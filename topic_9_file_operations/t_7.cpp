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
    ifstream input_file("../io_files/7_input.txt");
    ofstream result_file("../io_files/7_result.txt");

    char ch;
    while (input_file.get(ch))
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
        result_file << ch;
    }
}
