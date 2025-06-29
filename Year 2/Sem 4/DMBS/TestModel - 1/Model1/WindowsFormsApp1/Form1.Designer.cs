namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dgvDentalCabinet = new System.Windows.Forms.DataGridView();
            this.dgvDentists = new System.Windows.Forms.DataGridView();
            this.saveBtn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDentalCabinet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDentists)).BeginInit();
            this.SuspendLayout();
            // 
            // dgvDentalCabinet
            // 
            this.dgvDentalCabinet.AllowUserToOrderColumns = true;
            this.dgvDentalCabinet.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDentalCabinet.Location = new System.Drawing.Point(31, 50);
            this.dgvDentalCabinet.Name = "dgvDentalCabinet";
            this.dgvDentalCabinet.Size = new System.Drawing.Size(291, 211);
            this.dgvDentalCabinet.TabIndex = 0;
            // 
            // dgvDentists
            // 
            this.dgvDentists.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDentists.Location = new System.Drawing.Point(443, 50);
            this.dgvDentists.Name = "dgvDentists";
            this.dgvDentists.Size = new System.Drawing.Size(305, 211);
            this.dgvDentists.TabIndex = 1;
            // 
            // saveBtn
            // 
            this.saveBtn.Location = new System.Drawing.Point(336, 310);
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.Size = new System.Drawing.Size(98, 44);
            this.saveBtn.TabIndex = 2;
            this.saveBtn.Text = "Save";
            this.saveBtn.UseVisualStyleBackColor = true;
            this.saveBtn.Click += new System.EventHandler(this.saveBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.saveBtn);
            this.Controls.Add(this.dgvDentists);
            this.Controls.Add(this.dgvDentalCabinet);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dgvDentalCabinet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDentists)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvDentalCabinet;
        private System.Windows.Forms.DataGridView dgvDentists;
        private System.Windows.Forms.Button saveBtn;
    }
}

