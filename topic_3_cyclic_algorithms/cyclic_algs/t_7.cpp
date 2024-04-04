#include <iostream>

using namespace std;

int main()
{
	double x;
	cout << "Enter x: ";
	cin >> x;

	double y = 1.0;

	for (int n = 2; n <= 64; n *= 2)
	{
		y *= (x - n) / (x - (n - 1));
	}

	cout << "y: " << y;
}
