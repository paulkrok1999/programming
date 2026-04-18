using System;
namespace Gi {
    class Program {
        
        static void Main() {
            
            //задание 1

            //while (true)
            //{
            //    Console.Write("Введите число от 1 до 100");
            //    string message = Console.ReadLine();
            //    int namber = int.Parse(message);
            //    if (namber >= 1 && namber <= 100)
            //    {
            //        bool nams = namber % 3 == 0;//fiss
            //        bool nams1 = namber % 5 == 0;//buss
            //        if (nams && nams1) { Console.WriteLine("fiss and buss"); }
            //        else if (nams) { Console.WriteLine("fiss"); }
            //        else if (nams1) { Console.WriteLine("buss"); }
            //        else { Console.WriteLine(namber); }
            //    }
            //    else { Console.WriteLine("число в не дипизионе"); }
            //}

            //Задание 2

            //Console.Write("введите значение: ");
            //double a= Convert.ToDouble(Console.ReadLine());
            //Console.Write("введите процент: ");
            //double b= Convert.ToDouble(Console.ReadLine());
            //double rez = a * (b / 100);
            //Console.WriteLine(rez);

            //Задание 3

            Console.Write("введите 1 цифру: ");
            string odin=Console.ReadLine();
            Console.Write("введите 2 цифру: ");
            string dva = Console.ReadLine();
            Console.Write("введите 3 цифру: ");
            string tri = Console.ReadLine();
            Console.Write("введите 4 цифру: ");
            string shi = Console.ReadLine();
            int namber = int.Parse(odin);
            int namber2 = int.Parse(dva);
            int namber3 = int.Parse(tri);
            int namber4 = int.Parse(shi);

            int res= (namber*1000)+(namber2*100)+(namber3*10)+(namber4*1);
            Console.WriteLine(res);

        }
    }
}