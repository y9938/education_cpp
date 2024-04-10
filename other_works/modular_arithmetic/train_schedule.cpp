/*
В небольшом городке поезда на главный вокзал прибывают каждые 45 минут.
Первый поезд прибывает ровно в 00:00. Вам нужно написать программу,
которая для заданного времени (часы и минуты) определит,
сколько минут осталось ждать до следующего поезда.
Примеры:
Если текущее время 00:20, то до следующего поезда осталось 25 минут.
Если текущее время 01:05, то до следующего поезда осталось 40 минут.
*/

#include <iostream>
using namespace std;

int train_minutes(int hour, int minutes);

int main()
{
    int hour;
    int minutes;
    cout << "Enter hour and minutes: ";
    cin >> hour >> minutes;

    cout << "Before the train: " << train_minutes(hour, minutes) << endl;
}

int train_minutes(int hour, int minutes)
{
    int result;
    result = 45 - ((hour * 60 + minutes) % 45);
    return result;
}
