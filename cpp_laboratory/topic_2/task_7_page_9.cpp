#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	double x, y, z;
	cout << "Введите 2 числа: ";
	cin >> x >> y;
	if (x < 0)
		if (x > y) z = x;
		else z = y;
	else if (x < y) z = x;
	else z = y;
	cout << z;
}
