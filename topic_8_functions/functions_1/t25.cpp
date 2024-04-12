/*
 * Даны две матрицы С(8,6) и D(7,5). Для каждой матрицы сформировать массивы из средних
 * арифметических значений элементов нечетных строк.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int maxJ = 6;

void fillM(int a[][maxJ], int I, int J);
void printMatrix(int a[][maxJ], int I, int J);
void oddRowsAverage(int a[][maxJ], int I, int J, int b[][1]);
void printResult(char j, int a[][1]);

int main() 
{
    const int iA = 8, jA = 6;
    const int iB = 7, jB = 5;
    
    int A[iA][maxJ];
    int B[iB][maxJ];
    
    fillM(A, iA, jA);
    fillM(B, iB, jB);
    
    printMatrix(A, iA, jA);
    printMatrix(B, iB, jB);
    
    int C[iA/2][1], D[iB/2][1];
    
    oddRowsAverage(A, iA, jA, C);
    oddRowsAverage(B, iB, jB, D);
    
    printResult('A', C);
    printResult('B', D);
    
    return 0;
}

void oddRowsAverage(int a[][maxJ], int I, int J, int b[][1])
{
    int sum = 0;
    int count = 0;
    int k = 0;
    for(int i=1; i<I; i+=2)
    {
        sum = 0;
        count = 0;
        for(int j=0; j<J; j++)
        {
            sum += a[i][j];
            count++;
        }
        b[k++][0] = sum / count;
    }
}

// Функция для заполнения матрицы случайными числами от 0 до 49
void fillM(int a[][maxJ], int I, int J)
{
    for (int i = 0; i < I; ++i) 
    {
        for (int j = 0; j < J; ++j) 
        {
            a[i][j] = rand() % 50;
        }
    }
}

// Функция для вывода результата задачи
void printResult(char j, int a[][1])
{
    cout<<"Average of odd rows in Matrix "<<j<<":"<<endl;
    for(int i=0; i<4; ++i)
    {
        cout<<setw(5)<<a[i][0]<<" ";
    }
    cout<<endl;
}

// Функция для вывода матрицы
void printMatrix(int a[][maxJ], int I, int J)
{
    cout<<"Matrix:\n";
    // Выводим верхнюю границу матрицы
    cout << "      " << string(J * 5, '-') << endl;
    
    for (int i = 0; i < I; ++i) 
    {
        // Выводим * для нечетных строк и пробел для четных строк перед номером строки
        cout << (i % 2 != 0 ? "*" : " ") << setw(3) << i << " |";
    
        // Выводим элементы матрицы
        for (int j = 0; j < J; ++j)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << "|" << endl; // Закрываем строку границей справа
    }
    
    // Выводим нижнюю границу матрицы
    cout << "      " << string(J * 5, '-') << "\n\n";
}
