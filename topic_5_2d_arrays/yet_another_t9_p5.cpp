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
	for (int j = 0; j < n; j++)
	{
		New[j] = 1;

		for (int i = 1; i < n; i++)
		{
			if (Z[i][j] <= Z[i - 1][j])
			{
				New[j] = 0;
				break;
			}
		}
		cout << New[j] << " ";
	}
	cout << endl;
}
