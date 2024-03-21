#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter the number of elements in the array (below 50): ";
	cin >> n;

	double a[50] = {};
	
	cout << "Enter the elements of the array:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int count = 0;
	for (int k = 1; k < n - 1; k++) {
		if (a[k] < (a[k - 1] + a[k + 1]) / 2) {
			count++;
		}
	}

	cout << "Numbers of elements satisfying condition: " << count << endl;
}
