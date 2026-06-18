using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    public class Backid
    {
        public int Id {  get; set; }
        public int UserId {  get; set; }
        public User User { get; set; }
        public List<Product> products { get; set; }
        public int Count{get{return products.Count;}}
        public double Price { get { return products.Sum(i => i.Prise); } }
        static int countid = 0;
        public Baskid() { countid++; countid; }
    }
}
