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
    ifstream in_f("../io_files/10_in.txt");
    string word;
    while (in_f >> word)
    {
        if (word[0] == 'a') word.erase(0, 1);
        cout << word << " ";
    }
    cout << endl;
}
