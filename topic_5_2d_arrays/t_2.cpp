#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	double A[SIZE][SIZE] = {};
	double New[SIZE][SIZE] = {};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				New[i][j] = A[i][j] + 0.5;
			}
			else
			{
				New[i][j] = A[i][j] / 10;
			}
		}
	}

	cout << "Matrix output:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << New[i][j] << " ";
		}
		cout << endl;
	}
}
