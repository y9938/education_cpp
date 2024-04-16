#include <iostream>
using namespace std;

int main()
{
    int a[100] = {3, 8, 7, 2, 3};
    int b[100] = {};
    int n = 5;
    int key;
    cout<<"Key = ";
    cin>> key;
    int i, nom = -1;
    for(i = 0; i < n; ++i)
        if(a[i] == key) b[++nom] = i;
    if(nom !=-1)
    {
        cout<<"\nnom = ";
        for(i = 0; i <= nom; ++i) cout<<b[i]<<" ";
    }
    else
        cout<<"\nthere is no such element! ";
    cout << endl;
}
