#include <iostream>
#include <random>
using namespace std;

int main()
{
	int W[6][9] = {};

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(-100, 100);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			W[i][j] = dis(gen);
		}
	}

	// Matrix output
	for (int i = 0; i < 6; i++)
	{
		cout << "|";
		for (int j = 0; j < 9; j++)
		{
			cout.width(4);
			cout << W[i][j] << " ";
		}
		cout << "|" << endl;
	}
	
	double max = W[0][0];
	double min = W[0][0];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (W[i][j] < min)
			{
				min = W[i][j];
			}

			if (W[i][j] > max)
			{
				max = W[i][j];
			}
		}
	}
	cout << "Min: " << min << "\nMax: " << max << endl;

	double arithmetic_mean = (min + max) / 2.0;
	cout << "Arithmetic mean: " << arithmetic_mean << endl;
}
