using System;
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
using System.Windows.Shapes;

namespace kur2k
{
    /// <summary>
    /// Логика взаимодействия для TextInputWindow.xaml
    /// </summary>
    public partial class TextInputWindow : Window
    {
        public TextInputWindow()
        {
            InitializeComponent();
        }
        public string getName
        {
            get{ return ShopName.Text; }
        }
        public string getX
        {
            get { return X.Text; }
        }
        public string getY
        {
            get { return Y.Text; }
        }

        private void Accept_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = false;
        }

        private void ShopName_TextChanged(object sender, TextChangedEventArgs e)
        {
            
        }

        private void X_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Y_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
