#include <iostream>
using namespace std;

int main() 
{
	int k, m, n;
	cout << "Введите 3 числа: ";
	cin >> k >> m >> n;
	if (k % 2 + m % 2 + n % 2 == 0) cout << "3 числа четные";
	else cout << "Условие не выполненено";
}
