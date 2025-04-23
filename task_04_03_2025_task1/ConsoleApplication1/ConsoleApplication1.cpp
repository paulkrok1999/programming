#include <iostream>
using namespace std;
struct comp_num {
	double real;//действительное
	double imag;//мнимое	
};

// Вывод комплексного числа
void printComplex(comp_num c) {
	cout << c.real;
	if (c.imag >= 0) {
		cout << " + " << c.imag;
	}
	else {
		cout << " - " << -c.imag;
	}
	cout << "*i" << endl;
}
// Сумма двух комплексных чисел
comp_num add(comp_num a, comp_num b) {	
	comp_num result;	
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

comp_num sub(comp_num a, comp_num b){
	comp_num result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}
comp_num mul(comp_num r1, comp_num r2) {
	comp_num result;
	result.real = (r1.real * r2.real) - (r1.imag * r2.imag);
	result.imag = (r1.real * r2.imag) + (r1.imag * r2.real);
	return result;
}
// Деление (с проверкой деления на ноль)
comp_num divide(comp_num a, comp_num b) {
	double denominator = b.real * b.real + b.imag * b.imag;
	if (denominator == 0) {
		cerr << "Ошибка: деление на ноль!" << endl;
		return { 0, 0 };
	}
	return {
		(a.real * b.real + a.imag * b.imag) / denominator,
		(a.imag * b.real - a.real * b.imag) / denominator
	};
}
int main() {
	setlocale(LC_ALL, "");
	comp_num r1, r2, result;
	cout << "Введите первое число(r1.real): ";
	cin >> r1.real;
	cout << "Введите второе число(r1.imag): ";
	cin >> r1.imag;	
	cout << "Введите первое число(r2.real): ";
	cin >> r2.real;
	cout << "Введите второе число(r2.imag): ";
	cin >> r2.imag;
	cout << "первое сумирование чисел\n";
	printComplex(add(r1,r2));
	cout << "второе сумирование чисел (вычитание)\n";
	printComplex(sub(r1, r2));
	cout << "сложение\n";
	printComplex(mul(r1, r2));
	cout << "divide\n";
	printComplex(divide(r1, r2));
}