/*
Дан файл и строка st. Если строка файла содержит в качестве фрагмента строку st, 
то в начало этой строки вставить звездочку и пробел.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("io_files/3_in.txt");
    ofstream out_f("io_files/3_out.txt");

    string line, st = "star";
    int len_st = st.length();
    while (getline(in_f, line))
    {
        int len = line.length();
        bool found = false;
        for (int i = 0; i <= len - len_st && !found; ++i)
        {
            if (line[i] == st[0])
            {
                found = true;
                for (int j = 1; j < len_st; ++j)
                {
                    if (line[i + j] != st[j])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    line = "* " + line;
                    break;
                }
            }
        }
        out_f << line << endl;
    }
}
