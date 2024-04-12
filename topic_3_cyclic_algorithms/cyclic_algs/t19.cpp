#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double y = 0.0;

	for (int i = 99; i >= 3; i -= 3) {
		y = sqrt(i + y);
	}

	cout << "y: " << y;
	return 0;
}
