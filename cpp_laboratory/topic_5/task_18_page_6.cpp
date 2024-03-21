#include <iostream>
#include <iomanip>

const int n = 3;
const int m = 2;

void printMatrix(int arr[n][m]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	int A[n][m] = {
		{-22,2},
		{2,-3},
		{-11,1}
	};

	std::cout << "Elements of the " << n << "x" << m << " array:\n";
	printMatrix(A);

	for (int j = 0; j < m; ++j) {
		int minCol = A[0][j];
		int minRowIndex = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i][j] < minCol) {
				minCol = A[i][j];
				minRowIndex = i;
			}
			if (A[i][j] > 0) {
				sum += A[i][j];
			}
		}
		A[minRowIndex][j] = sum;
	}

	std::cout << "Array after replacing:\n";
	printMatrix(A);

	return 0;
}
