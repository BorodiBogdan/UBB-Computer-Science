using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Xml.Linq;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private SqlConnection conn;
        private SqlDataAdapter daMaster;
        private SqlDataAdapter daDetail;
        private DataSet dset;
        private SqlCommandBuilder cmdBuilderMaster;
        private SqlCommandBuilder cmdBuilderDetail;

        private ScenarioConfig scenario;
        private string relationName;

        public Form1()
        {
            InitializeComponent();

            try
            {
                // Load the current scenario configuration
                scenario = ConfigManager.GetCurrentScenario();
                
                

                // Update form title
                this.Text = scenario.DisplayName;

                // Set labels
                labelMaster.Text = scenario.MasterLabel;
                labelDetail.Text = scenario.DetailLabel;

                // Initialize data
                InitializeData();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error initializing form: {ex.Message}",
                    "Initialization Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void InitializeData()
        {
            try
            {
                conn = new SqlConnection(ConfigManager.GetConnectionString());

                // Create adapters using the queries from configuration
                daMaster = new SqlDataAdapter(scenario.MasterQuery, conn);
                daDetail = new SqlDataAdapter(scenario.DetailQuery, conn);

                // Create dataset and fill tables
                dset = new DataSet();
                daMaster.Fill(dset, scenario.MasterTableName);
                daDetail.Fill(dset, scenario.DetailTableName);

                // Create command builders for updates
                cmdBuilderMaster = new SqlCommandBuilder(daMaster);
                cmdBuilderDetail = new SqlCommandBuilder(daDetail);

                // Define relation name
                relationName = $"FK_{scenario.DetailTableName}_{scenario.MasterTableName}";

                // Create relation between master and detail tables
                dset.Relations.Add(relationName,
                    dset.Tables[scenario.MasterTableName].Columns[scenario.MasterIdColumn],
                    dset.Tables[scenario.DetailTableName].Columns[scenario.DetailForeignKeyColumn]);

                // Bind data to grid views
                dataGridViewMaster.DataSource = dset.Tables[scenario.MasterTableName];
                dataGridViewDetail.DataSource = dataGridViewMaster.DataSource;
                dataGridViewDetail.DataMember = relationName;

                // Configure grid views
                ConfigureDataGridViews();
            }
            catch (SqlException ex)
            {
                MessageBox.Show($"Database error: {ex.Message}\nError Code: {ex.Number}",
                    "Database Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error initializing data: {ex.Message}",
                    "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ConfigureDataGridViews()
        {
            // Configure master grid view
            dataGridViewMaster.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dataGridViewMaster.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridViewMaster.MultiSelect = false;
            dataGridViewMaster.AllowUserToAddRows = true;
            dataGridViewMaster.AllowUserToDeleteRows = true;

            // Configure detail grid view
            dataGridViewDetail.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dataGridViewDetail.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridViewDetail.MultiSelect = false;
            dataGridViewDetail.AllowUserToAddRows = true;
            dataGridViewDetail.AllowUserToDeleteRows = true;

            
        }

        private void RefreshData()
        {
            try
            {
                
                dset.Tables[scenario.DetailTableName].Clear();
                daDetail.Fill(dset, scenario.DetailTableName);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error refreshing data: {ex.Message}",
                    "Refresh Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                
                daMaster.Update(dset, scenario.MasterTableName);
                daDetail.Update(dset, scenario.DetailTableName);

                RefreshData();

                MessageBox.Show("Changes saved successfully!", "Success",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (SqlException ex)
            {
                string errorMessage = "Database error occurred:\n";
                switch (ex.Number)
                {
                    case 547: // Foreign key violation
                        errorMessage += "Cannot update/delete this record because it is referenced by other records.";
                        break;
                    case 2627: // Unique constraint violation
                        errorMessage += "A record with this key already exists.";
                        break;
                    case 515: // Cannot insert NULL
                        errorMessage += "Required fields cannot be empty.";
                        break;
                    default:
                        errorMessage += ex.Message;
                        break;
                }
                MessageBox.Show(errorMessage, "Database Error",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error saving changes: {ex.Message}",
                    "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                if (conn != null && conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error closing connection: {ex.Message}",
                    "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}