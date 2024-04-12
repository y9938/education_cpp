#include <iostream>
using namespace std;

int main()
{
	const int n = 2;
	const int m = 4;

	int x;
	cout << "Enter the real number: ";
	cin >> x;

	int Z[n][m] = {};
	int New[n] = {};

	cout << "Enter the elements of the matrix (2 x 4):\n";
	for (int i = 0; i < n; i++)
	{
		bool line = true;
		
		for (int j = 0; j < m; j++)
		{
			cin >> Z[i][j];

			if (Z[i][j] > x)
			{
				line = false;
				break;
			}
		}

		if (!line)
		{
			New[i] = 0;
		}
		else
		{
			New[i] = 1;
		}
	}

	cout << "Output:\n";
	for (int i = 0; i < n; i++)
	{
		cout << New[i] << " ";
	}
	cout << endl;
}
