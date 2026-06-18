using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    public class Order
    {
        public int Id { get; set; }
        public int UserId { get; set; }
        public User User { get; set; }
        public Status Status { get; set; }
        public DateTime date { get; set; }
        public List<Product> products { get; set; }
        public string StatusId {  get; set; }
    }
}
