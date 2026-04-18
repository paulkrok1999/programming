#include <iostream>
#include <stdio.h>
#include <string>

/*
    1. read_t - структура для хранения информации о выполнении функции read. Содержит в себе два поля:
        err - целочисленное поле для хранения кода ошибки
        text - поле типа string для хранения текста из файла

    2. typedef struct read_t read_t - объявление структуры read_t как глобальный тип данных в программе

    3. write - функция записи данных (в формате текста) в указанный файл. Возвращает код выполнения функции:
        0 - успешное выполнение
        !0 - ошибка выполнения

    4. read - функция чтения данных из файла. Возвращает структуру read_t, где
        err - код ошибки, если функция выполнилась с ошибкой
        text - текст файла, если функция выполнилась успешно

    5. loop - основной цикл выполнения программы, ожидающая на вход команды из консоли. Возвращает код
            выполнения в качестве результата.

    6. main - точка входа в программу. Вызывает метод loop() и завершается, при завершении выполнения loop()
*/

struct read_t {
    int err;
    std::string text;
};

typedef struct read_t read_t;

int write(const char* path, const char* message) {
    FILE* file{ nullptr };
    errno_t e = fopen_s(&file, path, "w");
    if (e != 0) {
        return e;
    }
    fputs(message, file);
    fputs("\n", file);
    fclose(file);
    return 0;
}

read_t read(const char* path) {
    read_t r;
    FILE* file{ nullptr };
    errno_t e = fopen_s(&file, path, "r");
    if (e != 0) {
        r.err = e;
        r.text = "";
        return r;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != nullptr) {
        r.text += buffer;
    }
    fclose(file);
    r.err = 0;
    return r;
}

int loop() {
    while (true) {
        std::cout << "Введите команду: \n";
        std::string com;
        std::getline(std::cin, com);
        if (com == "exit") {
            return 0;
        }
        else if (com == "read") {
            read_t r;
            std::string path;
            std::cout << "Введите путь до файла: \n";
            std::getline(std::cin, path);
            r = read(path.c_str()); // c_str() преобразует string -> const char*
            if (r.err != 0) {
                std::cout << "Чтение файла завершилось с ошибкой: " << r.err << "\n";
            }
            else {
                std::cout << "Файл успешно прочитан.\n" << r.text << "\n";
            }
        }
        else if (com == "write") {
            int r;
            std::string path;
            std::cout << "Введите путь до файла: \n";
            std::getline(std::cin, path);
            std::string message;
            std::cout << "Введите текст для записи: \n";
            std::getline(std::cin, message);
            r = write(path.c_str(), message.c_str());
            if (r != 0) {
                std::cout << "Запись в файл завершилась с ошибкой: " << r << "\n";
            }
            else {
                std::cout << "Файл успешно записан.\n";
            }
        }
        else if (com == "remove") {
            int r;
            std::string path;
            std::cout << "Введите путь до файла: \n";
            std::getline(std::cin, path);



                if (remove(path.c_str()) != 0)
                    perror("Error deleting file");
                else
                    puts("File successfully deleted");

            
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    loop();
}