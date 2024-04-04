/*
 * Даны целые массивы А(7), В(6), С(8). Определить, в каком массиве число элементов, значения которых
 * не превышают значение их последнего элемента, является наибольшим.
*/

#include <iostream>
using namespace std;

void inputA(int ar[], int s);
int define(int ar[], int s);

int main()
{
    const int a = 7, b = 6, c = 8;
    int A[a], B[b], C[c];

    cout << "Enter the array A, B, C: \n";
    inputA(A, a);
    inputA(B, b);
    inputA(C, c);

    cout << "Which array has the most elements with values not exceeding its last element's value?\n";
    int cA = define(A, a);
    int cB = define(B, b);
    int cC = define(C, c);
    if (cA > cB && cA > cC)
    {
        cout << "Answer: A: " << cA;
    }
    else if (cB > cA && cB > cC)
    {
        cout << "Answer: B: " << cB;
    }
    else if (cC > cA && cC > cB)
    {
        cout << "Answer: C: " << cC;
    }
    else
    {
        cout << "Tie.";
    }
    cout << "\n";
    return 0;
}

void inputA(int ar[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cin >> ar[i];
    }
}

int define(int ar[], int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        if (ar[i] < ar[s - 1])
        {
            count++;
        }
    }
    return count;
}
