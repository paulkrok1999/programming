#include <iostream>
using namespace std;
long fact(long n) {
    if ((n == 0) || (n == 1)) {
        return 1;
    }
    return  n * fact (n - 1);
}
int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите n: ";
    cin >> n;
    cout << "Результат: ";
    cout << fact(n) << '\n';
    cout << endl; // Перевод строки
    return 0;
}