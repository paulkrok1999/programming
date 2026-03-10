#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#endif

struct read_t {
    int err;
    std::string text;
};

int write(const char* path, const char* message) {
    std::ofstream file(path);
    if (!file.is_open()) {
        return errno;
    }
    file << message << "\n";
    if (file.fail()) {
        return errno;
    }
    return 0;
}

read_t read(const char* path) {
    read_t r;
    std::ifstream file(path);
    if (!file.is_open()) {
        r.err = errno;
        r.text = "";
        return r;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    r.text = buffer.str();
    r.err = 0;
    return r;
}

int loop() {
    while (true) {
        std::cout << "Введите команду: \n";
        std::string com;
        if (!std::getline(std::cin, com)) {
            break; // Выход при EOF
        }
        if (com.empty()) {
            std::cout << "Команда не может быть пустой.\n";
            continue;
        }
        if (com == "exit") {
            return 0;
        }
        else if (com == "read") {
            std::string path;
            std::cout << "Введите путь до файла: \n";
            if (!std::getline(std::cin, path)) {
                break;
            }
            if (path.empty()) {
                std::cout << "Путь не может быть пустым.\n";
                continue;
            }
            read_t r = read(path.c_str());
            if (r.err != 0) {
                std::cout << "Чтение файла '" << path << "' завершилось с ошибкой: " << std::strerror(r.err) << "\n";
            }
            else {
                std::cout << "Файл успешно прочитан.\n" << r.text << "\n";
            }
        }
        else if (com == "write") {
            std::string path;
            std::cout << "Введите путь до файла: \n";
            if (!std::getline(std::cin, path)) {
                break;
            }
            if (path.empty()) {
                std::cout << "Путь не может быть пустым.\n";
                continue;
            }
            std::string message;
            std::cout << "Введите текст для записи: \n";
            if (!std::getline(std::cin, message)) {
                break;
            }
            int r = write(path.c_str(), message.c_str());
            if (r != 0) {
                std::cout << "Запись в файл '" << path << "' завершилась с ошибкой: " << std::strerror(r) << "\n";
            }
            else {
                std::cout << "Файл успешно записан.\n";
            }
        }
        else if (com == "remove") {
            std::string path;
            std::cout << "Введите путь до файла: \n";
            if (!std::getline(std::cin, path)) {
                break;
            }
            if (path.empty()) {
                std::cout << "Путь не может быть пустым.\n";
                continue;
            }
            int r = std::remove(path.c_str());
            if (r != 0) {
                std::cout << "Удаление файла '" << path << "' завершилось с ошибкой: " << std::strerror(errno) << "\n";
            }
            else {
                std::cout << "Файл успешно удален.\n";
            }
        }
        else {
            std::cout << "Неизвестная команда.\n";
        }
    }
    return 0;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    return loop();
}