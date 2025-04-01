#include <iostream>
using namespace std;
void sortElements(int* arr, int size) {

    int* posArr = new int[size];
    
    int* negArr = new int[size];
    
    int* zeroArr = new int[size];
    
    int posIndex = 0;
    
    int negIndex = 0;
    
    int zeroIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posArr[posIndex] = arr[i];
            posIndex++;
        }

        else if (arr[i] < 0) {

            negArr[negIndex] = arr[i];
            negIndex++;

        }

        else {
            zeroArr[zeroIndex] = arr[i];
            zeroIndex++;
        }
    }
    cout << "обычные: ";

    for (int i = 0; i < posIndex; i++) {

        cout << posArr[i] << " ";

    }

    cout << endl;

    cout << "отрицательные: ";

    for (int i = 0; i < negIndex; i++) {

        cout << negArr[i] << " ";

    }

    cout << endl;

    cout << "нулевые: ";

    for (int i = 0; i < zeroIndex; i++) {

        cout << zeroArr[i] << " ";

    }

    cout << endl;

    delete[] posArr;

    delete[] negArr;

    delete[] zeroArr;

}
int main() {
    setlocale(LC_ALL, "");
    int arr[] = { 2, -4, 5, -7, 9, -10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    sortElements(arr, size);
    return 0;
}