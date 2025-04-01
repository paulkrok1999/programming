#include <iostream>
#include <algorithm> // Для std::sort
#include <random>
using namespace std;
int randomNumber(int min, int max) {
    // Генерация случайного числа типа int в заданном диапазоне
    static random_device rd; // Получаем случайное число из устройства
    static mt19937 gen(rd()); // Инициализация генератора
    uniform_int_distribution<int> dis(min, max); // Диапазон для int
    return dis(gen);
}
void initarray(const int n, int* arr) {   
        for (int x = 0; x < n; x++) {
            arr[x] = randomNumber(1, 100);//y * n + x; // Инициализация массива
        }   
}
void printArray(const int n, int* arr) {  
        for (int x = 0; x < n; x++) {
            cout << arr[x] << " ";
            cout << endl;
        }          
}
void freearray(int* array, const int n) {       
    delete[] array; // Освобождаем массив указателей
}
// Проверка на простое число
bool isPrime(const int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

void printi_sPrime(const int n, int* arr) {    
    int count = 0;
        for (int i = 0; i < n; i++) {            
            if (isPrime(arr[i])) {
               
                cout << "простые: " << arr[i] << '\n';
                count++;                
            }    
        }
        cout << "сколько раз встречаются простые" << count << endl;
}
int count_not_print(const int n, int* arr) {
    int cant = 0;
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i])) {
            cant++;
        }
    }    
    return cant;
}
// Удаление простых чисел + уменьшение размера
void removePrimes(int*& arr, int& size) {
    // 1. Считаем, сколько чисел останется
    int  notprime;
    notprime = count_not_print(size, arr);

    // 2. Создаём новый массив    

    int* newArr = new int [notprime];

        //копируем только не простые числа в новый массив
  
        int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j] = arr[i];
            j++;
        }
    }


   // 3. Удаляем старый, заменя новым
    delete[] arr;
    arr = newArr;
    size = notprime;

}
int main() {   
    setlocale(LC_ALL, "");
    int n = 10; // Размерность матрицы  
    int* intArray = new int[n];     
    initarray(n, intArray);
    printArray(n, intArray);
    removePrimes(intArray, n);
    cout << "после\n";
    printArray(n, intArray);

    //printi_sPrime(n, intArray);
    //int notprime = 0;
    //notprime =count_not_print(n, intArray);
    //cout << "сколько раз встречаются не простые" << notprime << endl;
    freearray(intArray, n);
    return 0; 
}