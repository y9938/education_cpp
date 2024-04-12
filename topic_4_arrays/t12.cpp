#include <iostream>
using namespace std;

int main() {
	const int SIZE = 50;
	char a[SIZE] = {};
	
	int count = 0;
	char input;
	cout << "Введите элементы массива (до " << SIZE << ") и точку для завершения ввода:\n";
	for (int i = 0; i < SIZE; i++) {
		if (cin >> input && input == '.') {
			if (count == 0) {
				cout << "Массива нет";
				return 0;
			}
			break;
		}
		a[i] = input;
		count++;
	}

	cout << "Вывод массива в обратном порядке:\n";
	for (int i = count - 1; i >= 0; i--) {
		cout << a[i] << endl;
	}

	bool s = true;
	cout << "Проверка на палиндром:\n";
	for (int i = 0; i < count/2; i++) {
		if (a[i] != a[count - i - 1]) {
			s = false;
			break;
		}
	}

	if (s == true) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
