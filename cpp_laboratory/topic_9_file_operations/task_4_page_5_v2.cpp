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
    ifstream input_file("../4.txt");
    ofstream result_file("../4_result.txt");

    string line;
    while (getline(input_file, line))
    {
        size_t pos = 0;
        while ((pos = line.find('.', pos)) != string::npos)
        {
            line.insert(pos + 1, "..");
            pos += 3;
        }
        result_file << line << endl;
    }
}
