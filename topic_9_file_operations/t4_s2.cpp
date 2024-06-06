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

    string line;
    while (getline(in_f, line))
    {
        size_t pos = 0;
        while ((pos = line.find('.', pos)) != string::npos)
        {
            line.insert(pos + 1, "..");
            pos += 3;
        }
        out_f << line << endl;
    }
}
