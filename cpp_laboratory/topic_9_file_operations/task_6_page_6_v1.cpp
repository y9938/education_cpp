/*
Дан файл, содержащий программу на языке С++. Проверить эту программу на
несоответствие числа открывающих и закрывающих фигурных скобок.
*/

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../6.txt");
    if (!input_file.is_open())
    {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line;
    int open_count = 0;
    int close_count = 0;
    while (getline(input_file, line))
    {
        size_t pos_open = 0;
        while ((pos_open = line.find('{', pos_open)) != string::npos)
        {
            ++open_count;
            ++pos_open;
        }

        size_t pos_close = 0;
        while ((pos_close = line.find('}', pos_close)) != string::npos)
        {
            ++close_count;
            ++pos_close;
        }
    }

    input_file.close();

    if ((open_count + close_count) % 2 == 0)
    {
        cout << "Good" << endl;
    }
    else
    {
        cout << "Bad" << endl;
    }

    return 0;
}