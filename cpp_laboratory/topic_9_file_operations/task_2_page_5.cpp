/*
 Дан файл. Строки, начинающиеся с цифры, поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../task_2.txt");
    ofstream output_file("../task_2_result.txt");
    if (!input_file.is_open())
    {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line;
    while (getline(input_file, line))
    {
        if (line.length() == 0) continue;

        int i = 0;
        while (line[i] == ' ')
            ++i;
        if (line[i] >= '0' && line[i] <= '9')
        {
            output_file << line << endl;
        }
    }

    input_file.close();
    output_file.close();
    return 0;
}
