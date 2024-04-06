/*
 Даны длины сторон треугольника, определить вид треугольника и его площадь. 
 Выполнить контроль вводимых чисел.
 Остроугольный треугольник, Тупоугольный треугольник, Прямоугольный треугольник.
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
    cin >> a >> b >> c;

    if (!is_valid_triangle(a, b, c))
    {
        cout << "The entered numbers cannot form a valid triangle." << endl;
        return 1;
    }

    classify_triangle(a, b, c);
    cout << "The area of the triangle: " << calculate_area(a, b, c) << endl;

    return 0;
}

bool is_valid_triangle(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0 && b > 0 && c > 0);
}

void classify_triangle(double a, double b, double c)
{
    if (c*c == a*a + b*b)
    {
        cout << "Right-angled triangle" << endl;
    }
    else if (c*c < a*a + b*b)
    {
        cout << "Acute-angled triangle" << endl;
    } 
    else 
    {
        cout << "Obtuse-angled triangle" << endl;
    }
}

double calculate_area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
