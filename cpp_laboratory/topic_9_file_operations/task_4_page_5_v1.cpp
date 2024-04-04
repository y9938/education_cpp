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
    ifstream input_file("../4_input.txt");
    ofstream result_file("../4_result.txt");

    string line;
    while (getline(input_file, line))
    {
        int len = line.length();
        for (int i = 0; i < len; ++i)
        {
            if (line[i] == '.')
            {
                line.insert(i + 1, "..");
                i += 2;
            }
        }
        result_file << line << endl;
    }
}
