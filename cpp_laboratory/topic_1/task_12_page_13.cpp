#include <iostream>
using namespace std;

int main()
{
    int hours, minutes, seconds, work_time;
    cout << "Введите время начала задачи (часы, минуты, секунды) и длительность задачи (в секундах): \n";
    cin >> hours >> minutes >> seconds >> work_time;

    int total_time = hours * 3600 + minutes * 60 + seconds + work_time; // Общее количество секунд

    int remaining_days = total_time / 86400; // Количество дней
    total_time %= 86400; // Количество секунд (без дней)

    int remaining_hours = total_time / 3600; // Количество часов
    total_time %= 3600; // Количество секунд (без часов)
    
    int remaining_minutes = total_time / 60; // Минуты
    int remaining_seconds = total_time % 60; // Секунды

    cout << remaining_days << "(д), " << remaining_hours << "(ч), " << remaining_minutes << "(м), " << remaining_seconds << "(с). \n";
}
