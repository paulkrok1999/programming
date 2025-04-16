#include <iostream>
using namespace std;
void printStars(int n) {
    if (n <= 0) { // условия разрыва рекирсии как только n = 0 завершение рекурсии
        return;
    }
    cout << '*';      // Печать звезды
    printStars(n - 1); // Рекурсивный вызов самого себя но на 1 меньше
}
int main() {
    setlocale(LC_ALL, "");
    int N;
    cout << "Введите N: ";
    cin >> N;

    cout << "Результат: ";
    printStars(N);
    cout << endl; // Перевод строки

    return 0;
}