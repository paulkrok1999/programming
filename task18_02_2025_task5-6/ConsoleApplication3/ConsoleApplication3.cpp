#include <iostream>
using namespace std;
char* removechar(const char* text, int index) {
	int len = strlen(text);
	char* text2 = new char[len];
	strncpy_s(text2, index + 1, text, index);
	strcpy_s(
		text2 + index,
		len - index,
		text + index + 1
	);
	return text2;
}
void print_arr(const char* arr) {
	int n = strlen(arr);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}
int found_char(const char* text, char sym) {
	int n = strlen(text);
	for (int i = 0; i < n; i++) {
		if (text[i] == sym) {
			return i;
		}
	}
	return -1;
}
char* remove_all_occurrences(const char* text, char sym) {
	int index = 0;
	int len = strlen(text);
	char* current = new char[len + 1];
	strncpy_s(current, len + 1, text, len);
	while ((index = found_char(current, sym)) != -1) {
		char* temp = current;
		current = removechar(temp, index);
		delete[] temp;
	}
	return current;
}
char* insert_char(const char* str, int position, char symbol) {
	// Выделение памяти для новой строки (+2: символ + нуль-терминатор)
	int len = strlen(str);
	char* newstr = new char[len + 2];

	// Копирование части до позиции вставки
	
	strncpy_s(
		newstr ,
		len  +2,
		str,
		position
	);
	// Вставка символа
	newstr[position] = symbol;

	// Копирование части после позиции
	strcpy_s(
		newstr + position+1,
		len - position+1,
		str+ position
	);
	return newstr;
}
int mystrcmp(const char* str1, const char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1==len2) {
		return 0;
	}
	else if (len1 > len2) {
		return 1;
	}
	else {
		return -1;
	}
}
int StringToNumber(char* str) {
	return 0;
}
int main() {
	//Задание 5.
	//	Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
	setlocale(LC_ALL, "");
	const char* text = "Hello, World!";
	char* text2 = new char [strlen(text) + 1+1];
	text2 = insert_char(text, 2, 'X');
	cout << "Было\n";
	cout << text << "\n";
	text2 = insert_char(text, 2, 'X');
	cout << "Стало\n";
	cout << text2 << "\n";
	//Задание 6.
	//Дополните свою библиотеку функций реализациями нижеследующих функций :
	//Функция сравнения строк
	text = "Hello, World!";
	const char* text3 = "Hello, X World!";
	int result = mystrcmp(text,text3);
	cout <<"Результат сравнения строк "<< result;
	//Функция преобразования строки в число
	//-123
}