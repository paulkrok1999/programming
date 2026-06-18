namespace WebApplication3.Models
{
    public class BasketRepos
    {
        static private List<Basket> backids = new List<Basket>()
        {
            new Basket(),
            new Basket()
        };
        public static Basket GetBackid(int id)
        {
            return backids[id];
        }
    }
}
