#include <iostream>
#include <Windows.h>
#include <ctime>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

const int width = 17;      // ширина поля (без учёта '\n')
const int height = 10;     // высота поля
const int max_len = (width - 2) * (height - 2); // максимальная длина змейки

const int up = 0;
const int down = 1;
const int left = 2;
const int right = 3;

int snake_dir = up;
bool isRunning = true;

// Массив для отображения поля (без символов '\n')
char map[height][width] = {
    "###############",
    "#             #",
    "#             #",
    "#             #",
    "#             #",
    "#             #",
    "#             #",
    "#             #",
    "#             #",
    "###############"
};

char snake_char = 'o';
int snake_x[max_len] = { 0 };
int snake_y[max_len] = { 0 };
int snake_len = 1;

int main() {
    // Начальная позиция головы змейки
    snake_x[0] = width / 2;
    snake_y[0] = height / 2;

    clock_t time = clock();
    gotoxy(0, 0);

    while (isRunning) {
        // Управление
        if (GetKeyState('W') & 0x8000 && snake_dir != down) snake_dir = up;
        if (GetKeyState('S') & 0x8000 && snake_dir != up)   snake_dir = down;
        if (GetKeyState('A') & 0x8000 && snake_dir != right) snake_dir = left;
        if (GetKeyState('D') & 0x8000 && snake_dir != left)  snake_dir = right;

        // Задержка движения (1 секунда)
        if ((clock() - time) / CLOCKS_PER_SEC >= 1.0) {
            time = clock();

            // Сдвиг сегментов змейки (от хвоста к голове)
            for (int i = snake_len - 1; i > 0; --i) {
                snake_x[i] = snake_x[i - 1];
                snake_y[i] = snake_y[i - 1];
            }

            // Движение головы
            if (snake_dir == up)    --snake_y[0];
            if (snake_dir == down)  ++snake_y[0];
            if (snake_dir == left)  --snake_x[0];
            if (snake_dir == right) ++snake_x[0];

            // Проверка столкновения со стенами
            if (snake_x[0] <= 0 || snake_x[0] >= width - 1 ||
                snake_y[0] <= 0 || snake_y[0] >= height - 1) {
                isRunning = false;
                break;
            }

            // Проверка столкновения с собственным хвостом
            for (int i = 1; i < snake_len; ++i) {
                if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) {
                    isRunning = false;
                    break;
                }
            }
            if (!isRunning) break;

            // Отрисовка
            gotoxy(0, 0);
            std::cout << "Length: " << snake_len << std::endl;

            // Временное рисование змейки на карте
            for (int i = 0; i < snake_len; ++i) {
                map[snake_y[i]][snake_x[i]] = snake_char;
            }

            // Вывод поля
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    std::cout << map[i][j];
                }
                std::cout << std::endl;
            }

            // Стирание змейки с карты
            for (int i = 0; i < snake_len; ++i) {
                map[snake_y[i]][snake_x[i]] = ' ';
            }
        }
    }

    // Вывод результата
    gotoxy(1, height / 2);
    std::cout << "Your score: " << snake_len;
    gotoxy(width, height);
    return 0;
}