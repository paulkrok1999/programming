#pragma once
#include <iostream>
#include <string>
using namespace std;
int answer = 0;
int score = 0;
class Question {
private:
    string question_text;
    string anwer_1;
    string anwer_2;
    string anwer_3;
    string anwer_4;
    int correct_answer = 0;
    int question_score = 0;
public:
    void SetValues(string, string, string, string, string, int, int) {}
    void AskQuestion();
};
void Question::SetValues(string qt, string a1,
    string a2, string a3,
    string a4, int ca, int qs) {
    question_text = qt;
    anwer_1 = a1;
    anwer_2 = a2;
    anwer_3 = a3;
    anwer_4 = a4;
    correct_answer = ca;
    question_score = qs;
}
void Question::AskQuestion() {
    cout << "\n";
    cout << question_text << "\n"
        << "  \t1)" << anwer_1
        << "    2)" << anwer_2
        << "    3)" << anwer_3
        << "    4)" << anwer_4
        << "\n";
    cout << "Ваш ответ: ";
    cin >> answer;
    if (answer == correct_answer) {
        cout << "\nПравильно!\n"
            << "Очков: +" << question_score << "\n";
        score = score + question_score;
    }
    else {
        cout << "\nНеправельно!" << "Очков: +0"
            << "\n"
            << "Правельный ответ = " << correct_answer
            << ".\n\n";
    }
}