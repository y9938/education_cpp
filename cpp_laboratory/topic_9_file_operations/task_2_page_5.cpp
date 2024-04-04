/*
Дан файл. Строки, начинающиеся с цифры, поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../2_input.txt");
    ofstream output_file("../2_result.txt");

    string line;
    while (getline(input_file, line))
    {
        if (line.empty()) continue;

        int i = 0;
        while (line[i] == ' ')
            ++i;
        if (line[i] >= '0' && line[i] <= '9')
        {
            output_file << line << endl;
        }
    }
}
