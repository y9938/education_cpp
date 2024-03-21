#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int D[SIZE][SIZE] = {};
	
	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> D[i][j];
		}
	}

	int max = abs(D[0][0]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (abs(D[i][j]) > max)
			{
				max = abs(D[i][j]);
			}
		}
	}

	cout << "Max abs: " << max << endl;
}
