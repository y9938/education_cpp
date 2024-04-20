/*
Вам дана дата (день, месяц и год). Ваша задача — определить,
на какой день недели приходится эта дата. Для упрощения задачи предположим,
что даты начинаются с 1 января 1900 года, который был понедельником.
Используйте модульную арифметику для решения этой задачи, учитывая,
что год может быть високосным.
*/

#include <iostream>
using namespace std;

bool is_bissextile(int year);

int main()
{
    int day, month, year;
    cout << "Enter date (day,month,year): ";
    cin >> day >> month >> year;
}

bool is_bissextile(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
            if (year % 400 == 0) 
                return true;
            else
                return false;
        else
            return true;
    }
    return false;
}
