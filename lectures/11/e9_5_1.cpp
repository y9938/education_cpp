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
    while ((l <= r) && !Found)
    // цикл, пока интервал поиска не
    // сузиться до 0
    {
        s = (l + r) / 2;
        // середина интервала
        if (a[s] == key)
            Found = true;
            // ключ найден
        else if (a[s] < key)
            l = s + 1;
            // поиск в правом подинтервале
        else
            r = s - 1;
            // поиск в левом подинтервале
    }
    if (Found == true) cout << "Элемент найден на позиции " << s + 1 << "\n";
    else cout << "Элемент не найден!\n";
}
