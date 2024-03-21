/*
 * Переписать в массив из матрицы элементы кратные 2.
*/

#include <iostream>

using namespace std;

const int N = 2;

int p(int m[N][N], int ar[N*N])
{
    int k = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (m[i][j] % 2 == 0)
            {
                ar[k++] = m[i][j];
            }
        }
    }
    return k;
}

int main()
{
    int matrix[N][N];
    int array[N*N];

    cout << "Enter matrix " << N << " x " << N << ": " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int count = p(matrix, array);

    cout << "Result: ";
    for(int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
