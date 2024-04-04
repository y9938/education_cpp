/*
Дан файл, содержащий программу на языке С++. Проверить эту программу на
несоответствие числа открывающих и закрывающих фигурных скобок.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../6.txt");

    string line;
    int count_open = 0;
    int count_close = 0;
    while (getline(input_file, line))
    {
        int len = line.length();
        for (int i = 0; i < len; ++i)
        {
            if (line[i] == '{')
            {
                ++count_open;
            }
            else
            {
                if (line[i] == '}')
                {
                    ++count_close;
                }
            }
        }
    }
    
    if (count_open == count_close)
    {
        cout << "Good" << endl;
    }
    else
    {
        cout << "Bad" << endl;
    }
}
