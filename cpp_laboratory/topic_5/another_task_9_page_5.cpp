#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix: ";
	cin >> n;

	int Z[SIZE][SIZE] = {};
	int New[SIZE] = {};

	cout << "Enter the elements of the matrix (n x n):\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Z[i][j];
		}
	}

	cout << "Output:\n";
	for (int i = 0; i < n; i++)
	{
		New[i] = 1;

		for (int j = 1; j < n; j++)
		{
			if (Z[i][j] <= Z[i][j - 1])
			{
				New[i] = 0;
				break;
			}
		}
		cout << New[i] << " ";
	}
	cout << endl;
}
