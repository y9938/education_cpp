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
    string line;
    while (getline(input_file, line))
    {
        int i = 0;
        int len = line.length();
        while (i < len)
        {
            // После этого мы будем на позиции begin
            while (i < len && line[i] == ' ') ++i;
            // Удалится буква `a` и будет переведено на след. символ
            if (line[i] == 'a') line.erase(i, 1);
            // Пропускаем остальную часть слова
            while (i < len && line[i] != ' ') ++i;
        }
        cout << line << endl;
    }
}
