// task11-02-25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main() {
    int* arr = new int[1]; // Начальный массив из 1 элемента
    int size = 1; // Текущий размер

    cout << "Enter a number: ";
    int num;
    cin >> num;

    if (num < 0) {
        delete[] arr; // Освобождаем память, если первое число <0
        return 0;
    }

    arr[0] = num; // Записываем 1 число в массив

    while (true) {
        cout << "Enter next number: ";
        cin >> num;

        if (num < 0) {
            break; // Выход из цикла при <0
        }

        int* newArr = new int[size + 1]; // Новый массив на 1 элемент больше

        // Копируем существующие элементы
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }

        newArr[size] = num; // Добавляем  число
        delete[] arr;       // Удаляем  массив
        arr = newArr;        // Обновляем указатель на новый массив
        size++;              // Увеличиваем размер
    }

    delete[] arr; // Освобождаем память перед завершением

    return 0;
}
