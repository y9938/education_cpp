#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout << "x\t y(x)\n";
	
	for (double x = -10.0; x <= 10.0; x += 2.0) {
		double y;

		if (x > 5) {
			y = log(pow(x, 2) + 0.75) / (4 * pow(x, 2) + x);
		}
		else
			y = pow(x, 4) + 2 * pow(x, 2) * sin(x);

		cout << x << "\t " << y << "\n";
	}

	return 0;
}
