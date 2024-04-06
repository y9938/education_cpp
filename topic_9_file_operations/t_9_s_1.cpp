/*
Дан файл. Слова в строках разделены пробелами. 
В строках с четными номерами записать слова в
обратном порядке.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string reverse_words(string line);

int main()
{
    ifstream input_file("../io_files/9_input.txt");

    string line;
    int count_line = 0;
    while (getline(input_file, line))
    {
        ++count_line;
        if (count_line % 2 == 0)
            cout << reverse_words(line) << endl;
        else
            cout << line << endl;
    }
}

string reverse_words(string line)
{
    string result;
    int i = 0;
    int len = line.length();
    while (i < len)
    {
        while (i < len && line[i] == ' ') ++i;
        int begin = i;
        while (i < len && line[i] != ' ') ++i;
        string word;
        word = line.substr(begin, i - begin);
        for (int j = word.length() - 1; j >= 0; --j)
            result += word[j];
        result += " ";
    }
    return result;
}
