using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4_Nikitenko_211
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Load += new System.EventHandler(this.Form1_Load);
        }
         
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "4e3";  // Начальное значение X
            textBox2.Text = "-0,875"; // Начальное значение Y
            textBox3.Text = "-4,75e-4"; // Начальное значение Z
            // Вывод строки в многострочный редактор
            richTextBox1.Text = "Лаб. раб. N1. Ст. гр. 211 Никитенко Я.В";
        }
         
        private void button1_Click(object sender, EventArgs e)
        {
           
            double x = double.Parse(textBox1.Text); // Считывание значения X
            richTextBox1.Text += Environment.NewLine + 
                "X = " + x.ToString(); // Вывод значения X в окно


            // Считывание значения Y
            double y = double.Parse(textBox2.Text); // Считывание значения Y
            richTextBox1.Text += Environment.NewLine +
                "Y = " + y.ToString(); // Вывод значения Y в окно


          
            double z = double.Parse(textBox3.Text); // Считывание значения Z
            richTextBox1.Text += Environment.NewLine +
                "Z = " + z.ToString(); // Вывод значения Z в окно


            // Вычисляем арифметическое выражение
            double a = Math.Pow(Math.Abs(Math.Cos(x)-Math.Cos(y)),(1 + 2*(Math.Sin(y)* Math.Sin(y))));
            double b = 1+z+((z * z)/2)+ ((z * z * z) / 3)+((z * z * z * z) / 4);
           
            double w = a * b;
          
            richTextBox1.Text += Environment.NewLine +
                "Результат W = " + w.ToString();   // Выводим результат в окно
        }

    }
 
}
