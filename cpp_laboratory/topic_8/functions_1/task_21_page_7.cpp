/*
 * Даны две матрицы А(6,4), В(3,5). Напечатать ту матрицу, у которой произведение максимального и
 * минимального элементов наибольшее
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void fillM(int a[][5], int n, int m);
void printMatrix(int a[][5], int n, int m);
int maxMinProduct(int a[][5], int n, int m, char matrixName);

int main() {
    const int nA = 6;
    const int mA = 4;
    const int nB = 3;
    const int mB = 5;
    
    int A[nA][5];
    int B[nB][5];

    fillM(A, nA, mA);
    fillM(B, nB, mB);
    
    printMatrix(A, nA, mA);
    printMatrix(B, nB, mB);
    
    int productA = maxMinProduct(A, nA, mA, 'A');
    int productB = maxMinProduct(B, nB, mB, 'B');

    cout << "Матрица с наибольшим произведением максимального и минимального элементов: ";
    if (productA > productB) 
    {
        cout << "A\n";
    } 
    else if (productB > productA) 
    {
        cout << "B\n";
    } 
    else 
    {
        cout << "Произведения максимального и минимального элементов матриц A и B равны.\n";
    }

    return 0;
}

// Функция для заполнения матрицы случайными числами от 0 до 49
void fillM(int a[][5], int n, int m) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            a[i][j] = rand() % 50;
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int a[][5], int n, int m) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для нахождения максимального и минимального элементов и их произведения
int maxMinProduct(int a[][5], int n, int m, char matrixName) 
{
    int max = a[0][0];
    int min = a[0][0];
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (a[i][j] > max) max = a[i][j];
            if (a[i][j] < min) min = a[i][j];
        }
    }
    cout << "Матрица " << matrixName << " - Максимальное знач.: " << max << ", Минимальное знач.: " << min << endl;
    return max * min;
}
