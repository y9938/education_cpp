/*
 * Поменять местами максимальный и минимальный элементы матрицы.
*/

#include <iostream>

using namespace std;

const int n = 2;

void inputMatrix(int m[n][n]);
void printMatrix(int m[n][n]);
void max_min(int m[n][n]);

int main()
{
    int matr[n][n];
    cout << "Enter matrix " << n << " x " << n << "\n";
    inputMatrix(matr);

    max_min(matr);
    cout << "result:\n";
    printMatrix(matr);
}

void inputMatrix(int m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
}

void printMatrix(int m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

void max_min(int m[n][n])
{
    int max = m[0][0], min = m[0][0];
    int I_max = 0, J_max = 0, I_min = 0 , J_min = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max > m[i][j])
            { 
                max = m[i][j];
                I_max = i;
                J_max = j;
            }
            if (min < m[i][j])
            {
                min = m[i][j];
                I_min = i;
                J_min = j;
            }
        }
    }
    m[I_max][J_max] = min;
    m[I_min][J_min] = max;
}
