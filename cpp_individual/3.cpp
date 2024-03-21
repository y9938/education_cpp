#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a = 6.13;
	double b = 3.22;
	int x_n = 2;
	int x_k = 7;
	double dx = 0.5;
	double x = x_n;

	double max_t = sqrt((a + x) / (cos(b + x) + 10)) * sin(a + pow(x, 3));
	int negative_count_x = 0;
	int iteration_count = 0;

	cout << " x\t t \n";
	while (x <= x_k) {
		double t = sqrt((a + x) / (cos(b + x) + 10)) * sin(a + pow(x, 3));

		if (x < 0) {
			negative_count_x++;
		}

		if (t > max_t) {
			max_t = t;
		}

		iteration_count++;
		if (iteration_count % 2 == 0) {
			cout << x << "\t" << t << "\n";
		}
		x += dx;
	}
	cout << "Количество отрицательных значений x: " << negative_count_x << endl;
	cout << "Максимальное значение t: " << max_t << endl;

	return 0;
}
