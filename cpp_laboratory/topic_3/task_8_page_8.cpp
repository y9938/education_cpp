#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x;
	cout << "Enter x: ";
	cin >> x;

	double y = 0.0;
	int factorial = 1, sign = 1;

	for (int i = 3; i <= 13; i += 2)
	{
		factorial *= (i - 1) * i;

		if(sign % 2 == 0)
			y += pow(x, i) / factorial;
		else
			y -= pow(x, i) / factorial;
		sign++;
	}

	cout << "y: " << y;
}
