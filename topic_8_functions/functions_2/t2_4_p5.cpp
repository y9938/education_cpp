/*
 * Транспонировать матрицу. Выполнить для целой и символьной матриц. Для ввода-
 * вывода матриц и транспонирования использовать шаблоны функции.
*/

#include <iostream>
using namespace std;

const int N = 50;

template <typename T>
void inputMatrix(T m[][N], int rows, int cols);

template <typename T>
void printMatrix(T m[][N], int rows, int cols);

template <typename T>
void transposeMatrix(T m[][N], T t[][N], int rows, int cols);

int main()
{
    int intMatrix[N][N], intTrans[N][N];
    char charMatrix[N][N], charTrans[N][N];
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    
    cout << "Enter the integer matrix: \n";
    inputMatrix(intMatrix, rows, cols);

    transposeMatrix(intMatrix, intTrans, rows, cols);

    cout << "Transposed integer matrix: \n";
    printMatrix(intTrans, cols, rows);

    cout << "Enter the character matrix: \n";
    inputMatrix(charMatrix, rows, cols);

    transposeMatrix(charMatrix, charTrans, rows, cols);

    cout << "Transposed character matrix: \n";
    printMatrix(charTrans, cols, rows);
}

template <typename T>
void inputMatrix(T m[][N], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> m[i][j];
        }
    }
}

template <typename T>
void printMatrix(T m[][N], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void transposeMatrix(T m[][N], T t[][N], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            t[j][i] = m[i][j];
        }
    }
}
