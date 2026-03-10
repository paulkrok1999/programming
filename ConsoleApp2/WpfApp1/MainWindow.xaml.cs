using System;
using System.Collections.Generic;
using System.Data.SqlClient;
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
namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }



        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string conneString = $"Data Source = {nameserver.Text}; Initial Catalog={bz_name.Text} ";
            if (Login.Text != password.Text)
            {
                SqlConnection sql = new SqlConnection(conneString);
                sql.Open();
                Console.WriteLine("мы подключились");
                sql.Close();
            }
            else
            {
                Console.WriteLine("вы не можете войти");

            }
            
            
        }
    }
}
