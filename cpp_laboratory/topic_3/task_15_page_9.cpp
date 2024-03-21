#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double y = 0;
	int n;

	cout << "Enter n: ";
	cin >> n;

	for (int x = 1; x <= n; x+=0.1) {
		y = pow(x, 2) - 3 * x + 2 / sqrt(2 * pow(x, 3) - 1);
	}
	cout << "result: " << y;
}
