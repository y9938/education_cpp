/*
Дан файл. Слова в строках разделены пробелами. 
В каждой строке найти самое короткое слово и 
его номер.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../io_files/11_input.txt");
    string line;
    while (getline(input_file, line))
    {
        if (line.empty()) continue;
        int i = 0;
        int len = line.length();
        int min_word_len = 1000;
        int min_word_index = 0;
        int n_word = 1; // Счетчик слов
        while (i < len)
        {
            while (i < len && line[i] == ' ') ++i;
            int begin = i;
            while (i < len && line[i] != ' ') ++i;
            int word_len = i - begin;
            if (word_len > 0 && word_len < min_word_len) 
            {
                min_word_len = word_len;
                min_word_index = n_word;
            }
            if (word_len > 0) ++n_word;
        }
        cout << "Длина: " << min_word_len << endl;
        cout << "Номер слова: " << min_word_index << endl;
    }
}
