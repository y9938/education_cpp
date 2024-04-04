/*
Дан файл. Слова в строках разделены пробелами. 
Найти строку с наибольшим числом слов.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int word_line(string line);

int main()
{
    ifstream input_file("../io_files/8_input.txt");

    string line;
    int max_word = 0; // Максимальное количество слов в строке
    string max_line; // Строка с максимальным количеством 
    while (getline(input_file, line))
    {
        int count_word = word_line(line);
        if (count_word > max_word)
        {
            max_word = count_word;
            max_line = line;
        }
    }

    cout << "Max word: " << max_word << endl;
    cout << "Max line: " << max_line << endl;
}

int word_line(string line)
{
    int count_word = 0;
    int i = 0;
    int len = line.length();
    while (i < len)
    {
        while (line[i] == ' ')
            ++i;
        int begin = i;
        while (line[i] != ' ' && i < len)
            ++i;
        string word;
        word = line.substr(begin, i - begin);
        if (word.length() > 0)
            ++count_word;
    }
    return count_word;
}
