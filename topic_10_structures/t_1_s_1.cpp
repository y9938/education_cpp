/*
Создать структуру Дата с элементами День, Месяц, Год. 
Для N человек с заданной датой рождения вывести 
сообщение, в каком сезоне и в каком веке родился человек.
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    srand(time(NULL));

    const int N = 10;
    Date person[N];

    for (int i = 0; i < N; ++i)
    {
        // % 31 + 1 - (это от 1 до 31 включительно)
        person[i].day = rand() % 31 + 1;
        person[i].month = rand() % 12 + 1;
        person[i].year = rand() % 2024; // до 2023 (включ.)
    }

    string result[N];
    for (int i = 0; i < N; ++i)
    {
        int season = (person[i].month % 12) / 3;
        switch (season)
        {
            case 0:
                result[i] = "Winter";
                break;
            case 1:
                result[i] = "Spring";
                break;
            case 2:
                result[i] = "Summer";
                break;
            case 3:
                result[i] = "Autumn";
                break;
        }
    }

    int century[N];
    for (int i = 0; i < N; ++i)
        century[i] = (person[i].year / 100) + 1;
    
    for (int i = 0; i < N; ++i)
    {
        printf("Person %d: %d/%d/%d - %s, Century: %d\n", i + 1, person[i].day,
            person[i].month, person[i].year, result[i].c_str(), century[i]);
    }
}