using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4_1zadanie__Nikitenko_211
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void hide_Click(object sender, EventArgs e)
        {
            textBox1.Hide();
        }

        private void show_Click(object sender, EventArgs e)
        {
            textBox1.Show();
        }

        private void clear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();

        }
    }
}
