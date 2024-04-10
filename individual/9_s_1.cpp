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

bool is_digit(string word)
{
    for (char ch : word)
    {
        if (!isdigit(ch)) return false;
    }
    return true;
}

int main()
{
    ifstream input_file("../9_input.txt");
    string word;
    while (input_file >> word)
    {
        if (is_digit(word))
        {
            if (word[0] == '9')
            {
                int ten = 10;
                word = to_string(ten);
            }
            else word[0] += 1;
        }
        cout << word << " ";
    }  
    cout << endl;
}
