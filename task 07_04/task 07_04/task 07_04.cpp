#include <iostream>
using namespace std;
void print(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}
void filterPositive(int* arr, int n, int*& pol, int& p, int*& otris, int& o, int*& zero, int& z) {
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			p++;
		}
		if (arr[i] == 0) {
			z++;
		}
		if (arr[i] < 0) {
			o++;
		}
	}
	pol = new int[p];
	int pp = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			
			pol[pp] = arr[i];
			pp++;
		}
	}
	otris = new int[o];
	pp = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			otris[pp] = arr[i];
			pp++;
		}
	}
	zero = new int[z];
	pp = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			zero[pp] = arr[i];
			pp++;
		}
	}
}
int main() {
	setlocale(LC_ALL, "");
	int n = 5;
	int p = 0;
	int o = 0;
	int z = 0;
	int* otris = new int[o];
	int* zero = new int[z];
	int* pol = new int[p];
	int* arr = new int[5] {5, -1, 9, 0, 8};
	print(arr, n);
	filterPositive(arr, n, pol, p, otris, o,zero,z);
	cout << "список положительных:\n";
	print(pol, p);
	cout << "список отрицательных:\n";
	print(otris,o);
	cout << "список нулевых:\n";
	print(zero, z);
}
