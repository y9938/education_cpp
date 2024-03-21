#include <iostream>
using namespace std;

int main()
{
	const int n = 6;
	const int m = 7;
	int a[n][m] = {};

	cout << "Enter:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = i + j;
			if (sum % 2 == 0 && a[i][j] > 0)
			{
				a[i][j] = 0;
			}
		}
	}

	cout << "Finish:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
