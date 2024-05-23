/*
Вам дана дата (день, месяц и год). Ваша задача — определить,
на какой день недели приходится эта дата. Для упрощения задачи предположим,
что даты начинаются с 1 января 1900 года, который был понедельником.
Используйте модульную арифметику для решения этой задачи, учитывая,
что год может быть високосным.
*/

#include <iostream>
using namespace std;

//const int MONTHS = 12;

struct Date {
    int day, month, year;
};

bool is_bissextile(int year);
int days_in_month(int month, int year);
int days_between_dates(Date start, Date end);

int main() {
    //Date start_date = {1, 0, 1900}; // 1 января 1900 года
    Date start_date = {1, 0, 2024};
    Date input_date;

    cout << "Recording format: day (0-31), month (0-11), year (from 2024)";
    cout << "\nEnter date (day,month,year): ";
    cin >> input_date.day >> input_date.month >> input_date.year;

    int dif_days = days_between_dates(start_date, input_date);
    cout << "The difference in days: " << dif_days << endl;

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

int days_in_month(int month, int year) {
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

int days_between_dates(Date start, Date end) {
    int days = 0;

    days += 31 - 1;
    for (int month = start.month + 1; month < end.month; ++month) {
        days += days_in_month(month, start.year);
    }
    days += end.day;

    for (int year = start.year + 1; year < end.year; ++year) {
        days += is_bissextile(year) ? 366 : 365;
    }

    return days;
}
