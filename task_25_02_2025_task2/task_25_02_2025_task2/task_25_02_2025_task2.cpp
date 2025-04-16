#include <iostream>
using namespace std;
int printsum(int a, int b) {
    if (a > b) {
        return printsum(b, a);
    }
    if (a == b) {
        return a;
    }
    return a+ printsum(a + 1, b);
}
int main() {
    setlocale(LC_ALL, "");
    int a;
    int b;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Результат: ";
    cout << printsum(a, b) << '\n';
    
    cout << endl; // Перевод строки
    return 0;
}