#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
// Перечисление для цвета автомобиля
enum class Color {
    Black,
    White,
    Red,
    Blue,
    Silver,
    Green,
    Yellow,
    Unknown
};
enum class GearboxType {
    Automatic,
    Manual,
    Robot,
    CVT,
    Unknown
};
// Структура "Автомобиль"
struct Car {
    double length;         // Длина (в метрах)
    double clearance;      // Клиренс (в метрах)
    double engineVolume;   // Объем двигателя (в литрах)
    double enginePower;       // Мощность двигателя (в л.с.)
    double wheelDiameter;     // Диаметр колес (в дюймах)
    Color color;           // Цвет
    GearboxType gearbox;   // Тип коробки передач

    // Функция для ввода данных
    void input() {
        int gearboxInput;
        int colorInput;
        cout << "Введите параметры автомобиля:\n";
        cout << "Длина (м): ";
        cin >> length;
        cout << "Клиренс (м): ";
        cin >> clearance;
        cout << "Объем двигателя (л): ";
        cin >> engineVolume;
        cout << "Мощность: (в л.c): ";
        cin >> enginePower;
        cout << "Диаметр колес (дюймы): ";
        cin >> wheelDiameter;
        // Ввод коробки передач
        cout << "Коробка (0-Автомат, 1-Механика, 2-Робот, 3-Вариатор): ";
        cin >> gearboxInput;
        // Ввод цвета
        cout << "Цвет (0-Черный, 1-Белый, 2-Красный, 3-Синий, 4-Серебристый, 5-Зеленый, 6-Желтый): ";
        cin >> colorInput;
        gearbox = static_cast<GearboxType>(gearboxInput);
        color = static_cast<Color>(colorInput);
    }
    void display() const {
        const string colors[] = { "Черный", "Белый", "Красный", "Синий", "Серебристый", "Зеленый", "Желтый", "Неизвестный" };
        const string gearboxes[] = { "Автомат", "Механика", "Робот", "Вариатор", "Неизвестный" };
        cout << "\nПараметры автомобиля:\n"
            << "Длина: " << length << " м\n"
            << "Клиренс: " << clearance << " м\n"
            << "Объем двигателя: " << engineVolume << " л\n"
            << "Мощность: " << enginePower << " л.с.\n"
            << "Диаметр колес: " << wheelDiameter << " дюймов\n"
            << "Коробка: " << gearboxes[static_cast<int>(gearbox)] << "\n"
            << "Цвет: " << colors[static_cast<int>(color)] << "\n";
    }
    
};
// Функция поиска автомобилей по критериям
void findCars(const vector<Car>& cars) {
    int choice = 1;
    do {
        cout << "\nВыберите критерий поиска:\n"
            << "1 - По цвету\n"
            << "2 - По диапазону мощности\n"
            << "3 - По типу коробки\n"
            << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {

        case 1: {
            int colorInput;
            cout << "Введите цвет (0-6): ";
            cin >> colorInput;
            Color targetColor = static_cast<Color>(colorInput);
            for (const auto& car : cars) {
                if (car.color == targetColor) car.display();
            }
            break;
        }
        case 2: {
            int minPower, maxPower;
            cout << "Введите минимальную мощность: ";
            cin >> minPower;
            cout << "Введите максимальную мощность: ";
            cin >> maxPower;
            for (const auto& car : cars) {
                if (car.enginePower >= minPower && car.enginePower <= maxPower) car.display();
            }
            break;
        }
        case 3: {
            int gearboxInput;
            cout << "Введите тип коробки (0-3): ";
            cin >> gearboxInput;
            GearboxType targetGearbox = static_cast<GearboxType>(gearboxInput);
            for (const auto& car : cars) {
                if (car.gearbox == targetGearbox) car.display();
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
int main() {
    setlocale(LC_ALL, "");
    vector<Car> cars;
    int choice;

    do {
        cout << "\nМеню:\n"
            << "1 - Добавить автомобиль\n"
            << "2 - Показать все автомобили\n"
            << "3 - Поиск\n"
            << "0 - Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Car newCar;
            newCar.input();
            cars.push_back(newCar);
            break;
        }
        case 2: {
            for (const auto& car : cars) car.display();
            break;
        }
        case 3: {
            if (cars.empty()) {
                cout << "Список автомобилей пуст!\n";
                break;
            }
            findCars(cars);
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