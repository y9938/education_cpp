#include <iostream>
using namespace std;

int main() {
	int n; 
	cout << "Enter the number of elements in the array (below 50): ";
	cin >> n;

	char s[50] = {};

	cout << "Enter the elements of the array:\n";
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	bool k = false;
	for (int i = 0; i < n; i++) {
		if (k) {
			s[i] = '-';
		}
		else {
			if (s[i] == '*') {
				k = true;
			}
		}
	}

	cout << "Final array:\n";
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
}
