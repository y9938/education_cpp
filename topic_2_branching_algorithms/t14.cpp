#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int x, y, r1, r2;
    cout << "Введите координаты точки и r1, r2: ";
    cin >> x >> y >> r1 >> r2;

    if (x < 0 || y < 0 || r1 <= 0 || r2 <= 0) {
        cout << "Введенные значения должны быть положительными.\n";
        return 1;
    }

    // r1 должен быть меньше r2
    if (r2 < r1) {
        int temp = r1;
        r1 = r2;
        r2 = temp;
    }

    // Вычисляем расстояние
    int R = sqrt(pow(x, 2) + pow(y, 2));

    if (R > r1 && R < r2) cout << "Точка лежит в кольце.\n";
    else cout << "Точка не лежит в кольце.\n";

    return 0;
}
