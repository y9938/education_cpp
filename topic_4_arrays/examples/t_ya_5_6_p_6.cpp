#include <iostream>
using namespace std;

int main() {
	int n, i;
	cout << "Enter the number of elements in the arrays (below 20): ";
	cin >> n;

	char a[20] = {};
	char b[20] = {};

	cout << "Enter the elements of array a:\n";
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int j = 0;
	for (i = 0; i < n; i++) {
		if (a[i] != '*') {
			b[j] = a[i];
			j++;
		}
	}

	cout << "Final array b:\n";
	for (i = 0; i < j; i++) {
		cout << b[i] << " ";
	}
}
