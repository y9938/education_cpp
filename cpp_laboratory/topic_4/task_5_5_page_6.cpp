#include <iostream>
using namespace std;

int main() {
	int n, i;
	cout << "Enter the number of elements in the array (below 20): ";
	cin >> n;

	int a[20] = {};
	int b[20] = {};
	int c[20] = {};

	cout << "Enter the elements of array a:\n";
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter the elements of array b:\n";
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}

	cout << "The result of adding elements of arrays a and b (c[]):\n";
	for (i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}
}
