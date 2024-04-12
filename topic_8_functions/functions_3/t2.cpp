/*
 * Найти сумму цифр целого числа, вводимого с клавиатуры. Суммирование должно осуществляться
 * рекурсивной функцией.
*/

#include <iostream>

using namespace std;

int f(int n);

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Sum of digit in number: " << f(n) << "\n";
    return 0;
}

int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + f(n / 10);
    }
}
