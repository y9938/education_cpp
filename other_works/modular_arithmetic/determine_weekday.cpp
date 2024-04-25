/*
Вам дана дата (день, месяц и год). Ваша задача — определить,
на какой день недели приходится эта дата. Для упрощения задачи предположим,
что даты начинаются с 1 января 1900 года, который был понедельником.
Используйте модульную арифметику для решения этой задачи, учитывая,
что год может быть високосным.
*/

#include <iostream>
using namespace std;

const int MONTHS = 12;

struct Date {
    int day, month, year;
};

bool is_bissextile(int year);
int days_in_month(int month, int year);

int main() {
    Date date1;
    cout << "Enter date (day,month,year): ";
    cin >> date1.day >> date1.month >> date1.year;

    int day_in_year = 0;
    for (int month = 0; month < MONTHS; ++month) {
        day_in_year += days_in_month(month, date1.year);
    }
    cout << "Days a year: " << day_in_year << endl;

    Date date2;
    date2.day = 1, date2.month = 1, date2.year = 2024;

    
    //int dif_days = (date1.year - date2.year) * 365;
    //cout << "The difference in days: " << endl;

    //cout << "Day of the week: " << day_in_year % 7 << endl;
}

bool is_bissextile(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) 
                return true;
            else
                return false;
        } else
            return true;
    }
    return false;
}

int days_in_month(int month, int year)
{
    switch (month) {
        case 0: case 2: case 4: case 6: case 7: case 9: case 11:
            return 31;
        case 3: case 5: case 8: case 10:
            return 30;
        case 1:
            return is_bissextile(year) ? 29 : 28;
        default:
            return 0;
    }
}
