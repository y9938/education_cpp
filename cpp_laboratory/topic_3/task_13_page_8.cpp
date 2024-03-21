#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double p = 1;
	
	for (int i = 1; i <= 52; ++i) {
		p *= pow(i, 2) / pow(i, 2) + 2 * i + 3;
	}
	cout << "product: " << p;
}
