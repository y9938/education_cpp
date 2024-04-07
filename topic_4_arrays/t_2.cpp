#include <iostream>

using namespace std;

int main() {
	const int n = 4;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout<<"Новая четная последовательность"<<endl;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << endl;
		}
	}

	return 0;
}
