#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	int n;
	cout << "Введите количество элементов массива (не более 100): ";
	cin >> n;

	int a[100] = {};

	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}

	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}

	int index_min = 0;
	int min = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			index_min = i;
		}
	}

	for (int i = 0; i < index_min; i++) {
		a[i] *= min;
	}

	cout << "Умноженные элементы массива:" << endl;
	for (int i = 0; i < index_min; i++) {
		cout << a[i] << endl;
	}

	return 0;
}
