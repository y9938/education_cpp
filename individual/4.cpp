#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the number of elements in the array (up to 50): ";
    cin >> n;

    double A[50] = {};

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
    }

    cout << "Final array:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << A[i] << endl;
    }

    return 0;
}
