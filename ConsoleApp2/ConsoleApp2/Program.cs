using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {

            try
            {
                string conneString = @"Data Source=(localdb)\MSSQLLocalDB; 
                     Initial Catalog=apact; 
                     Integrated Security=SSPI;";
                SqlConnection sql = new SqlConnection(conneString);
                sql.Open();
                Console.WriteLine("мы подключились");
                sql.Close();
            }
            catch (Exception ex) {
                Console.WriteLine("вы не подключились"+ex);
            }
        }

    }
}
