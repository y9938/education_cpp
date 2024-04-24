/*
Среди всех слов файла найти слова,
представляющие собой целые числа.
Увеличить все эти числа на 1.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool is_int(const string& word);

int main()
{
    ifstream in_f("../io_files/9_in.txt");
    ofstream out_f("../io_files/9_out.txt");

    string line;
    while (getline(in_f, line))
    {
        int i = 0;
        int len = line.length();
        while (i < len)
        {
            while (i < len && (line[i] == ' ' || (ispunct(line[i]) && line[i] != '-')))
            {
                out_f << line[i]; // Пробелы и пунктуация, кроме минуса
                ++i;
            }
            int begin = i;
            if (i < len && line[i] == '-') ++i; // Проверяем наличие минуса перед числом
            while (i < len && (line[i] != ' ' && !ispunct(line[i]))) ++i;
            string word;
            word = line.substr(begin, i - begin);
            if (is_int(word))
            {
                int number = stoi(word); // Строку в число
                ++number;
                out_f << number;
            }
            else
                out_f << word;
        }
        out_f << endl;
    }
}

bool is_int(const string& word)
{
    if (word.empty()) return false;
    int len = word.length();
    int start = (word[0] == '-') ? 1 : 0;
    if (len == start) return false; // Строка только `-`
    for (int i = start; i < len; ++i) 
        if (!isdigit(word[i])) return false;
    return true;
}
