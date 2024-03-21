#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, sum = 0;
	int n;

	cout << "Enter n and x: ";
	cin >> n >> x;

	for (int i = 1; i <= n; ++i) {
		sum += x + cos(i * x) / pow(2, i);
	}
	cout <<"sum: " << sum;
}
