/*
Задан файл, содержащий фамилию, имя, отчество,
группу и оценки студентов за последнюю сессию.
а)Вывести фамилии и инициалы студентов, сдавших сессию без троек.
б)Переписать в новый файл фамилии и названия групп
тех студентов, которые имеют хотя бы одну задолженность (если оценка < 3).
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_GRAGES = 5;

struct student_record
{
    string surname; // Фамилия
    string name; // Имя
    string patronymic; // Отчество
    string group; // Группа
    int grades[MAX_GRAGES]; // Оценки
};

bool has_no_threes(int grades[]);
bool has_debts(int grades[]);

int main()
{
    ifstream in_f("../io_files/11_in.txt");
    ofstream out_f("../io_files/11_out.txt");

    student_record stu;
    while (in_f >> stu.surname >> stu.name >> stu.patronymic >> stu.group)
    {
        for (int i = 0; i < MAX_GRAGES; ++i)
            in_f >> stu.grades[i];
        
        if (has_no_threes(stu.grades))
            cout << stu.surname << " " << stu.name << " " << stu.patronymic << endl;

        if (has_debts(stu.grades))
            out_f << stu.surname << " " << stu.group << endl;
    }
}

bool has_no_threes(int grades[])
{
    for (int i = 0; i < MAX_GRAGES; ++i)
        if (grades[i] == 3) return false;
    return true;
}

bool has_debts(int grades[])
{
    for (int i = 0; i < MAX_GRAGES; ++i)
        if (grades[i] < 3) return true;
    return false;
}
