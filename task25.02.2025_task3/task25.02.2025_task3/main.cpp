#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int BOARD_SIZE = 6;
const int POSSIBLE_MOVES = 8;

// Возможные ходы коня (относительные смещения)
const int moveX[POSSIBLE_MOVES] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int moveY[POSSIBLE_MOVES] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Функция для проверки, находится ли клетка в пределах доски
bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == -1);
}

// Рекурсивная функция для поиска пути коня
bool knightTour(int x, int y, int moveCount, vector<vector<int>>& board) {
    // Если все клетки пройдены
    if (moveCount == BOARD_SIZE * BOARD_SIZE) {
        return true;
    }

    // Пробуем все возможные ходы из текущей позиции
    for (int i = 0; i < POSSIBLE_MOVES; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;

            if (knightTour(nextX, nextY, moveCount + 1, board)) {
                return true;
            }
            else {
                // Откат (backtracking)
                board[nextX][nextY] = -1;
            }
        }
    }

    return false;
}

// Функция для вывода доски
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, -1));

    int startX, startY;

    cout << "Шахматная доска 6x6" << endl;
    cout << "Введите начальные координаты коня (x y, от 0 до 5): ";
    cin >> startX >> startY;

    // Проверка корректности ввода
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE) {
        cout << "Некорректные координаты!" << endl;
        return 1;
    }

    // Начальная позиция
    board[startX][startY] = 0;

    // Запуск поиска пути
    if (knightTour(startX, startY, 1, board)) {
        cout << "Маршрут коня найден:" << endl;
        printBoard(board);
    }
    else {
        cout << "Маршрут не найден для данных начальных координат." << endl;
    }

    return 0;
}