#include <iostream>
using namespace std;
int Sumprint(const int n,int* arr) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	return sum;
}
int het(const int num) {
	if (num % 2 > 0) {
		cout << "четное\n";
		return false;
	}
	else {
		cout << "не четное\n";
		return true;
	}
}
int Sumhet(const int n, int* arr) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (het(arr[i]))
			sum = sum + arr[i];
	}
	return sum;
}
int Sumhet2(const int n, int* arr) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (!het(arr[i]))
			sum = sum + arr[i];
	}
	return sum;
}
//void perever(int *arr, int ver) {
//	int* _arr = new int[ver];
//	for (int i = 0; i < ver; i++) _arr[i] = arr[i];
//	for (int i = 0; i < ver; i++) {
//		arr[i] = _arr[(ver - 1) - i];
//	}
//}
//void perever2(int* &arr, int ver) {
//	int* arrnew = new int[ver];
//	int j = 0;
//	for (int i = ver-1; i >= 0; i--) {
//		arrnew[j] = arr[i];
//		j++;
//	}
//	delete[] arr ;
//	arr = arrnew;
//}

//,int*& pol, int& num_pol
int chet(const int& n, int*& arr){
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	sum++;

	int sum2 = -1;
	for (int i = -1; i < n; i++) {
		sum2 = sum2 + arr[i];
	}
	sum2++;
	
	int sum3;
	int sum3 = sum + sum2;
	return sum3;
}

/*print_arrar(arr,n);
sort_mass(arr, n,pol, num_pol,otriz, inum_otriz);
print_arrar(pol,num_pol);
print_arrar(otriz,num_otriz);*/
int main() {
	setlocale(LC_ALL, "");
	int n = 2;
	int* arr = new int[2] {-2,2};

	cout << "" << chet << n << arr;;
	/*erever2(arr, 5);
	for (int i = 0; i < 5; i++)
	cout << arr[i];*/
	delete[] arr;
}