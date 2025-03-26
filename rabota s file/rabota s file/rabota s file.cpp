#include <iostream>
using namespace std;

template <typename T>
void printArray(const int n, T  arr);

template <typename T>
void printArray(const int n, T  arr) {
        for (int i = 0; i < n; i++) {

            cout << arr[i] << " ";
        }
        cout << endl;    
}
template <typename T>
int print() {
    int n;
    cout << "Введите число элементов  ";
    cin >> n;
    int* arr = new int[n];
    int size = n;
    for (int i = 0; i < n; i++) {
        cout << "Ввдите" << i << "й = элемент  ";
        cin >> arr[i];
    }
    printArray(n, arr);
}
int main() {
    setlocale(LC_ALL, "");

}