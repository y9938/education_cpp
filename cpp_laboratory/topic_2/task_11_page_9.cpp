#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "RU");

	int k;
	cout << "Введите четырехзначное число: ";
	cin >> k;

	if (k < 1000 || k >= 10000) {
		cout << "Число не четырехзначное\n";
		return 1;
	}

	int ones, tens, hundreds, thousands;
	thousands = k / 1000;
	hundreds = (k / 100) % 10;
	tens = (k / 10) % 10;
	ones = k % 10;

	if (ones == thousands && tens == hundreds)
		cout << "Это число палиндром\n";
	else cout << "Нет, это число не палиндром\n";

	return 0;
}
