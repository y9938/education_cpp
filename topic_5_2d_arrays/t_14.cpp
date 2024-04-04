#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 20;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int X[SIZE][SIZE] = {};

	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> X[i][j];
		}
	}
	
	int min = X[0][0], Jmin = 0;
	int max = X[0][0], Jmax = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (X[i][j] < min)
			{
				min = X[i][j];
				Jmin = j;
			}

			if (X[i][j] > max)
			{
				max = X[i][j];
				Jmax = j;
			}
		}
	}

	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = X[i][Jmin];
		X[i][Jmin] = X[i][Jmax];
		X[i][Jmax] = temp;
	}

	cout << "Output:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << X[i][j] << " ";
		}
		cout << endl;
	}
}
