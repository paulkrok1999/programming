#include <iostream>
#include <stdio.h>
#include <string>

int write_file(const char* path, const char* message) {
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

int main()
{
    /*// Создаем буфер для сообщения
    char text[255];
    // Создаем буфер для пути к файлу
    char path[255];
    std::cout << "Input path to file:\n";
    // Получаем путь до файла из консоли
    std::cin.getline(path, 255);
    // Создаем константную строку с указанием пути до файла, для передачи в функцию
    const char* fpath = path;
    std::cout << "Input message:\n";
    // Получаем сообщение из консоли
    std::cin.getline(text, 255);
    // Создаем константную строку с сообщением, для передачи в функцию
    const char* ftext = text;*/

    std::string path, text;
    std::cout << "Input path to file:\n";
    std::getline(std::cin, path);
    std::cout << "Input message:\n";
    std::getline(std::cin, text);

    const char* fpath = path.c_str();
    const char* ftext = text.c_str();

    int e = write_file(fpath, ftext);
    if (e != 0) {
        std::cerr << "Error at write_file function: " << e << "\n";
    }
}