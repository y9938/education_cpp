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
    ifstream input_file("../3.txt");
    ofstream result_file("../3_result.txt");

    string line, st = "star";
    while (getline(input_file, line))
    {
        if (line.find(st) != string::npos)
        {
            line = "* " + line;
        }
        result_file << line << endl;
    }
}
