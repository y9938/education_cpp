#include <iostream>
using namespace std;

int main()
{
	const int N = 30;

	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int A[N][N] = {};

	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	
	// Отражение матрицы относительно главной диагонали
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}

	cout << "Reflected matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	// Поиск строк с возрастающей последовательностью
	cout << "Rows with increasing sequence:\n";
	for (int i = 0; i < n; i++)
	{
		bool increasing = true;
		
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] <= A[i][j - 1])
			{
				increasing = false;
				break;
			}
		}

		if (increasing)
		{
			for (int j = 0; j < n; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}
}
