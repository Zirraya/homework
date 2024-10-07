using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace _6_Nikitenko_211
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.Click += new EventHandler(button1_Click);
        }
        private void button1_Click(object sender, EventArgs e)
        {  // Получение исходных данных из TextBox
            double x = Convert.ToDouble(textBox1.Text);
            double y = Convert.ToDouble(textBox2.Text);
            double z = Convert.ToDouble(textBox3.Text);
            // Ввод исходных данных в окно результатов
            richTextBox1.Text = "Результаты работы программы ст. Никитенко Я.В. " + Environment.NewLine;
            richTextBox1.Text += "При X = " + textBox1.Text + Environment.NewLine;
            richTextBox1.Text += "При Y = " + textBox2.Text + Environment.NewLine;
            richTextBox1.Text += "При Z = " + textBox3.Text + Environment.NewLine;
            // Определение номера выбранной функции
            int n = 0;
            if (radioButton2.Checked) n = 1;
            else if (radioButton3.Checked) n = 2;
            // Вычисление U
            double u;
            switch (n)
            {
                case 0:
                    if ((z - x) == 0) u = y * Math.Sin(x) * Math.Sin(x) + z;
                    else if ((z - x) < 0) u = y * Math.Exp(Math.Sin(x)) - z;
                    else u = y * Math.Sin(Math.Sin(x)) + z;
                    richTextBox1.Text += "U = " + Convert.ToString(u) + Environment.NewLine;
                    break;
                case 1:
                    if ((z - x) == 0) u = y * Math.Cos(x) * Math.Cos(x) + z;
                    else if ((z - x) < 0) u = y * Math.Exp(Math.Cos(x)) - z;
                    else u = y * Math.Sin(Math.Cos(x)) + z;
                    richTextBox1.Text += "U = " + Convert.ToString(u) + Environment.NewLine;
                    break;
                case 2:
                    if ((z - x) == 0) u = y * Math.Exp(x) * Math.Exp(x) + z;
                    else if ((z - x) < 0) u = y * Math.Exp(Math.Exp(x)) - z;
                    else u = y * Math.Sin(Math.Exp(x)) + z;
                    richTextBox1.Text += "U = " + Convert.ToString(u) + Environment.NewLine;
                    break;
                default:
                    richTextBox1.Text += "Решение не найдено" + Environment.NewLine;
                    break;
            }

        }
    }
}

