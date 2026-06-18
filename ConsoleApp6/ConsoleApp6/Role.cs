using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    public class Role
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public List<User> users { get; set; } 
    }
}
