using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApplication1.Controllers
{
    public class bv411 : Controller
    {
        public string Vania()
        {
            return "Ваня молодец!";
        }
        public int Age()
        {
            return 17;
        }
        public int Math(int a)
        {
            return a;
        }
        public IActionResult Hello1()
        {
            DateTime dateTime = DateTime.Now;
            int has = dateTime.Hour;
            string mess;
            /*
             ющим образом:
                Ночь - 0:00 до 05:59
                Утро - 06:00 до 11:59
                День - 12:00 до 17:59
                Вечер - 18:00 до 23:59

             */
            if (has >= 0 || has <= 5)
            {

                mess = "Доброй ночи";
            }
            else if (has >= 6 && has <= 11)
            {
                mess = "Доброе утро";
            }
            else if (has >= 12 && has <= 17)
            {
                mess = "Добрый день";
            }
            else // hour >= 18 && hour <= 23
            {
                mess = "Добрый вечер";
            }

            // Возвращаем строку с приветствием
            return Content(mess);
        }
        public int Math2(int a, int b)
        {
            int result = a + b;
            return result;
        }
        public string Mathl(double a = 0, double b = 0, string operation = "+")
        {
            double result;

            if (operation == "+")
            {
                result = a + b;
            }
            else if (operation == "-")
            {
                result = a - b;
            }
            else if (operation == "*")
            {
                result = a * b;
            }
            else if (operation == "/")
            {
                if (b != 0)
                    result = a / b;
                else
                    return "ошибка делить на 0 нельзя";
            }
            else
            {
                return "\r\nОшибка: Недопустимая операция";
            }

            return $"{a} {operation} {b} = {result}";
        }
    }

}
