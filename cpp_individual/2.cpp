// Без использования разветвляющейся структуры
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, R;
	cout << "Введите координаты точки и радиус: ";
	cin >> x >> y >> R;

	bool is_in_region(x >= 0 && sqrt(x * x + y * y) <= R ||
		x <= 0 && y <= x && y >= -R ||
		x <= 0 && y >= -x && y <= R);
	cout << is_in_region << endl;
}

// С использованием условной операции
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, R;
	cout << "Введите координаты точки и радиус: ";
	cin >> x >> y >> R;

	(x >= 0 && sqrt(x * x + y * y) <= R ||
		x <= 0 && y <= x && y >= -R ||
		x <= 0 && y >= -x && y <= R) ?
		cout << "Точка попадает в область\n" :
		cout << "Точка не попадает в область\n";
}

// С использованием оператора ветвления
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y, R;
	cout << "Введите координаты точки и радиус: ";
	cin >> x >> y >> R;

	if (x >= 0 && sqrt(x * x + y * y) <= R ||
		x <= 0 && y <= x && y >= -R || // 3 четверть
		x <= 0 && y >= -x && y <= R) // 2 четверть
		cout << "Точка попадает в область\n";
	else
		cout << "Точка не попадает в область\n";
}
