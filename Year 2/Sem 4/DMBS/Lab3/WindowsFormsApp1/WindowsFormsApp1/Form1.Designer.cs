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
            this.dataGridViewMaster = new System.Windows.Forms.DataGridView();
            this.dataGridViewDetail = new System.Windows.Forms.DataGridView();
            this.buttonSave = new System.Windows.Forms.Button();
            this.labelMaster = new System.Windows.Forms.Label();
            this.labelDetail = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewMaster)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDetail)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewMaster
            // 
            this.dataGridViewMaster.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewMaster.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewMaster.Location = new System.Drawing.Point(12, 25);
            this.dataGridViewMaster.Name = "dataGridViewMaster";
            this.dataGridViewMaster.RowHeadersWidth = 82;
            this.dataGridViewMaster.Size = new System.Drawing.Size(776, 200);
            this.dataGridViewMaster.TabIndex = 0;
            // 
            // dataGridViewDetail
            // 
            this.dataGridViewDetail.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewDetail.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewDetail.Location = new System.Drawing.Point(12, 250);
            this.dataGridViewDetail.Name = "dataGridViewDetail";
            this.dataGridViewDetail.RowHeadersWidth = 82;
            this.dataGridViewDetail.Size = new System.Drawing.Size(776, 200);
            this.dataGridViewDetail.TabIndex = 1;
            // 
            // buttonSave
            // 
            this.buttonSave.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.buttonSave.Location = new System.Drawing.Point(354, 470);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(100, 30);
            this.buttonSave.TabIndex = 2;
            this.buttonSave.Text = "Save Changes";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // labelMaster
            // 
            this.labelMaster.AutoSize = true;
            this.labelMaster.Location = new System.Drawing.Point(12, 9);
            this.labelMaster.Name = "labelMaster";
            this.labelMaster.Size = new System.Drawing.Size(45, 13);
            this.labelMaster.TabIndex = 3;
            this.labelMaster.Text = "Master";
            // 
            // labelDetail
            // 
            this.labelDetail.AutoSize = true;
            this.labelDetail.Location = new System.Drawing.Point(12, 234);
            this.labelDetail.Name = "labelDetail";
            this.labelDetail.Size = new System.Drawing.Size(45, 13);
            this.labelDetail.TabIndex = 4;
            this.labelDetail.Text = "Detail";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 512);
            this.Controls.Add(this.labelDetail);
            this.Controls.Add(this.labelMaster);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.dataGridViewDetail);
            this.Controls.Add(this.dataGridViewMaster);
            this.MinimumSize = new System.Drawing.Size(816, 551);
            this.Name = "Form1";
            this.Text = "Dynamic Master-Detail Form";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewMaster)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDetail)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewMaster;
        private System.Windows.Forms.DataGridView dataGridViewDetail;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Label labelMaster;
        private System.Windows.Forms.Label labelDetail;
    }
}