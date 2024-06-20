#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() 
{
    ifstream in_f("io_files/9_in.txt");
    ofstream out_f("io_files/9_out.txt");

    string line;
    while (getline(in_f, line)) 
    {
        // Преобразуем каждую строку в верхний регистр
        for (auto it = line.begin(); it != line.end(); ++it)
        {
            *it = toupper(*it);
        }
        
        // Записываем преобразованную строку в выходной файл
        out_f << line << endl;
    }
}
