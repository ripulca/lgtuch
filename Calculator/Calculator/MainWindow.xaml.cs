using System;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

        }

        private void CleanLast_Click(object sender, RoutedEventArgs e)
        {
            if (!String.IsNullOrEmpty(textBox.Text))
            {
                textBox.Text = textBox.Text.Substring(0, textBox.Text.Length - 1);
            }
        }
        private void Digit_Click(object sender, RoutedEventArgs e)
        {
            string value;
            string data = (string)((Button)e.OriginalSource).Content;
            if (data == "=")
            {
                try
                {
                    if (textBox.Text.Contains(".e+"))
                    {
                        textBox.Text.Replace(".e+", "*");
                        value = System.Math.Exp((double)textBox.Text.Last()).ToString();
                    }
                    value = new DataTable().Compute(textBox.Text, null).ToString();
                    textBox.Text = value;
                    return;
                }
                catch (Exception ex)
                {
                    return;
                }
            }
            else if (data == "CE")
            {
                textBox.Clear();
                return;
            }
            textBox.Text += data;
        }
        private void Exp_Click(object sender, RoutedEventArgs e)
        {
            textBox.Text += ".e+";
            return;
        }
        private void Plus_Minus_Click(object sender, RoutedEventArgs e)
        {
            if (textBox.Text.Last().Equals('*') || textBox.Text.Last().Equals('/') || textBox.Text.Last().Equals('(') || textBox.Text.Last().Equals(')') || textBox.Text.Last().Equals('+') || textBox.Text.Last().Equals('-') || textBox.Text.Last().Equals('.'))
            {
                return;
            }
            else if (textBox.Text.Last().Equals("*(-1)")) {
                textBox.Text.Replace("*(-1)", " ");
            }
            else {
                textBox.Text += "*(-1)";
            }
        }
        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {}
    }
}
