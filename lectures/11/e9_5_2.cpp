#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n, I;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array: ";
    for (I = 0; I < n; I++) cin >> a[I];
    int key;
    cout<<"Key = ";
    cin>> key;
    int l = 0, r = n - 1, s;
    bool Found = false;
    // флаг
    do
    {
        s = (l + r) / 2;
        //найти средний элемент
        if (a[s] < key) l = s + 1;
        //перенести левую границу
        else r = s;
        //перенести правую границу
    }
    while (l != r);
    if (a[l] == key) cout<< "Элемент найден на позиции "<< l + 1<< " \n";
    else cout << "Элемент не найден!\n";
}
