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

    string line;
    while (getline(input_file, line))
    {
        string result; // Создаем новую строку и заполняем ее
        int len = line.length();
        for (int i = 0; i < len; ++i)
        {
            if (line[i] == '.')
            {
                result += "...";
            }
            else
            {
                result += line[i];
            }
        }
        result_file << result << endl;
    }
}
