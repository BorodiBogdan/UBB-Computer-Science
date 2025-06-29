using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        SqlConnection conn;
        SqlDataAdapter daDentalCabinet;
        SqlDataAdapter daDentist;
        DataSet dset;
        //BindingSource bsNeighbourHoods;
        //BindingSource bsSmartHomes;

        SqlCommandBuilder builder;

        string queryDentalCabinet;
        string queryDentist;

        public Form1()
        {
            InitializeComponent();
            fillData();
        }

        void fillData()
        {
            conn = new SqlConnection(getConnectionString());

            try
            {
                conn.Open();
            }
            catch (Exception excep)
            {
                Console.WriteLine(excep.ToString());
            }


            queryDentalCabinet = "SELECT * from DentalCabinet";
            queryDentist = "SELECT * FROM Dentist";

            daDentalCabinet = new SqlDataAdapter(queryDentalCabinet, conn);
            daDentist = new SqlDataAdapter(queryDentist, conn);

            builder = new SqlCommandBuilder(daDentalCabinet);
            SqlCommandBuilder cmdBuildersSmartHomes = new SqlCommandBuilder(daDentist);

            dset = new DataSet();

            daDentalCabinet.Fill(dset, "DentalCabinet");
            daDentist.Fill(dset, "Dentist");

            dset.Relations.Add("DentalDentist",
               dset.Tables["DentalCabinet"].Columns["DentalCabinetId"],
               dset.Tables["Dentist"].Columns["DentalCabinetId"] 
           );


            BindingSource bsParent = new BindingSource();
            bsParent.DataSource = dset.Tables["DentalCabinet"];
            BindingSource bsChild = new BindingSource(bsParent, "DentalDentist");
            this.dgvDentalCabinet.DataSource = bsParent;
            this.dgvDentists.DataSource = bsChild;

            /*
            this.dgvDentalCabinet.DataSource = dset.Tables["DentalCabinet"];

            this.dgvDentists.DataSource = this.dgvDentalCabinet.DataSource;
            this.dgvDentists.DataMember = "DentalDentist"; 
            */
        }
        string getConnectionString() {
            return "Data Source=DESKTOP-26CIK75\\SQLEXPRESS;" +
                  "Initial Catalog=Dental;Integrated Security=true;";
        }

        private void saveBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (dset.HasChanges())
                {
                    daDentalCabinet.Update(dset, "DentalCabinet");
                    daDentist.Update(dset, "Dentist");

                    dset.AcceptChanges();
                    MessageBox.Show("Updated");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error updating database: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
