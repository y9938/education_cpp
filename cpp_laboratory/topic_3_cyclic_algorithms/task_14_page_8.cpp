#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, p = 1;
	int n, factorial = 1;

	cout << "Enter n and x: ";
	cin >> n >> x;

	for (int k = 1; k <= n; ++k) {
		factorial *= k;
		p *= 1 + sin(k * x) / factorial;
	}
	cout << "product: " << p;
}
