#include <iostream>
using namespace std;

int main() 
{
    int k;
    cout << "Введите k = ";
    cin >> k;

    if (k / 1000 != 0 || k / 100 == 0)
        cout << "Число не трехзначное\n";
    else {
        int d1 = k / 100;
        int d2 = (k / 10) % 10;
        int d3 = k % 10;

        if (d1 == 5 || d2 == 5 || d3 == 5) cout << "В числе есть цифра 5\n";
        else cout << "В числе нету цифры 5\n";
    }
}
