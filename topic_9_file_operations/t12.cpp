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
    ifstream in_f("io_files/12_in.txt");
    ofstream out_f("io_files/12_out.txt");
    string line;
    while (getline(in_f, line))
    {
        if (line.empty()) continue;
        int len = line.length();
        int i = len - 1;
        while (i > 0 && line[i] == ' ') --i;
        while (i > 0 && line[i] != ' ') --i;
        line.erase(i, len - i);
        out_f << line << endl;
    }
}
