#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    double x, y, z;
    cout << "Введите 3 числа: ";
    cin >> x >> y >> z;

    double a = sqrt(x + y + z);
    double b = 1.5 * x * y * z;
    double c = 0.1 * x * y / z;

    cout << a << ", " << b << ", " << c << endl;

    double min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;

    cout << "min = " << min;
}
