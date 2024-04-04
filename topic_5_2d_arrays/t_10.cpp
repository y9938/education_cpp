#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int SIZE = 30;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	double A[SIZE][SIZE] = {};

	int count = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			A[i][j] = sin(i + j / 2.0);

			if (A[i][j] > 0)
			{
				count++;
			}
		}
	}

	cout << "Completed matrix:\n";
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Count of positive elements: " << count << endl;
}
