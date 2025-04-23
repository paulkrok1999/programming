#include <iostream>
using namespace std;
char* removeChar(const char* text, int index) {
	int len = strlen(text);
	char* text2 = new char[len];
	strncpy_s(text2, index+1, text, index); // Безопасно
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
int main() {
	const char* text = "Hello, World!";
	char* text2 = new char[strlen(text)];
	text2 =  removeChar(text, 4);
	//strncpy_s(text2, 5, text, 4); // Безопасно
	cout << "" << text2;
}