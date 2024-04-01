#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cout << "Enter the number of elements in the array (below 50): ";
	cin >> n;

	int a[50] = {};

	cout << "Enter the elements of the array:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int max = abs(a[0]);
	for (int i = 1; i < n; i++) {
		if (abs(a[i]) > max) {
			max = abs(a[i]);
		}
	}
	
	cout << "Final array:\n";
	for (int i = 0; i < n; i++) {
		if (abs(a[i]) == max) {
			a[i] = 1;
		}
		else {
			a[i] = 0;
		}
		cout << a[i] << endl;
	}
}
