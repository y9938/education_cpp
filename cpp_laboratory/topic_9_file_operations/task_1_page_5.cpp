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
    ifstream input_file("../task_1.txt");
    if (!input_file.is_open())
    {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line, max_vowel_line;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    double max_vowel_ratio = 0.0;

    while (getline(input_file, line)) // Пока можем читать строки
    {
        if (line.empty()) continue;

        int length = line.length();
        int count = 0;
        for (int i = 0; i < length; ++i)  // Символы в строке
        {
            for (unsigned int j = 0; j < sizeof(vowels)/sizeof(vowels[0]); ++j) // По каждой гласной из массива
            {
                if (tolower(line[i]) == vowels[j])
                {
                    ++count;
                }
            }
        }
        double current_ratio = (double) count / length; // Доля гласных в текущей строке
        if (current_ratio > max_vowel_ratio)
        {
            max_vowel_ratio = current_ratio;
            max_vowel_line = line;
        }
    }

    cout << "Line with the highest number of vowels: " << max_vowel_line << endl;
    cout << "Number of vowels in that line: " << max_vowel_ratio << endl;
    
    input_file.close();
    return 0;
}
