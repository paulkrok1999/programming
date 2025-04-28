#include <iostream>
#include <vector>
#include <string>
#include <limits>
#define NOMINMAX
#include <Windows.h>
#include <locale.h>
using namespace std;
// Структура "Фильма"
struct VideoMagazin {
    string title;//Название фильма;
    string director;//Режиссер;
    string genre; //Жанр
    double popularityRating;//рейтинг популярности
    double price;//цена диска
    // Функция для ввода данных
    void input() {
        cout << "Параметры фильма:\n";
        cout << "Название фильма\n: ";
        cin >> title;
        cout << "режисер: \n";
        cin >> director;
        cout << "Жанр: \n";
        cin >> genre;
        cout << "Введите рейтинг популярности: ";
        while (!(cin >> popularityRating)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите число: ";
        }
        cin.ignore();        cout << "Цена диска: \n";
        cin >> price;
    }
    void display() const {
        cout << "\nПараметры фильма:\n"
            << "\nНазвание фильма:" << title
            << "\nРежисер: " << director
            << "\nжанр: " << genre
            << "\nрейтинг: " << popularityRating
            << "\nцена: " << price;
    }
};
// Функция поиска автомобилей по критериям
void findVideos(const vector<VideoMagazin>& videos) {
    int choice = 1;
    do {
        cout << "\nВыберите критерий поиска:\n"
            << "1 - По название\n"
            << "2 - По жанру\n"
            << "3 - По режиссеру\n"
            << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {

        case 1: {
            string param;
            cout << "Введите название: ";
            cin >> param;
            for (const auto& video : videos) {
                if (video.title == param ) video.display();
            }
            break;
        }
        case 2: {
            string param;
            cout << "Введите жанр: ";
            cin >> param;
            for (const auto& video : videos) {
                if (video.genre == param) video.display();
            }
            break;
        }
        case 3: {
            string param;
            cout << "Введите фамилию режиссера: ";
            cin >> param;
            for (const auto& video : videos) {
                if (video.director == param) video.display();
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Неверный выбор!\n";
        };
    } while (choice != 0);
}
void mostPopularInGenre(const vector<VideoMagazin>& videos) {
    string genre;
    //cout << "Введите жанр: ";
    //getline(cin, genre);

    double maxRating = -1;
    VideoMagazin mostPopular;
    bool found = false;

    for (const auto& video : videos) {
        if ( video.popularityRating > maxRating) {
            maxRating = video.popularityRating;
            mostPopular = video;
            found = true;
        }
    }

    if (found) {

        cout << "Название: " << mostPopular.title << endl;
        cout << "Режиссер: " << mostPopular.director << endl;
        cout << "Жанр: " << mostPopular.genre << endl;
        cout << "Рейтинг: " << mostPopular.popularityRating << endl;
        cout << "Цена: " << mostPopular.price << " руб." << endl;
        cout << "-------------------\n";
    }
    else {
        cout << "Фильмы в жанре '" << genre << "' не найдены.\n";
    }
}
int main() {

    // Настройки для русской локализации
    SetConsoleCP(1251);          // Устанавливаем кодировку ввода CP1251
    SetConsoleOutputCP(1251);    // Устанавливаем кодировку вывода CP1251
    setlocale(LC_ALL, "Rus");    // Локализация для функций стандартной библиотеки
    vector<VideoMagazin> videos;
    int choice;
    do {
        cout << "\nМеню:\n"
            << "1 - Добавить фильм\n"
            << "2 - Показать все фильмы\n"
            << "3 - Поиск\n"
            << "4-самый популярный\n"
            << "0 - Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            VideoMagazin newvideo;
            newvideo.input();
            videos.push_back(newvideo);
            cout << "Фильм успешно добавлен!\n";
            break;
        }
        case 2: {
            for (const auto& vid : videos) vid.display();
            break;
        }
        case 3: {
            if (videos.empty()) {
                cout << "Список фильма пуст!\n";
                break;
            }
            findVideos(videos);
            break;
        }
        case 4: {
            if (videos.empty()) {
                cout << "Список фильма пуст!\n";
                break;
            }
            mostPopularInGenre(videos);
            break;
        }
        case 0:
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}
