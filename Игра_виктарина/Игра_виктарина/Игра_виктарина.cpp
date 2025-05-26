#include <iostream>
#include <string>
#include "Header.hpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    cout << "\n\n\t\t\t<ИГРА ВИКТОРИНА>"
        << "\n";
    cout << "\nНажмите ENTER что бы начать игру..."
        << endl;
    cin.get();
    Question q1;
    /*    Question q2;
    Question q3;
    Question q4;
    Question q5;*/

    //ворос с вариантами ответа
    q1.SetValues("сколько Паши лет?"), ("18","20","40");

    //ответ Usera
    q1.AskQuestion();
    cout << "Всего очков = " << score << "из 50\n";
    if (score>=40){
        cout << "поздравляю вы выйграли!\n";
    }
    else {
        cout << "поздравляю вы проиграли!\n";
    }
    return 0;
}
