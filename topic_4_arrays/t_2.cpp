#include <iostream>

using namespace std;

int main() {
	const int size = 4;
	int n = 0;
	int a[size];

	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	cout<<"Новая четная последовательность"<<endl;
	for (int i = 0; i < size; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << endl;
		}
	}

	return 0;
}
