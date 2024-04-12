/* 
 * Написать функцию, которая проверяет упорядочен ли массив по возрастанию.
*/

#include <iostream>

using namespace std;

void asc_ord(int a[], int n);

int main()
{
    const int n = 2;

    int ar[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    asc_ord(ar, n);
}

void asc_ord(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i+1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
