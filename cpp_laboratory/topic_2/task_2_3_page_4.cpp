#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int num, d1, d2, d3, d4, d5, d6;
	cout << "Введите шестизначное число = ";
	cin >> num;
	if (num / 1000000 != 0 || num / 100000 == 0)
		cout << "Вы ввели не шестизначное число\n";
	else
	{
		d1 = num / 100000;
		d2 = num / 10000 % 10;
		d3 = num / 1000 % 10;
		d4 = num / 100 % 10;
		d5 = num / 10 % 10;
		d6 = num % 10;
		if (d1 + d2 + d3 == d4 + d5 + d6)
			cout << "Число счастливое\n";
		else
			cout << "Число несчастливое\n";
	}
}
