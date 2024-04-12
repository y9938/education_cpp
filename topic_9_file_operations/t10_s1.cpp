/*
Дан файл. Слова в строках разделены пробелами. 
В словах, начинающихся с буквы а, удалить эту
букву.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../io_files/10_input.txt");
    string word;
    while (input_file >> word)
    {
        if (word[0] == 'a') word.erase(0, 1);
        cout << word << " ";
    }
    cout << endl;
}
