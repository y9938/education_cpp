#include <iostream>
using namespace std;

int search(int *k, int n, int key)
{
    int nom = -1;int temp;
    for(int i=0; i<n; i++)
    {
        if(k[i] == key)
        {
            nom = i;
            temp = k[i];
            k[i] = k[0];
            k[0] = temp;
            break;
        }
    }
    return(nom);
}

int main()
{
    int a[100] = {3, 8, 7, 2, 3};
    int n = 5;
    int key;
    cout<<"Key = ";
    cin>> key;
    int nom = search(a, n, key);
    if(nom != -1)
    {
        cout<<"\nnom = "<<nom;
    }
    else
        cout<<"\nthere is no such element! ";
    cout << endl;
}
