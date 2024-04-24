/*
Создать файл с полями: фамилия, сумма долга,
номер ЖЭКа. Вывести список должников.
Определить сумму задолженностей по каждому ЖЭКу.
P.s Тут я использую номера ЖЭКа в виде слов
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_REC = 100;

struct record
{
    string surname; // Фамилия
    double debt_amount; // Сумма долга
    string hcs_number; // Номер ЖЭКа
};

void sort(record arr[], int size);
void calculate_debts(record arr[], int size);

int main()
{
    ifstream in_f("../io_files/10_in.txt");

    record rec[MAX_REC];
    int n_rec = 0; // Реальное количество записей

    while (in_f >> rec[n_rec].surname >> rec[n_rec].debt_amount >> rec[n_rec].hcs_number)
    {
        if (rec[n_rec].debt_amount > 0)
            cout << rec[n_rec].surname << "\t" << rec[n_rec].debt_amount << "\t" << rec[n_rec].hcs_number << endl;
        ++n_rec;
    }

    sort(rec, n_rec);
    calculate_debts(rec, n_rec);
}

void sort(record arr[], int size)
{
    for (int i = size - 1; i > 0; --i) 
        for (int j = 0; j < i; ++j) 
            if (arr[j].hcs_number > arr[j+1].hcs_number) 
            {
                record tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

void calculate_debts(record arr[], int size)
{
    int i = 0;
    cout << "\n" << "НОМЕР ЖЭКа" << "\tСУММА ДОЛГА" << "\n\n";
    while (i < size) 
    {
        string current_hcs = arr[i].hcs_number;
        double total_debt = 0;
        while (i < size && arr[i].hcs_number == current_hcs) 
        {
            total_debt += arr[i].debt_amount; // подсчет суммы долга по текущему ЖЭКу
            ++i;
        }
        cout << current_hcs << "\t\t" << total_debt << "\n";
    }
}
