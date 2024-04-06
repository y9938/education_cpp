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
    ifstream input_file("../io_files/4_input.txt");
    ofstream result_file("../io_files/4_result.txt");

    char ch;
    while (input_file.get(ch))
    {
        if (ch == '.')
        {
            result_file << "...";
        }
        else
        {
            result_file << ch;
        }
    }
}
