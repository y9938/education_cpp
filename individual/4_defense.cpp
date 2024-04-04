#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    const int MAX_SIZE = 25;

    int n;
    cout << "Enter the number of elements in the array (up to " << MAX_SIZE << "): ";
    cin >> n;
    
    double A[MAX_SIZE] = {};
    double ya[MAX_SIZE/2] = {};

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }

    bool k = false;
    for (int i = 0; i < n; i++) 
    {
        if (A[i] < -2) 
        {
            k = true;
            break;
        }
    }

    int yaIndex = 0;
    for (int i = 0; i < n; i++) 
    {
        if (k && A[i] < 0) 
        {
            A[i] = abs(A[i]);
        }
        else 
        {
            if (!k) 
            {
                A[i] *= 0.1;
            }
        }
        if (i % 2 == 1)
        {
            ya[yaIndex++] = A[i];
        }
    }

    cout << "Final array:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << A[i] << endl;
    }

    cout << "ya array:\n";
    for (int i = 0; i < n/2; i++)
    {
        cout << ya[i] << endl;
    }

    return 0;
}
