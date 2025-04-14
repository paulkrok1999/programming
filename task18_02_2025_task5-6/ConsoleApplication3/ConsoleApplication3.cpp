#include <iostream>
#include <string>
using namespace std;
char* removechar(const char* text, int index) {
	size_t len = strlen(text);
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
	size_t n = strlen(arr);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}
int found_char(const char* text, char sym) {
	size_t n = strlen(text);
	for (int i = 0; i < n; i++) {
		if (text[i] == sym) {
			return i;
		}
	}
	return -1;
}
char* remove_all_occurrences(const char* text, char sym) {
	int index = 0;
	size_t len = strlen(text);
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
	size_t len = strlen(str);
	char* newstr = new char[len + 2];	
	strncpy_s(
		newstr ,
		len  +2,
		str,
		position
	);	
	newstr[position] = symbol;
	strcpy_s(
		newstr + position+1,
		len - position+1,
		str+ position
	);
	return newstr;
}
int mystrcmp(const char* str1, const char* str2) {
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
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
int StringToNumber(const char* str) {
	int sign = 1; // Знак числа (по умолчанию положительный)

	int i = 0;
	long result = 0;
	int digit = 0;
	if (str[i] == '-' || str[i] == '+') {
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
			digit = str[i] - '0';
			result = result * 10 + digit;
			i++;
	}	
	// Обработка знака числа


	return static_cast<int>(result * sign); // Применяем знак и возвращаем результат

}
char* NumberToString(int number) {
	const int buffer_size = 12;
	char buffer[buffer_size];
	int pos = buffer_size - 1;
	buffer[pos] = '\0';

	bool is_negative = (number < 0);
	unsigned int n = is_negative ? static_cast<unsigned>(-number) : static_cast<unsigned>(number);


	if (n == 0) {
		buffer[--pos] = '0';
	}
	else {
		while (n > 0) {
			buffer[--pos] = '0' + (n % 10);
			n /= 10;
		}
	}

	if (is_negative) {
		buffer[--pos] = '-';
	}

	int length = buffer_size - pos - 1; // Длина без '\0'
	char* result = new char[length + 1];

	// Используем strncpy_s вместо strncpy
	strncpy_s(result,         // Куда копируем
		length + 1,      // Размер буфера назначения
		&buffer[pos],    // Откуда копируем
		length);         // Сколько символов копируем

	return result;
}

char* Uppercase(char* str1) {

	for (int i = 0; str1[i] != '\0'; ++i) {

		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] = str1[i] - 32;


		}

		if (str1[i] >= 'а' && str1[i] <= 'я')
		{
			str1[i] = str1[i] - 32;


		}

	}
		return str1;
/*'a'   'z'	
a = 97;
		A = 65;*/

}
char* Lowercase(char* str1) {
	for (int i = 0; str1[i] != '\0'; ++i) {

		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str1[i] = str1[i] + 32;


		}

		if (str1[i] >= 'А' && str1[i] <= 'Я')
		{
			str1[i] = str1[i] + 32;


		}

	}
	return str1;
}
char* mystrrev(char* str) {
	const size_t length = strlen(str);
	char* reversed = new char[length + 1]; // +1 для '\0'
	for (size_t i = 0; i < length; ++i) {
		{
			//длина =32-1; i=0;
			reversed[i] = str[length - 1 - i];


		}
		reversed[length] = '\0'; // Завершающий нуль-терминатор

	}
	return reversed;
}

	int main() {

	setlocale(LC_ALL, "");
	//Задание 5.
//	Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
	const char* text = "Hello, World!";

	char* result = insert_char(text, 3, 'X');
	cout << "Task5.\nOriginal: " << text << "\n"; 
	cout << "Reversed: " << result << "\n";
	delete[] result;
	//Задание 6.

	//Дополните свою библиотеку функций реализациями нижеследующих функций :
	//int mystrcmp(const char* str1, const char* str2); — функция сравнивает две строки, и, если строки равны
	//	возвращает 0, если первая строка больше второй, то возвращает 1, иначе –1.
	
	const char* text2 = "Hello, New World!";
	
	cout << "Task 6.1  mystrcmp('" << text<<"', '" << text2 << "') = " << mystrcmp(text, text2) << '\n';

	//
	//	int StringToNumber(char* str); //— функция конвертирует строку в число и возвращает это число.
	text = "-123456";
	int num = StringToNumber(text);
	cout << "Task 6.2  StringToNumber('" << text << "') = " <<num << '\n';

	//char* NumberToString(int number);// — функция конвертирует число в строку и возвращает указатель на эту строку.
	int num2 = 523467;
	text2 = NumberToString(num2);
	cout << "Task 6.3  NumberToString(" << num2 << ") = '" << text2 << "'\n";
	//delete[] text2;

	//char* Uppercase(char* str1);// — функция преобразует строку в верхний регистр.
	char original[] = "hello worl!привет мир";
	
	text2 = Uppercase(original);
	
	cout << "Task 6.4  Uppercase('" << original << "') = '" << text2 << "'\n";
	//delete[] original;
	//delete[] text2;

	//char* Lowercase(char* str1);// — функция преобразует строку в нижний регистр
	char original2[] = "HELLO, 123 МИР";
	text2 = Lowercase(original2);
	cout << "Task 6.5  Lowercase('" << original2 << "') = '" << text2 << "'\n";

	//char* mystrrev(char* str); //— функция реверсирует строку и возвращает указатель на новую строку
	
	char* reversed = mystrrev(original2);
	cout << "Task 6.6  reversed('" << original2 << "') = '" << reversed << "'\n";

	//std::cout << "Original: " << original << "\n"; // Hello World
	//std::cout << "Reversed: " << reversed << "\n"; // dlroW olleH

	//char str[] = "HELLO,123 МИР!"; // Пример строки
	//std::cout << "До: " << str << std::endl; // До: Hello, 123 мир!

	//Lowercase(str);
	//std::cout << "После: " << str << std::endl; // После: HELLO, 123 МИР!

	//char* str = NumberToString(-12345);
	//printf("%s", str); // Вывод: -12345
	//delete[] str;





}