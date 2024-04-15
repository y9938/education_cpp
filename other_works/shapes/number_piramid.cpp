/*
Получить елочку:
0
1 2
3 4 5
При вводе rows = 3
*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter the rows: ";
    cin >> rows;

    int current_number = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cout << current_number++ << " ";
        }
        cout << "\n";
    }
}
