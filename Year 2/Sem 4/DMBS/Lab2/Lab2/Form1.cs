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

namespace Lab2
{
    public partial class Form1 : Form
    {
        SqlConnection conn;
        SqlDataAdapter daWorkers;
        DataSet dset;
        BindingSource bsWorkers;

        SqlCommandBuilder builder;

        string queryWorkers;

        public Form1()
        {
            InitializeComponent();
            fillData();
        }

        void fillData()
        {
            conn = new SqlConnection();
            queryWorkers = "Select * from Workers";

            daWorkers = new SqlDataAdapter(queryWorkers, conn);

            builder = new SqlCommandBuilder(daWorkers);

            dset = new DataSet();

            daWorkers.Fill(dset, "Worker");

            dset.Relations.Add("Workers", dset.Tables["Worker"].Columns["worker_id"],
               dset.Tables["Worker"].Columns["worker_id"]);
            
            this.dataGridViewWorkers.DataSource = dset.Tables["Worker"];
        }

        string getConnectionString()
        {
            return "Data Source=DESKTOP-26CIK75\\SQLEXPRESS;" +
                   "Initial Catalog=Practice;Integrated Security=true;";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
