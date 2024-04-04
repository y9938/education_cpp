/*
В файле заменить каждую цифру на следующую по величине цифру (‘9’ заменить на ‘0’),
результат поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../7.txt");
    ofstream result_file("../7_result.txt");
    
    string line;
    while (getline(input_file, line))
    {
        int len = line.length();
        for (int i = 0; i < len; ++i)
        {
            if (line[i] >= '0' && line[i] < '9')
            {
                line[i] += 1;
            }
            else
            {
                if (line[i] == '9')
                {
                    line[i] = '0';
                }
            }
        }
        result_file << line << endl;
    }
}
