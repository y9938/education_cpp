/*
 Даны длины сторон треугольника, определить вид треугольника и его площадь.
 Выполнить контроль вводимых чисел. 
 Разносторонний треугольник, Равнобедренный треугольник, Равносторонний треугольник.
*/

#include <iostream>
#include <cmath>

using namespace std;

bool is_valid_triangle(double a, double b, double c);
void classify_triangle(double a, double b, double c);
double calculate_area(double a, double b, double c);

int main()
{
    double a, b, c;
    cout << "Enter the lengths of the triangle's sides (a,b,c): ";
    if (cin >> a >> b >> c)
    {
        if (is_valid_triangle(a,b,c))
        {
            classify_triangle(a,b,c);
            cout << "The area of the triangle: " << calculate_area(a, b, c) << endl;
        }
        else
        {
            cout << "The entered numbers cannot be the sides of a triangle." << endl;
        }
    }
    else
    {
        cout << "Input error: non-numeric values entered." << endl;
    }

    return 0;
}

// Функция для проверки, могут ли числа быть сторонами треугольника
bool is_valid_triangle(double a, double b, double c)
{
    return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (c + b > a);
}

// Функция для определения вида треугольника
void classify_triangle(double a, double b, double c)
{
    if (a == b && b == c)
    {
        cout << "Equilateral triangle" << endl;
    }
    else if (a == b || a == c || b == c)
    {
        cout << "Isosceles triangle" << endl;
    }
    else
    {
        cout << "Scalene triangle" << endl;
    }
}

// Функция для вычисления площади треугольника по формуле Герона
double calculate_area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
