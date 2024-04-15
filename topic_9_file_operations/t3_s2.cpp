/*
Дан файл и строка st. Если строка файла содержит в качестве фрагмента строку st, 
то в начало этой строки вставить звездочку и пробел.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("../io_files/3_in.txt");
    ofstream out_f("../io_files/3_out.txt");

    string line, st = "star";
    while (getline(in_f, line))
    {
        if (line.find(st) != string::npos)
        {
            line = "* " + line;
        }
        out_f << line << endl;
    }
}
