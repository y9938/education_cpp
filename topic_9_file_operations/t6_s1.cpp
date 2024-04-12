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
    ifstream input_file("../io_files/6_input.txt");

    char ch;
    int balance = 0;

    while (input_file.get(ch))
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
