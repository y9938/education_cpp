/*
Создать структуру Треугольник с тремя элементами 
a, b, c – длины 3-х сторон. Для N заданных треугольников
найти: k1 – количество равносторонних треугольников и 
k2 – количество прямоугольных треугольников.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct triangle
{
    double a, b, c;
};

bool is_triangle(double a, double b, double c)
{
    return (a + b > c && b + c > a && c + a > b);
}

int classify_triang(double a, double b, double c)
{
    if (a == b && b == c) return 1;
    if (c*c == a*a + b*b || a*a == b*b + c*c || b*b == a*a + c*c) return 2;
    return 3;
}

int main()
{
    triangle t;
    int equilateral_c = 0, right_angled_c = 0, other_c = 0;

    ifstream input_file("../io_files/10_input.txt");
    while (input_file >> t.a >> t.b >> t.c)
    {
        if (is_triangle(t.a, t.b, t.c))
        {
            switch (classify_triang(t.a, t.b, t.c))
            {
                case 1:
                    ++equilateral_c;
                    break;
                case 2:
                    ++right_angled_c;
                    break;
                case 3:
                    ++other_c;
                    break;
            }
        }
    }
    cout << "Number of equilateral triangles: " << equilateral_c << endl;
    cout << "Number of right-angled triangles: " << right_angled_c << endl;
    cout << "Number of other types of triangles: " << other_c << endl;
}
