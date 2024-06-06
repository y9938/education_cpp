/*
Дан файл. В строках каждую точку заменить многоточием (т.е. тремя точками).
Результат записать в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("io_files/4_in.txt");
    ofstream out_f("io_files/4_out.txt");

    char ch;
    while (in_f.get(ch))
    {
        if (ch == '.')
        {
            out_f << "...";
        }
        else
        {
            out_f << ch;
        }
    }
}
