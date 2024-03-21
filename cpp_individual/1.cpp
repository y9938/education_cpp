#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");

	const double m1 = 3.177, m2 = 8.392, v = -6.613, f = 0.599;

	double numerator = -f * (m1 + m2) - m1 * m2 * pow(v, 2);
	double denominator = (1 - pow(m1, 2) * pow(v, 2)) * (1 + pow(m2, 2) * pow(v, 2)) - (m1 + m2 / m1);
	double m = numerator / denominator;

	printf("�������� ������:\n");
	printf(" m1: %g\n m2: %g\n v: %g\n f: %g\n", m1, m2, v, f);
	printf("\n��������� �����: %.5f\n����������� �����: %.2f\n", numerator, denominator);
	printf("\n��������� ����������: \n m: %.12f\n", m);
}
