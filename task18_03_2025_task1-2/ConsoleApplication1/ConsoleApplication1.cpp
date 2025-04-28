#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <fstream>
#include <vector>
#include <locale.h>
#include <Windows.h>

using namespace std;
void print_error(errno_t err) {
    std::cout << "The file cannot be opened " << "\n";

    switch (err)
    {
    case 2:
        std::cout << "Отсутствует такой файл или каталог. " << "\n";
        break;
    case 13:
        std::cout << "в разрешении отказано.  " << "\n";
        break;
    default:
        std::cout << "Ошибка неизвестна!  " << "\n";
        break;
    }
}

void write_file(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "w");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    for (int i = 0; i < 5; i++) {
        char str[255]{};
        std::cout << "Enter string :";
        std::cin.getline(str, 255);
        fputs(str, in_file);
        fputs("\n", in_file);
    }

    fclose(in_file);
}

void write_file2(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "w");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    char str[255]{};
    cout << "Enter name :";
    cin.getline(str, 255);
    char str2[255]{};
    std::cout << "Enter surname :";
    std::cin.getline(str2, 255);
    int age;
    std::cout << "Enter age :";
    std::cin >> age;

    fprintf_s(in_file, "%s %s %d", str, str2, age);


    fclose(in_file);
}

void read_file2(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "r");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    while (!feof(in_file)) {
        char str[255]{};
        char str2[255]{};
        int age;

        fscanf_s(in_file, "%s %s %d", str, 255, str2, 255, &age);
        //cout << "Name = " << str << endl;
        //cout << "Surname = " << str2 << endl;
        //cout << "Age = " << age << endl;

        printf("My name is %s, my surname is %s, my age = %d \n", str, str2, age);

    }
    fclose(in_file);
}

void read_file(const char* path) {
    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "r+");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    while (!feof(in_file)) {
        char str[255]{};
        fgets(str, 255, in_file);
        std::cout << str;
    }
    fclose(in_file);
}
// Функция для задания 1: Подсчет слов, начинающихся с заданного символа
void count_words_starting_with( const char* filename) {
    int count = 0;
    ifstream file(filename);
    string myword;
    char target;
    cout << "Введите буку";
    cin >> target;
    target = tolower(target);
    cout << target << "\n";
    // Читаем слова из файла
    while (file >> myword) {
        if (!myword.empty()) {
            // Преобразуем первый символ слова в нижний регистр
            char first_char = tolower(static_cast<unsigned char>(myword[0]));
            if (first_char == target) {
                count++;
                //cout << "Найдено слово: " << myword << endl;
            }
        }
    }
    cout << "Количество слов, начинающихся с '" << target << "': " << count << endl;
    file.close();
}


// Функция для задания 1: Подсчет слов, начинающихся с заданного символа
void write_words(const char* filename, const char* filename2) {
    int count = 0;
    string myword;
    ifstream file(filename);
    ofstream out(filename2);
    // Читаем слова из файла
    while (file >> myword) {
        //filter myword
        string cleaned = myword;
        //cout << cleaned << "\n";
        //условие филтрованного слова на длину
        if (cleaned.length() >= 7){
            out << cleaned << "\n";
            //cout << cleaned << "\n";

        }
    }
    file.close();
    out.close();

}
int main() {
    SetConsoleCP(1251);          // Устанавливаем кодировку ввода CP1251
    SetConsoleOutputCP(1251);    // Устанавливаем кодировку вывода CP1251
    setlocale(LC_ALL, "Rus");    // Локализация для функций стандартной библиотеки
    const char* path = "C:\\Users\\USER\\programming\\task18_03_2025_task1-2\\test.txt";
    const char* path2 = "C:\\temp\\test2.txt";
    count_words_starting_with(path);//Задание 1.
    write_words(path, path2);//задание2

    //write_file(path);
    //read_file(path);
    //
    //write_file2(path);
  /*  read_file2(path);*/
}

/*
Задание 1. Дан текстовый файл. Подсчитать количество
слов, начинающихся с символа, который задаёт пользо-
ватель.
Задание 2. Дан текстовый файл. Необходимо создать
новый файл, в который переписать из исходного файла
все слова, состоящие не менее чем из семи букв.

*/
