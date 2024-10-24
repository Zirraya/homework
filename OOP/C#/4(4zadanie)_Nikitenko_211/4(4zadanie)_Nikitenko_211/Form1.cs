using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4_4zadanie__Nikitenko_211
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Считывание начальных данных
            double x0 = Convert.ToDouble(textBox1.Text);
            double xk = Convert.ToDouble(textBox2.Text);
            double dx = Convert.ToDouble(textBox3.Text);
            Cal(x0, xk, dx);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            double x0 = Convert.ToDouble(textBox1.Text);
            double xk = Convert.ToDouble(textBox2.Text);
            double dx = Convert.ToDouble(textBox3.Text);
            dx= dx / 2;
            Cal(x0,xk,dx);


        }




        // Оно где-то внизу чтоб глаза не мозолила (функция для вычисления и загрузки)

        // Функия для вычисления
        private void Cal(double x0, double xk, double dx)
        {
            const double a = 1.35;
            textBox4.Text = a.ToString();

            const double b = -6.25;
            textBox6.Text = b.ToString();

            textBox5.Text = "Работу выполнила ст. Никитенко Я.В" + Environment.NewLine;


            // Цикл для табулирования функции
            double x = x0;
            while (x <= (xk + dx / 2))
            {
                double y = Math.Pow(a * b, 2) + Math.Pow(Math.Cos(x * x * x - b), 2);
                textBox5.Text += "x=" + Convert.ToString(x) +
                                 "; y=" + Convert.ToString(y) + Environment.NewLine;
                x = x + dx;

            }
        }
        //

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "5,3";
            textBox2.Text = "10,3";
            textBox3.Text = "0,25";
            textBox4.Text = "1,35";
            textBox6.Text = "-6,25";

        }
    }
 }


