/*
Дан файл, содержащий программу на языке С++. Проверить эту программу на
несоответствие числа открывающих и закрывающих фигурных скобок.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in_f("../io_files/6_in.txt");

    char ch;
    int balance = 0;

    while (in_f.get(ch))
    {
        if (ch == '{')
            ++balance;
        else
            if (ch == '}')
                --balance;
    }
    
    if (balance == 0)
        cout << "Good" << endl;
    else
        cout << "Bad" << endl;
}
