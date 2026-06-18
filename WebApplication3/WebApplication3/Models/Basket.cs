namespace WebApplication3.Models
{
    public class Basket
    {
        public int Id { get; set; }
        public int UserId { get; set; }

        public List<daniels> products { get; set; }= new List<daniels>();
        public int Count { get { return products.Count; } }
        public double Price { get { return products.Sum(i => i.Prise); } }
        static int countid = 0;
        public Basket() { countid++;Id = countid; }
    }
}
