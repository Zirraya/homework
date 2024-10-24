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

namespace _6_Nikitenko_211 // На самом деле это 4 вариант, а не 6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.Click += new EventHandler(button1_Click);
            button2.Click += new EventHandler(button2_Click);
           
        }
        private void button1_Click(object sender, EventArgs e)
        {  // Получение исходных данных из TextBox
            double x = Convert.ToDouble(textBox1.Text);
            double y = Convert.ToDouble(textBox2.Text);

            // Ввод исходных данных в окно результатов
            richTextBox1.Text = "Результаты работы программы ст. Никитенко Я.В. " + Environment.NewLine;
            richTextBox1.Text += "При X = " + textBox1.Text + Environment.NewLine;
            richTextBox1.Text += "При Y = " + textBox2.Text + Environment.NewLine;

            // Определение номера выбранной функции
            int n = 0;
            if (radioButton2.Checked) n = 1;
            else if (radioButton3.Checked) n = 2;
            // Вычисление D
            double d=0;
           
            
            switch (n)
            {
                case 0:
                    if (x>y) d = Math.Pow(Math.Sinh(x)-y,3)+Math.Atan(x);
                    else if (y>x) d = Math.Pow(y-Math.Sinh(x), 3) + Math.Atan(x);
                    else if (y==x) d = Math.Pow(y + Math.Sinh(x), 3) + 0.5; 
                    richTextBox1.Text += "D = " + Convert.ToString(d) + Environment.NewLine;
                    break;
                case 1:
                    if (x > y) d = Math.Pow((x*x) - y, 3) + Math.Atan(x);
                    else if (y > x) d = Math.Pow(y -(x* x), 3) + Math.Atan(x);
                    else if (y == x) d = Math.Pow(y + (x*x), 3) + 0.5;
                    richTextBox1.Text += "D = " + Convert.ToString(d) + Environment.NewLine;
                    break;
                case 2:
                    if (x > y) d = Math.Pow(Math.Exp(x) - y, 3) + Math.Atan(x);
                    else if (y > x) d = Math.Pow(y - Math.Exp(x), 3) + Math.Atan(x);
                    else if (y == x) d = Math.Pow(y + Math.Exp(x), 3) + 0.5;
                    richTextBox1.Text += "D = " + Convert.ToString(d) + Environment.NewLine;
                    break;
                default:
                    richTextBox1.Text += "Решение не найдено" + Environment.NewLine;
                    break;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();

        }

      
    }
              
}

