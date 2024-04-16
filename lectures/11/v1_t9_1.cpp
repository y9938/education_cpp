#include <iostream>
using namespace std;

int main()
{
    int a[100] = {3, 8, 7, 2, 1};
    int n = 5;
    int key;
    cout<<"Key = ";
    cin>> key;
    int i, nom=-1;
    for(i=0; i<n; i++)
        if(a[i]== key){nom=i; break;}
    if(nom !=-1)
        cout<<"\nnom="<<nom+1;
    else
        cout<<"\nthere is no such element! ";
    cout << endl;
}
