#include <iostream>
using namespace std;

int main() 
{
	int x, y;
	cout << "Введите координаты точки: ";
	cin >> x >> y;

	if (x == 0 && y == 0) cout << "В начале координат";
	else if (x > 0 && y > 0) cout << "1 четверть";
	else if (x < 0 && y > 0) cout << "2 четверть";
	else if (x < 0 && y < 0)cout << "3 четверть";
	else if (x > 0 && y < 0) cout << "4 четверть";
	else if (x == 0) cout << "На оси x";
	else cout << "На оси y";
}
