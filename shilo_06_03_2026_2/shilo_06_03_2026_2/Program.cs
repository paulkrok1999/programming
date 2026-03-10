class TestClass {
    static void Main() {
        Console.Write("Чтобы начать играть, выбери уровень:" +
            "\n1. легко (от 0 до 20)" +
            "\n2. средний (от 0 до 50)" +
            "\n3. сложный (от 0 до 100)" +
            "\nТвой выбор: ");

        string choice = Console.ReadLine();
        int MaxNum = 0;

        switch (choice)
        {
            case "1":
                MaxNum = 20;
                break;
            case "2":
                MaxNum = 50;
                break;
            case "3":
                MaxNum = 100;
                break;
            default:
                Console.WriteLine("Неверный выбор. Играем в легкий уровень.");
                MaxNum = 20;
                break;
        }

        Random random = new();
        int secret = random.Next(0, MaxNum + 1); // +1 чтобы включить maxNumber
        int pop = 0;
        bool isGuessed = false;

        Console.WriteLine($"\nЯ загадал число от 0 до {MaxNum}. Попробуй угадать!");

        while (!isGuessed) {
            Console.Write("Введи число: ");
            string input = Console.ReadLine();

            if (int.TryParse(input, out int guess)) {
                pop++;
                if (guess == secret) {
                    Console.WriteLine($"Поздравляю! Ты угадал число {secret} за {pop} попыток!");
                    isGuessed = true;
                }
                else if (guess < secret) {
                    Console.WriteLine("Загаданное число БОЛЬШЕ. Попробуй еще!");
                }
                else {
                    Console.WriteLine("Загаданное число МЕНЬШЕ. Попробуй еще!");
                }
            }
            else {
                Console.WriteLine("Пожалуйста, введи корректное число!");
            }
        }
    }
}