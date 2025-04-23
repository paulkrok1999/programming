#include <iostream>
using namespace std;

struct Decimal {
    int num;    // Целая часть
    int tail;   // Десятичная часть (должна быть 0-99)

    // Конструктор по умолчанию
    Decimal() : num(0), tail(0) {}

    // Конструктор с параметрами
    Decimal(int n, int t) : num(n), tail(t) {
        normalize();
    }

    // Метод для вывода информации
    void print() {
        cout << "num: " << num << ", tail: " << tail << "\n";
    }

    void sum(int e_num, int e_tail) {
        num = num + e_num;
        tail = tail + e_tail;
        normalize();
    }

private:
    // Нормализация десятичной части
    void normalize() {
        if (tail >= 100) {
            num += tail / 100;
            tail %= 100;
        }
        // Для обработки отрицательных значений
        else if (tail < 0) {
            num -= 1;
            tail += 100;
        }
    }
};
int main() {
	setlocale(LC_ALL, "");
    Decimal d(5, 75);
    d.print();
    d.sum(2, 30);
    d.print();  // Вывод: num: 7, tail: 105 -> после нормализации: 8, 05
}