/*
В файле заменить каждую цифру на следующую по величине цифру (‘9’ заменить на ‘0’),
результат поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("../io_files/7_in.txt");
    ofstream out_f("../io_files/7_out.txt");

    char ch;
    while (in_f.get(ch))
    {
        if (ch >= '0' && ch < '9')
        {
            ch += 1;
        }
        else
        {
            if (ch == '9')
            {
                ch = '0';
            }
        }
        out_f << ch;
    }
}
