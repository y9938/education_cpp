#include <iostream>
using namespace std;

int main()
{
    int a[100] = {3, 8, 7, 2, 1};
    int n = 5;
    int key;
    cout<<"Key = ";
    cin>> key;
    int i = 0;
    while ( (i < n) && (a[i] != key) )
        i++;
    if (i==n)
        cout<<"\nthere is no such element!";
    else
        cout<<"\nnom="<<i+1;
    cout << endl;
}
