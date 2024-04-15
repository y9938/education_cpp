/*
Дан файл. Строки, начинающиеся с цифры, поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("../io_files/2_in.txt");
    ofstream out_f("../io_files/2_out.txt");

    string line;
    while (getline(in_f, line))
    {
        if (line.empty()) continue;

        int i = 0;
        while (line[i] == ' ')
            ++i;
        if (line[i] >= '0' && line[i] <= '9')
        {
            out_f << line << endl;
        }
    }
}
