/*
 * Поменять местами максимальный и минимальный элементы матрицы.
*/

#include <stdio.h>

const int n = 2;

void inputMatrix(int m[n][n]);
void printMatrix(int m[n][n]);
void max_min(int m[n][n]);

int main()
{
    int matr[n][n];
    printf("Enter matrix %d x %d: \n", n, n);
    inputMatrix(matr);

    max_min(matr);
    printf("result:\n");
    printMatrix(matr);
}

void inputMatrix(int m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

void printMatrix(int m[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void max_min(int m[n][n])
{
    int max = m[0][0], min = m[0][0];
    int I_max, J_max, I_min, J_min;
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
    int k = m[I_max][J_max];
    m[I_max][J_max] = m[I_min][J_min];
    m[I_min][J_min] = k;
}
