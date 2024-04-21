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

bool is_positive_int(const string& word)
{
    if (word.empty()) return false;
    for (char ch : word)
    {
        if (!isdigit(ch)) return false;
    }
    return true;
}

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
            while (i < len && (line[i] == ' ' || ispunct(line[i]))) ++i;
            int begin = i;
            while (i < len && (line[i] != ' ' && !ispunct(line[i]))) ++i;
            string word;
            word = line.substr(begin, i - begin);
            if (is_positive_int(word))
            {
                int number = stoi(word);
                number++;
                out_f << number << " ";
            }
            else
                out_f << word << " ";
        }
        out_f << endl;
    }
}
