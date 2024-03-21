#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int num1, num2, num3;
	cout << "Введите 3 ненулевых целых числа: ";
	cin >> num1 >> num2 >> num3;

	// Проверка на положительность числа
	if (num1 <= 0 || num2 <= 0 || num3 <= 0) {
		cout << "Числа должны положительными и ненулевыми\n";
		return 1;
	}

	// Нахождение максимального из трех чисел
	int max = num1;
	if (num2 > max) max = num2;
	if (num3 > max) max = num3;

	// Вычисление суммы квадратов двух меньших чисел
	int sum_of_squares = pow(num1, 2) + pow(num2, 2) + pow(num3, 2) - pow(max, 2);

	// Проверка условия по теореме Пифагора
	if (sum_of_squares == pow(max, 2))
		cout << "Да, они могут представлять стороны прямоугольного треугольика\n";
	else cout << "Нет, они не могут представлять стороны прямоугольного треугольника\n";

	return 0;
}
