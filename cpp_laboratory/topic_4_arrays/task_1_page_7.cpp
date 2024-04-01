#include <iostream>

using namespace std;

int main() {
	const int size = 20;
	int n[size];
	int x[size];
	double numerator = 0;
	double denominator = 0;

	for (int i = 0; i < size; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < size; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < size; i++) {
		numerator += n[i] * x[i];
		denominator += n[i];
	}

	double t = numerator / denominator;

	if (denominator != 0) {
		cout << "Согласно формуле: " << t;
	}
	else
		cerr << "Ошибка. Происходит деление на 0.";

	return 0;
}
