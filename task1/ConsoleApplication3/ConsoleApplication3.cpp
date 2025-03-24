#include <iostream>
#include <algorithm> // Для std::sort
#include <random>
using namespace std;



template <typename T>
void initarray(const int n, T** arr);

template <typename T>
void fillarray(const int n,T** arr);

template <typename T>
void printArray(const int n, T** arr);

template <typename T>
void freearray(T** array, const int n);

int randomNumber(int min, int max);

template <typename T>
int findmax(const int n, T** arr);

template <typename T>
int findmin(const int n, T** arr);

template <typename T>
double sred(const int n, T** arr);

template <typename T>
int findsum(const int n, T** arr);

template <typename T>
void printsum(const int n, T** arr);

template <typename T>
int printsum2(const int n, T** arr);

template <typename T>
void findnum(const int n, T** arr,const T NUM);

template <typename T>
void menu(const int n, T** Array, T NUM);

void menu2();

int main() {
    setlocale(LC_ALL, "");
   // Размерность матрицы
    //Главное меню
    int pm = 0;
    while (pm != 2) {
        cout << "#Введите действие(при выборе типа данные стираются) :\n#";
        cout << "1.	Выбрать тип данных\n";
        cout << "2. Выход\n";
        cin >> pm;
        if (pm == 1) {
            menu2();
        }    

    }  
    return 0;
}

void menu2() 
{
    int pm2 = -1;
    int n = 4;
    while (pm2 < 0) {
        cout << "#Введите тип данных:                            \n#";
        cout << "#1.	Long#\n";
        cout << "#2.	Int#\n";
        cout << "#3.	Double#\n";
        cout << "#4.	Char#\n";
        cout << "#5.	Short#\n";
        cin >> pm2;
        if (pm2 >= 1 and pm2 <= 5) {

        }
        else {
            pm2 = -1;
        }


    }
    if (pm2 == 1) {
        long** Array = new long* [n];
        long NUM = 0;
        initarray(n, Array);
        menu(n, Array, NUM);

    }
    else if (pm2 == 2) {
        int** Array = new int* [n];
        int NUM = 0;
        initarray(n, Array);
        menu(n, Array, NUM);
    }
    else if (pm2 == 3) {
        double** Array = new double* [n];
        double NUM = 0;
        initarray(n, Array);
        menu(n, Array, NUM);
    }
    else if (pm2 == 4) {
        unsigned char** Array = new unsigned char* [n];
        unsigned char NUM = 0;
        initarray(n, Array);
        menu(n, Array, NUM);
    }
    else if (pm2 == 5) {
        short** Array = new short* [n];
        short NUM = 0;
        initarray(n, Array);
        menu(n, Array, NUM);
    }
}
template <typename T>
void menu(const int n,T**Array,T NUM) {
    int pm = -1;

    while (pm != 10)
    {
        cout << "#Введите действие :                                \n#";
        cout << "#1 . Заполнения массива случайными данными:        \n#";
        cout << "#2. Вывод массива на экран:                        \n#";
        cout << "#3. Поиск максимального элемента:                  \n#";
        cout << "#4. Поиск минимального элемента:                   \n#";
        cout << "#5. Поиск среднего арифметического                 \n#";
        cout << "#6. Линейный поиск элемента                        \n#";
        cout << "#7. Вывод на экран суммы элементов каждой строки   \n#";
        cout << "#8. Вывод на экран суммы элементов каждого столбца \n#";
        cout << "#9. Вывод на экран суммы элементов всего массива   \n#";
        cout << "#10. Главное меню                                  \n#";


        cin >> pm;
        if (pm == 1) {
            fillarray(n, Array);
        }
        else if (pm == 2) {
            printArray(n, Array);
        }
        else if (pm == 3) {
            cout << "MAX=" << findmax(n, Array) << endl;
        }
        else if (pm == 4) {
            cout << "MIH=" << findmin(n, Array) << endl;
        }
        else if (pm == 5) {
            cout << "SRED=" << sred(n, Array) << endl;
        }
        else if (pm == 6) {
            NUM = 0;
            cout << "Введите число для поиска:";
            cin >> NUM;
            findnum(n, Array, NUM);
        }
        else if (pm == 7) {
            printsum(n, Array);
        }
        else if (pm == 8) {
            printsum2(n, Array);
        }
        else if (pm == 9) {
            cout << "sum=" << findsum(n, Array) << endl;
        }

    }

    freearray(Array, n);
}
template <typename T>
int findmax(const int n, T** arr) {
    T max = arr[0][0];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x <n; x++) {
            if (arr[y][x] > max) {
                max = arr[y][x];
            }
        }
    }
    return max;
}



template <typename T>
int findmin(const int n, T** arr) {
    T min = arr[0][0];
    for (int y = 0; y < n; y++) { 
        for (int x = 0; x < n; x++) {
            if (arr[y][x] < min) {
                min = arr[y][x];
            }
        }        
    }
    return min;
}

template <typename T>
double sred(const int n, T** arr) {
    T SUM = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {          
                SUM = SUM + arr[y][x];            
        }
    }    
    double sr = static_cast<float>(SUM) / (n*n);
    return sr;
}
template <typename T>
int findsum(const int n, T** arr) {
    int SUM = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {           
                SUM = SUM + arr[y][x];            
        }
    }    
    return SUM;
}
template <typename T>
void findnum(const int n, T** arr, const T NUM) {
    int xi = -1;
    int yi = -1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (arr[x][y] == NUM) {
                xi = x;
                yi = y;
            }
        }
    }
    if (xi >= 0 and yi >= 0) {
        cout << NUM << " Found(" << xi << "," << yi << ")" << endl;
    }
    else {
        cout << NUM << "-Not Found" << endl;
    }
}


template <typename T>
void printsum(const int n, T** arr) {
    T SUM;
    for (int y = 0; y < n; y++) {
        SUM = 0;
        for (int x = 0; x < n; x++) {
            SUM = SUM + arr[y][x];
        }
        cout <<y<<" row sum is" << " " << SUM << endl;
    }
    
}

template <typename T>
int printsum2(const int n, T** arr) {
    T SUM;
    for (int x = 0; x < n; x++) {
        SUM = 0;
        for (int y = 0; y < n; y++) {
            SUM = SUM + arr[y][x];
        }
        cout << x << " col sum is "<< " " << SUM << endl;
    }
    return SUM;
}


int randomNumber(int min, int max) {
    // Генерация случайного числа типа int в заданном диапазоне
    static random_device rd; // Получаем случайное число из устройства
    static mt19937 gen(rd()); // Инициализация генератора
    uniform_int_distribution<int> dis(min, max); // Диапазон для int
    return dis(gen);
}
template <typename T>
void initarray(const int n, T** arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = new T[n]; // Выделение памяти для второго измерения
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            arr[y][x] = 0; // Инициализация массива
        }
    }
}

//template <typename T>
//void fillarray(const int n, T** arr) {
//    for (int i = 0; i < n; i++) {
//        arr[i] = new T[n];
//    }
//    for (int y = 0; y < n; y++) {
//        for (int x = 0; x < n; x++) {
//            arr[y][x] = static_cast<T>( randomNumber(10, 1000)/10);//y * n + x; // Инициализация массива
//        }
//    }
//}
template <typename T>
void fillarray(const int n, T** arr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> int_dis(100, 1000); // От 100 до 1000

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if constexpr (is_floating_point_v<T>) {
                arr[y][x] = static_cast<T>(int_dis(gen)) / 10.0;
            }
            else {
                arr[y][x] = int_dis(gen) / 10;
            }
        }
    }
}

template <typename T>
void printArray(int n, T** arr) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            cout << static_cast<T>(arr[y][x]) << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void freearray(T** array, const int n) {
    for (int i = 0; i < n; i++) {
        delete[] array[i]; // Освобождаем каждую строку
    }
    delete[] array; // Освобождаем массив указателей
}
