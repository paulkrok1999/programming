using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    public class BaskidRepos
    {
        static private List<Backid> backids = new List<Backid>()
        {
            new Backid(),
            new Backid()
        };
        public static Backid GetBackid(int id)
        {
            return backids[id];
        }

    }
}
