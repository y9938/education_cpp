#include <iostream>
#include <iomanip>

const int n = 3;
const int m = 2;

void printMatrix(int arr[n][m]) {
	std::cout << "Elements of the " << n << "x" << m << " array:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	int matrix[n][m] = {
		{-1,2},
		{4,5},
		{7,-9}
	};

	printMatrix(matrix);

	int New[n];

	for (int i = 0; i < n; ++i) {
		New[i] = 0;
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] < 0) {
				New[i]++;
			}
		}
	}

	std::cout << "Negatives in rows: ";
	for (int i = 0; i < n; ++i) {
		std::cout << New[i] << " ";
	}
	
	return 0;
}
