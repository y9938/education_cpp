/*
Дан файл. Преобразовать строки файла следующим образом: если строка является
палиндромом, т.е. 1-й ее символ равен последнему, 2-й - предпоследнему и т.д.,
то оставить ее без изменения, иначе строку удвоить, дописав в ее конец строку
в обратном порядке. Результат поместить в новый файл.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("io_files/5_in.txt");
    ofstream out_f("io_files/5_out.txt");

    string line;
    while (getline(in_f, line))
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
            out_f << line << endl;
        }
        else
        {
            out_f << line << " ";
            for (int i = line.length() - 1; i >= 0; --i)
            {
                out_f << line[i];
            }
            out_f << endl;
        }
    }
}
