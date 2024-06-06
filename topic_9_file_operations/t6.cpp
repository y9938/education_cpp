/*
Дан файл, содержащий программу на языке С++. Проверить эту программу на
несоответствие числа открывающих и закрывающих фигурных скобок.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("io_files/6_in.txt");

    char ch;
    int count_open = 0;
    int count_close = 0;

    while (in_f.get(ch))
    {
        if (ch == '{')
            ++count_open;
        else
            if (ch == '}')
                ++count_close;
    }
    
    if (count_open == count_close)
        cout << "Good" << endl;
    else
        cout << "Bad" << endl;
}
