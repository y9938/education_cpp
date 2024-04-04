/*
Дан файл. Найти строку, в которой доля гласных (a, e, i, o) максимальна.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ifstream input_file("../1.txt");

    string line, max_vowel_l;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    double max_vowel_r = 0.0;

    while (getline(input_file, line)) // Пока можем читать строки
    {
        if (line.empty()) continue;

        int len = line.length();
        int count = 0;
        for (int i = 0; i < len; ++i)  // Символы в строке
        {
            for (unsigned int j = 0; j < sizeof(vowels)/sizeof(vowels[0]); ++j) // По каждой гласной из массива
            {
                if (tolower(line[i]) == vowels[j])
                {
                    ++count;
                }
            }
        }
        double current_ratio = (double) count / len; // Доля гласных в текущей строке
        if (current_ratio > max_vowel_r)
        {
            max_vowel_r = current_ratio;
            max_vowel_l = line;
        }
    }

    cout << "Line with the highest number of vowels: " << max_vowel_l << endl;
    cout << "Number of vowels in that line: " << max_vowel_r << endl;
}
