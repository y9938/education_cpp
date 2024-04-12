/*
Дан файл. Слова в строках разделены пробелами. 
В каждой строке удалить последнее слово. 
Результат поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../io_files/12_input.txt");
    ofstream result_file("../io_files/12_result.txt");
    string line;
    while (getline(input_file, line))
    {
        if (line.empty()) continue;
        int len = line.length();
        int i = len - 1;
        while (i > 0 && line[i] == ' ') --i;
        while (i > 0 && line[i] != ' ') --i;
        line.erase(i, len - i);
        result_file << line << endl;
    }
}
