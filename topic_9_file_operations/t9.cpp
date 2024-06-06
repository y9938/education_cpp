/*
Дан файл. Слова в строках разделены пробелами. 
В строках с четными номерами записать слова в
обратном порядке.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("io_files/9_in.txt");
    string line;
    int count_line = 0;
    while (getline(in_f, line))
    {
        ++count_line;
        int i = 0;
        int len = line.length();
        while (i < len)
        {
            while (i < len && line[i] == ' ')
                ++i;
            int begin = i;
            while (i < len && line[i] != ' ')
                ++i;
            string word;
            word = line.substr(begin, i - begin);
            if (count_line % 2 == 0)
            {
                for (int j = word.length() - 1; j >= 0; --j)
                    cout << word[j];
                cout << " ";
            }
            else
                cout << word << " ";
        }
        cout << endl;
    }
}
