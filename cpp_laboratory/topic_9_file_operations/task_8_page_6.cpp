/*
Дан файл. Слова в строках разделены пробелами. 
Найти строку с наибольшим числом слов.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream input_file("../8_input.txt");

    string line;
    while (getline(input_file, line))
    {
        int count = 0;
        int i = 0;
        int len = line.length();
        while (i < len)
        {
            while (line[i] != ' ')
                ++i;
            int begin = i;
            while (line[i] == ' ')
                ++i;
            string word;
            word = line.substr(begin, i - begin);
            ++count;
        }
        
    }
}