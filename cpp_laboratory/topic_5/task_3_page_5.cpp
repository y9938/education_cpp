#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int B[SIZE][SIZE] = {};
	int New[SIZE][SIZE] = {};

	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j) {
				New[i][j] = B[i][j] / 2;
			}
			else
			{
				New[i][j] = pow(B[i][j], 2);
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
