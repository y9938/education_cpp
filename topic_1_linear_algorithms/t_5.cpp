#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, s, v;
	cout << "Enter a \n";
	cin >> a;
	v = pow(a, 3);
	s = 4 * pow(a, 2);
	cout << "Volume = " << v << '\n';
	cout << "Lateral Surface Area = " << s;
}
