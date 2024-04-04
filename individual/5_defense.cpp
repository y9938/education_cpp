#include <iostream>
#include <iomanip>

const int n = 3;

void printMatrix(int arr[n][n]) {
	std::cout << "Elements of the " << n << "x" << n << " array:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	int matrix[n][n] = {
		{1,2,3},
		{4,3,2},
		{-1,-2,0}
	};

	printMatrix(matrix);

	int minRow[n];
	for (int i = 0; i < n; ++i)
	{
		minRow[i] = matrix[i][0];
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] < minRow[i])
			{
				minRow[i] = matrix[i][j];
			}
		}
		std::cout << "minRow: " << minRow[i] << std::endl;
	}

	return 0;
}
