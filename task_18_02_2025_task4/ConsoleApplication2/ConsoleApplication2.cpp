#include <iostream>
using namespace std;
char* removechar(const char* text, int index) {
	int len = strlen(text);
	char* text2 = new char[len];
	strncpy_s(text2, index + 1, text, index); // Безопасно
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
		if (text[i]==sym) {
			return i;
		}
	}
	return -1;
}
// Функция удаления всех вхождений символа
char* remove_all_occurrences(const char* text, char sym) {
	int index = 0;
	int len = strlen(text);
	char* current = new char[len+1];
	strncpy_s(current, len + 1, text, len);
	while ((index = found_char(current, sym)) != -1) {
		char* temp = current;
		current = removechar(temp, index);
		delete[] temp;
	}
	return current;
}
int main() {
	const char* text = "Hello, World!";
	char* text2 = new char[strlen(text)];
	text2 = remove_all_occurrences(text, 'l');
	cout << "Original: " << text << endl;
	cout << "Modified: " << text2 << endl;
	//int f = 0;	
	//text2 = removechar(text, 4);
	////strncpy_s(text2, 5, text, 4); // Безопасно
	//cout << "" << text2
	//f = found_char(text,'l');
	//cout << f << '\n';
}