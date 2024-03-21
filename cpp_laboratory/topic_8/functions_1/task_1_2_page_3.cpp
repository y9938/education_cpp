/* 
 * Написать функцию, которая проверяет упорядочен ли массив по возрастанию.
*/

#include <stdio.h>

int asc_ord(int a[], int n);

int main()
{
    const int n = 2;

    int ar[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    printf("Function return: %d\n", asc_ord(ar, n));
}

int asc_ord(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i+1])
        {
            return 1;
        }
    }
    return 0;
}
