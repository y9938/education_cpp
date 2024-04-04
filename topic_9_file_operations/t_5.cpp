/*
Дан файл. Преобразовать строки файла следующим образом: если строка является
палиндромом, т.е. 1-й ее символ равен последнему, 2-й - предпоследнему и т.д.,
то оставить ее без изменения, иначе строку удвоить, дописав в ее конец эту же строку.
Результат поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("../io_files/5_input.txt");
    ofstream result_file("../io_files/5_result.txt");

    string line, result;
    while (getline(input_file, line))
    {
        int len = line.length();
        bool pal = true;
        
        for (int i = 0; i < len / 2; ++i)
        {
            if (line[i] != line[len - 1 - i])
            {
                pal = false;
                break;
            }
        }

        if (pal)
        {
            result_file << line << endl;
        }
        else
        {
            result_file << line << line << endl;
        }
    }
}
