#include <iostream>
#include <cmath>

using namespace std;

void one(double x, double y, double R) {
    bool is_in = ((x >= 0 && sqrt(x * x + y * y) <= R) ||
                  (x <= 0 && y <= x && y >= -R) ||
                  (x <= 0 && y >= -x && y <= R));
    cout << is_in << endl;
}

void two(double x, double y, double R) {
    ((x >= 0 && sqrt(x * x + y * y) <= R) ||
     (x <= 0 && y <= x && y >= -R) ||
     (x <= 0 && y >= -x && y <= R)) ?
        cout << "Точка попадает в область\n" :
        cout << "Точка не попадает в область\n";
}

void three(double x, double y, double R) {
    if ((x >= 0 && sqrt(x * x + y * y) <= R) ||
        (x <= 0 && y <= x && y >= -R) || // 3 четверть
        (x <= 0 && y >= -x && y <= R)) // 2 четверть
        cout << "Точка попадает в область\n";
    else
        cout << "Точка не попадает в область\n";
}

int main() {
    double x, y, R;
    cout << "Введите координаты точки и радиус: ";
    cin >> x >> y >> R;

    cout << "Без разветвления: ";
    one(x, y, R);

    cout << "С условной операцией: ";
    two(x, y, R);

    cout << "С ветвлением: ";
    three(x, y, R);
}
