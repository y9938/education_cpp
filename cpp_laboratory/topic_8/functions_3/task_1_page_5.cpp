/*
 * Вывести на экран в порядке возрастания все четные числа из диапазона, границы которого вводятся
 * с клавиатуры. Границы могут вводиться в произвольном порядке. Вывод должен осуществляться
 * рекурсивной функцией.
*/

#include <iostream>

using namespace std;

void g(int a, int b);

int main()
{
    int a, b;
    cout << "Enter the range boundaries: ";
    cin >> a >> b;

    if (a > b)
    {
        int k = a;
        a = b;
        b = k;
    }
    
    if (a % 2 != 0)
    {
        a++;
    }
    
    g(a, b);
    cout << "\n";
}

void g(int a, int b)
{
    if (a > b)
    {
        return;
    }

    cout << a << " ";

    g(a + 2, b);
}
