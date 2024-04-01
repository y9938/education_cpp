#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 25;

	int m, n;
	cout << "Enter the size of the matrix (m x n): ";
	cin >> m >> n;
	
	int Y[SIZE][SIZE] = {};

	cout << "Enter the elements of matrix:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Y[i][j];
		}
	}
	
	cout << "Non-zero elements:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Y[i][j] != 0)
			{
				cout << "Index: " << i << " " << j << endl;
			}
		}
	}
}
