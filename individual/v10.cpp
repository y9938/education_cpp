/*
Создать файл с полями: фамилия, сумма долга,
номер ЖЭКа. Вывести список должников.
Определить сумму задолженностей по каждому ЖЭКу.
P.s Тут я использую номера ЖЭКа от 1 до 3
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_HCS = 3;

struct record
{
    string surname; // Фамилия
    double debt_amount; // Сумма долга
    int hcs_number; // Номер ЖЭКа
};

int main()
{
    ifstream in_f("io_files/v10_in.txt");

    record rec;
    double debt_hcs[MAX_HCS] = {}; // Суммы долгов по каждому ЖЭКу
    while (in_f >> rec.surname >> rec.debt_amount >> rec.hcs_number)
    {
        if (rec.debt_amount > 0)
            cout << rec.surname << "\t" << rec.debt_amount << "\t" << rec.hcs_number << endl;

        if (rec.hcs_number >= 1 && rec.hcs_number <= MAX_HCS)
            debt_hcs[rec.hcs_number - 1] += rec.debt_amount;
    }
    cout << "Сумма по каждому ЖЭКу:\n";
    for (int i = 0; i < MAX_HCS; ++i)
        cout << i + 1 << ": " << debt_hcs[i] << endl;
}
