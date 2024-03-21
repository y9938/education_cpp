#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x = 2.0;
	double h = 0.2;
	double sum_values = 0.0;
	int count = 0;

	cout << "x\t\t y = tan(x)\n";
	while (x <= 6.1) {
		double y = tan(x);
		cout << x << "\t\t " << y << "\n";

		if (y > 0.2 && y < 0.8) {
			sum_values += y; // сумма значений функции
			count++; // количество значений
		}
		x += h;
	}

	double average = sum_values / count;
	cout << "Среднее значение между 0.2 и 0.8: " << average;
	return 0;
}
