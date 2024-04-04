#include <iostream>
using namespace std;

int main()
{
	double p, old1, old2, new1, new2;
	cout << "Enter p, old1, old2 \n";
	cin >> p >> old1 >> old2;
	new1 = old1 + (old1 * p / 100);
	new2 = old2 + (old2 * p / 100);
	cout << "Старая цена " << old1 << ", " << old2 << '\n' << "Новая цена " << new1 << ", " << new2;
}
