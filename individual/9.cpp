/*
Среди всех слов файла найти слова,
представляющие собой целые числа.
Увеличить все эти числа на 1.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../9_input.txt");
    char ch;
    while (input_file.get(ch))
    {
        if (ch >= '0' && ch < '9') ch += 1;
        else if (ch == '9')
        {
            ch -= '0';
            ch += 1;
            string ten = to_string(ch);
            cout << ten;
        }
        cout << ch;
    }
    cout << endl;
}
