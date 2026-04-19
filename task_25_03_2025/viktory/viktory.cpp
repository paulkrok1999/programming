#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <limits>
#include <climits>
using namespace std;


struct Answer {
    string text = "";
    bool correct = false;
};
struct Question {
    string text = "";
    vector<Answer> answers;
};
void printQuiz(const std::vector<Question>& quiz);
void saveToBinaryFile(const std::vector<Question>& quiz, const std::string& filename);
std::vector<Question> loadFromBinaryFile(const std::string& filename);
void inputQuiz();
void clearInputBuffer();
int safeInputInt(const std::string& prompt, int minVal, int maxVal);
void playQuiz(vector<Question>& quiz);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int menu =1;

    while (menu != 0)
    {
        cout << "Меню программы" << endl;
        cout << "1. Загрузка викторины и просмотр" << endl;
        cout << "2. Загрузка викторины и игра" << endl;
        cout << "3. Запуск создания викторины" << endl;
        cout << "0. Выход" << endl;
        cin >> menu;
        if (menu == 1) {
            std::vector<Question> quiz; // Вектор для всех вопросов
            string filename;
            cout << "введите имя файла: ";
            cin >> filename;
            quiz = loadFromBinaryFile(filename);
            printQuiz(quiz);
        }
        else if (menu == 2)
        {
            std::vector<Question> quiz; // Вектор для всех вопросов
            string filename;
            cout << "введите имя файла: ";
            cin >> filename;
            quiz = loadFromBinaryFile(filename);
            playQuiz(quiz);
        }
        else if (menu == 3) {
            inputQuiz();
        }

    }    
    return 0;
}
void printQuiz(const std::vector<Question>& quiz) {
    for (size_t q = 0; q < quiz.size(); ++q) {
        cout << "\nВопрос " << q + 1 << ": " << quiz[q].text << endl;
        cout << "Варианты ответов:" << endl;

        for (size_t a = 0; a < quiz[q].answers.size(); ++a) {
            std::cout << "  " << a + 1 << ". " << quiz[q].answers[a].text;
            std::cout << " - " << (quiz[q].answers[a].correct ? "[ПРАВИЛЬНО]" : "[НЕПРАВИЛЬНО]");
            std::cout << std::endl;
        }
    }
}
// Сохранение викторины в бинарный файл
void saveToBinaryFile(const std::vector<Question>& quiz, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }

    // Сохраняем количество вопросов
    size_t questionCount = quiz.size();
    file.write(reinterpret_cast<const char*>(&questionCount), sizeof(questionCount));

    // Сохраняем каждый вопрос
    for (const auto& question : quiz) {
        // Сохраняем текст вопроса
        size_t questionLength = question.text.length();
        file.write(reinterpret_cast<const char*>(&questionLength), sizeof(questionLength));
        file.write(question.text.c_str(), questionLength);

        // Сохраняем количество ответов
        size_t answerCount = question.answers.size();
        file.write(reinterpret_cast<const char*>(&answerCount), sizeof(answerCount));

        // Сохраняем каждый ответ
        for (const auto& answer : question.answers) {
            // Сохраняем текст ответа
            size_t textLength = answer.text.length();
            file.write(reinterpret_cast<const char*>(&textLength), sizeof(textLength));
            file.write(answer.text.c_str(), textLength);

            // Сохраняем флаг correct
            file.write(reinterpret_cast<const char*>(&answer.correct), sizeof(answer.correct));
        }
    }

    file.close();
}

// Загрузка викторины из бинарного файла
std::vector<Question> loadFromBinaryFile(const string& filename) {
    std::vector<Question> quiz;
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return quiz;
    }

    // Загружаем количество вопросов
    size_t questionCount;
    file.read(reinterpret_cast<char*>(&questionCount), sizeof(questionCount));

    // Загружаем каждый вопрос
    for (size_t q = 0; q < questionCount; ++q) {
        Question question;

        // Загружаем текст вопроса
        size_t questionLength;
        file.read(reinterpret_cast<char*>(&questionLength), sizeof(questionLength));
        char* questionBuffer = new char[questionLength + 1];
        file.read(questionBuffer, questionLength);
        questionBuffer[questionLength] = '\0';
        question.text = questionBuffer;
        delete[] questionBuffer;

        // Загружаем количество ответов
        size_t answerCount;
        file.read(reinterpret_cast<char*>(&answerCount), sizeof(answerCount));

        // Загружаем каждый ответ
        for (size_t a = 0; a < answerCount; ++a) {
            Answer answer;

            // Загружаем текст ответа
            size_t textLength;
            file.read(reinterpret_cast<char*>(&textLength), sizeof(textLength));
            char* textBuffer = new char[textLength + 1];
            file.read(textBuffer, textLength);
            textBuffer[textLength] = '\0';
            answer.text = textBuffer;
            delete[] textBuffer;

            // Загружаем флаг correct
            file.read(reinterpret_cast<char*>(&answer.correct), sizeof(answer.correct));

            question.answers.push_back(answer);
        }

        quiz.push_back(question);
    }

    file.close();
    return quiz;
}

void inputQuiz() {
    int otvetov;
    int vopros;
    vector<Question> quiz; // Вектор для всех вопросов
    string filename;

 
    vopros = safeInputInt("Сколько числа вопросов: ",1,10);
   
     // Ввод каждого вопроса
    for (int q = 0; q < vopros; ++q) {
       
        std::cout << "\n=== Вопрос " << q + 1 << " ===" << endl;
        Question quest;
        std::cout << "Введите текст вопроса: " << endl;
        // НЕ НУЖНО wcin.ignore() здесь, так как первый ввод
        getline(cin, quest.text);
        std::cin.ignore();       
    
        otvetov = safeInputInt("Сколько вариантов ответов: ",1,10);
        std::cin.ignore();
        for (int i = 0; i < otvetov; ++i) {
            Answer answer;

            cout << "  Ответ " << i + 1 << ": ";
            getline(cin, answer.text);  // Читаем строку

            cout << "  Это правильный ответ? (1/0): ";
            cin >> answer.correct;  // Читаем число
            cin.ignore();           // ОДИН ignore после числа

            quest.answers.push_back(answer);
        }
        quiz.push_back(quest);

    }
    printQuiz(quiz);
    cout << "что бы сохранить вопросы, введите name: ";
    cin >> filename;
    saveToBinaryFile(quiz, filename);
}




void clearInputBuffer() {
    std::cin.clear();
    //cin.ignore();
    std::cin.ignore(INT_MAX, '\n');
}

int safeInputInt(const std::string& prompt, int minVal, int maxVal) {
    int value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            clearInputBuffer();
            std::cout << "ОШИБКА: Введите ЧИСЛО от " << minVal << " до " << maxVal << "!" << std::endl;
            continue;
        }

        if (value < minVal || value > maxVal) {
            clearInputBuffer();
            std::cout << "ОШИБКА: Число должно быть от " << minVal << " до " << maxVal << "!" << std::endl;
            continue;
        }

        break; // Успешный ввод
    }

    return value;
}

// ===== ГЛАВНАЯ ПРОЦЕДУРА ИГРЫ =====
void playQuiz(vector<Question>& quiz) {
    if (quiz.empty()) {
        cout << "\nОШИБКА: Нет вопросов для викторины!" << endl;
        return;
    }

    int score = 0;
    int totalQuestions = quiz.size();

    cout << "\n" << string(50, '=') << endl;
    cout << "🎮 НАЧАЛО ВИКТОРИНЫ! 🎮" << endl;
    cout << string(50, '=') << endl;
    cout << "Всего вопросов: " << totalQuestions << endl;
    cout << "Для ответа введите номер варианта (1, 2, 3...)" << endl;
    cout << string(50, '=') << endl;

    // Перемешиваем вопросы (опционально)
    // srand(time(0));
    // random_shuffle(quiz.begin(), quiz.end());

    for (size_t q = 0; q < quiz.size(); ++q) {
        cout << "\n" << string(40, '-') << endl;
        cout << "Вопрос " << q + 1 << " из " << totalQuestions << ":" << endl;
        cout << "📝 " << quiz[q].text << endl;
        cout << string(40, '-') << endl;

        // Выводим варианты ответов
        for (size_t a = 0; a < quiz[q].answers.size(); ++a) {
            cout << "  " << a + 1 << ". " << quiz[q].answers[a].text << endl;
        }

        cout << "\nВаш ответ (номер): ";

        int userAnswer = safeInputInt("", 1, quiz[q].answers.size());

        // Проверяем ответ
        if (quiz[q].answers[userAnswer - 1].correct) {
            cout << "✅ ПРАВИЛЬНО! +1 балл" << endl;
            score++;
        }
        else {
            cout << "❌ НЕПРАВИЛЬНО!" << endl;
            // Находим и показываем правильный ответ
            for (size_t a = 0; a < quiz[q].answers.size(); ++a) {
                if (quiz[q].answers[a].correct) {
                    cout << "Правильный ответ: " << quiz[q].answers[a].text << endl;
                    break;
                }
            }
        }

        cout << "Текущий счет: " << score << " из " << q + 1 << endl;

        // Пауза между вопросами
        if (q < quiz.size() - 1) {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
            clearInputBuffer();
        }
    }

    // Выводим финальный результат
    cout << "\n" << string(50, '=') << endl;
    cout << "🎉 РЕЗУЛЬТАТ ВИКТОРИНЫ 🎉" << endl;
    cout << string(50, '=') << endl;
    cout << "Правильных ответов: " << score << " из " << totalQuestions << endl;

    double percentage = (double)score / totalQuestions * 100;
    cout << "Процент правильных: " << percentage << "%" << endl;

    // Оценка
    cout << "\nОценка: ";
    if (percentage >= 90) {
        cout << "5 (Отлично!) 🌟🌟🌟" << endl;
    }
    else if (percentage >= 75) {
        cout << "4 (Хорошо!) 🌟🌟" << endl;
    }
    else if (percentage >= 60) {
        cout << "3 (Удовлетворительно!) 🌟" << endl;
    }
    else if (percentage >= 40) {
        cout << "2 (Плохо!)" << endl;
    }
    else {
        cout << "1 (Очень плохо!)" << endl;
    }

    cout << string(50, '=') << endl;
}



