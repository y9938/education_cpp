/*
Вам дана дата (день, месяц и год). Ваша задача — определить,
на какой день недели приходится эта дата. Для упрощения задачи предположим,
что даты начинаются с 1 января 1900 года, который был понедельником.
Используйте модульную арифметику для решения этой задачи, учитывая,
что год может быть високосным.
*/

#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
};

bool is_bissextile(int year);
int days_in_month(int month, int year);
int days_between_dates(Date start, Date end);
string day_of_week(int days);

int main() {
    Date start_date = {1, 1, 1900}; // 1 января 1900 года
    Date input_date;

    cout << "\nEnter date (day,month,year): ";
    cin >> input_date.day >> input_date.month >> input_date.year;

    int days = days_between_dates(start_date, input_date);
    cout << "Day of the week: " << day_of_week(days) << endl;
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
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return is_bissextile(year) ? 29 : 28;
        default:
            return 0;
    }
}

int days_between_dates(Date start, Date end) {
    int days = 0;

    if (start.year == end.year) {
        for (int month = start.month; month < end.month; ++month) {
            days += days_in_month(month, start.year);
        }
        days += end.day - start.day;
        return days;
    }

    for (int month = start.month; month <= 12; ++month) {
        days += days_in_month(month, start.year);
    }
    days -= start.day;

    for (int month = 1; month < end.month; ++month) {
        days += days_in_month(month, end.year);
    }
    days += end.day;

    for (int year = start.year + 1; year < end.year; ++year) {
        days += is_bissextile(year) ? 366 : 365;
    }

    return days;
}

string day_of_week(int days) {
    string days_of_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    return days_of_week[days % 7];
}
