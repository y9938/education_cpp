#include <iostream>
#include <iomanip>

const int n = 4;

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
		{1,2,2,1},
		{3,3,3,3},
		{7,8,2,1}
	};

	printMatrix(matrix);

	std::cout << "Palindrome Rows: ";
	for (int i = 0; i < n; ++i) {
		bool isPalindrome = true;
		for (int j = 0; j < n / 2; ++j) {
			if (matrix[i][j] != matrix[i][n - 1 - j]) {
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome) {
			std::cout << i << " ";
		}
	}
	
	return 0;
}
