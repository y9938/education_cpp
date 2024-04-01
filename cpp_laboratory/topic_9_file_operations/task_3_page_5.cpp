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
    ifstream input_file("../task_3.txt");
    ofstream result_file("../task_3_result.txt");
    if (!input_file.is_open() || !result_file.is_open())
    {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line, st = "star";
    int length_st = st.length();
    while (getline(input_file, line))
    {
        int length = line.length();
        bool found = false;
        for (int i = 0; i <= length - length_st && !found; ++i)
        {
            if (line[i] == st[0])
            {
                found = true;
                for (int j = 1; j < length_st; ++j)
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
        result_file << line << endl;
    }
    
    input_file.close();
    result_file.close();
    return 0;
}
