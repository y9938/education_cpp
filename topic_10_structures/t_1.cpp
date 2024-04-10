/*
Создать структуру Дата с элементами День, Месяц, Год. 
Для N человек с заданной датой рождения вывести 
сообщение, в каком сезоне и в каком веке родился человек.
*/

#include <iostream>
#include <string>
#include <locale>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    const int N = 10;
    Date person[N];
    for (int i = 0; i < N; ++i)
    {
        person[i].day = 1 + i;
        person[i].month = 1 + i;
        person[i].year = 1959 + i;
    }
    for (int i = 0; i < N; ++i)
    {
        cout << "Person " << i + 1 << endl;
        cout << person[i].day << endl;
        cout << person[i].month << endl;
        cout << person[i].year << endl;
    }

    for (int i = 0; i < N; ++i)
    {
        switch (person[i].month)
        {
            case 12:
            case 1:
            case 2:
                cout << "Season: Winter" << endl;
                break;
            case 3:
            case 4:
            case 5:
                cout << "Season: Spring" << endl;
                break;
            case 6:
            case 7:
            case 8:
                cout << "Season: Summer" << endl;
                break;
            case 9:
            case 10:
            case 11:
                cout << "Season: Autumn" << endl;
                break;
            default:
                cout << "Invalid month" << endl;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int century;
        century = (person[i].year + 100) / 100;
        cout << "Век: " << century << endl;
    }
}