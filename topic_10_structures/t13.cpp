/*
Дан файл, содержащий информацию о багаже пассажиров
(номер квитанции, количество вещей, общий вес багажа).
а) Найти число пассажиров, имеющих более двух вещей и
число пассажиров, количество вещей которых превосходит
среднее количество вещей.
б) Выяснить, имеется ли пассажир, багаж которого
превышает багаж каждого из остальных пассажиров
и по числу вещей, и по весу.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_RECORDS = 100;

struct luggage_record
{
    int receipt_number;
    int item_count;
    double total_weight;
};

int read_luggage_data(ifstream& in_f, luggage_record lug[], int items[], int& over_2_items);
double average_num_items(int n_rec, int items[]);

int main()
{
    ifstream in_f("io_files/13_in.txt");

    int over_2_items = 0;
    int items[MAX_RECORDS];
    luggage_record lug[MAX_RECORDS];
    
    int n_rec = read_luggage_data(in_f, lug, items, over_2_items);
    
    // a)
    cout << "Passengers with more than 2 items: " << over_2_items << endl;
    
    double average = average_num_items(n_rec, items);
    int above_avg_items = 0;
    for (int j = 0; j < n_rec; ++j)
        if (lug[j].item_count > average) ++above_avg_items;
    cout << "Passengers with above-average luggage: " << above_avg_items << endl;

    // b)
    luggage_record max_lug = lug[0];
    for (int k = 1; k < n_rec; ++k)
    {
        if (lug[k].item_count > max_lug.item_count && lug[k].total_weight > max_lug.total_weight)
            max_lug = lug[k];
    }
    int count_max_lug = 0;
    for (int k = 0; k < n_rec; ++k)
    {
        if (lug[k].item_count == max_lug.item_count && lug[k].total_weight == max_lug.total_weight)
            ++count_max_lug;
    }
    if (count_max_lug == 1)
        cout << "Passenger with the most items: " << max_lug.item_count << " items, Total weight: " << max_lug.total_weight << endl;
}

int read_luggage_data(ifstream& in_f, luggage_record lug[], int items[], int& over_2_items)
{
    int n_rec = 0;
    while (in_f >> lug[n_rec].receipt_number >> lug[n_rec].item_count >> lug[n_rec].total_weight)
    {
        if (lug[n_rec].item_count > 2) ++over_2_items;
        items[n_rec] = lug[n_rec].item_count;
        ++n_rec;
        if (n_rec == MAX_RECORDS) break;
    }
    return n_rec;
}

double average_num_items(int n_rec, int items[])
{
    double total = 0;
    for (int i = 0; i < n_rec; ++i)
        total += items[i];
    return total / n_rec;
}
