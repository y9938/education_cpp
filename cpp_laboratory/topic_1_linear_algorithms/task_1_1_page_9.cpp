#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Объявление переменных
	double a, b, c, p, t, ha, hb, hc;

	// Ввод с клавиатуры значения сторон
	cout << "Enter a, b, c \n";
	cin >> a >> b >> c;

	// Вычисление полупериметра
	p = (a + b + c) / 2;

	// Вычисление площади треугольника по формуле Герона
	t = 2 * sqrt(p * (p - a) * (p - b) * (p - c));

	// Вычисление высот треугольника
	ha = t / a;
	hb = t / b;
	hc = t / c;

	// Вывод результатов
	cout << "\n" << " ha = " << ha;
	cout << "\n" << " hb = " << hb;
	cout << "\n" << " hc = " << hc;
}
