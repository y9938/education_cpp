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
    ifstream input_file("../task_4.txt");
    ofstream result_file("../task_4_result.txt");
    if (!input_file.is_open() || !result_file.is_open())
    {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line;
    while (getline(input_file, line))
    {
        string result;
        int length = line.length();
        for (int i = 0; i < length; ++i)
        {
            if (line[i] == '.')
            {
                result += "...";
                while (i + 1 < length && line[i + 1] == '.') 
                {
                    ++i;
                }
            }
            else
            {
                result += line[i];
            }
        }
        result_file << result << endl;
    }

    input_file.close();
    result_file.close();
    return 0;
}
