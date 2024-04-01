#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int xA, yA, xB, yB, xC, yC;

	cout << "Enter xA, yA, xB, yB, xC, yC \n";
	cin >> xA >> yA >> xB >> yB >> xC >> yC;

	// Вычисление длин сторон треугольника
	double c = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2)); // AB
	double a = sqrt(pow(xC - xB, 2) + pow(yC - yB, 2)); // BC
	double b = sqrt(pow(xA - xC, 2) + pow(yA - yC, 2)); // СA

	// Вычисление полупериметра и площади треугольника
	double p = (a + b + c) / 2; // Полупериметр
	double s = sqrt(p * (p - a) * (p - b) * (p - c)); // Площадь

	// Вычисление биссектрисы и радиуса описанной окружности
	double W = (2 * sqrt(b * c * p * (p - a))) / (b + c); // Биссектриса
	double R = a * b * c / (4 * s); // Радиус описанной окружности

	// Вывод результатов
	cout << "Биссектриса = " << W << "\n" << "Радиус описаной окружности = " << R << "\n";
}
