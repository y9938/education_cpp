#include <iostream>
using namespace std;

int main()
{
	double a, b, c, k;
	cout << "Enter a, b, c \n";
	cin >> a >> b >> c;
	k = c / (a * b) + (a * b) / c;
	cout << "c/a*b + a*b/c = " << k;
}
