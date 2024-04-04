#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	cout << "Enter x, y \n";
	cin >> x >> y;
	z = x;
	x = y;
	y = z;
	cout << "X = " << x << '\n' << "Y = " << y;
}
