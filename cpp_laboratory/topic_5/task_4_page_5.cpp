#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int C[SIZE][SIZE] = {};
	int T[SIZE] = {};

	int index = 0;

	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> C[i][j];

			if (i == j)
			{
				T[index++] = C[i][j];
			}

			if (j == n - 1 - i)
			{
				T[index++] = C[i][j];
			}
		}
	}

	cout << "Array T with main and side of diagonal: ";
	for (int i = 0; i < index; i++)
	{
		cout << T[i] << " ";
	}
}
