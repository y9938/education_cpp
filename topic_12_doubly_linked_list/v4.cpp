/*
Ввести N и список действительных чисел A1,A2...A n.
 Получить max(A1+An ,A 2+ A-n-1 ..., An + A1).
 Выводить суммы (первого + последнего), (второго + предпоследнего) элементов
 до середины и вести из них максимальную сумму.
*/

#include <iostream>
using namespace std;

struct List
{
    int key;
    List *prev, *next;
};

List *make_list(List *&last, int n)
{
    int key;
    List *current, *created, *beg;
    current = new List;
    beg = current;

    cout << "\nEnter key: " << endl;
    cin >> current->key;
    current->prev = 0;
    current->next = 0;

    for (int i = 1; i < n; ++i)
    {
        created = new List;
        cout << "Enter key: " << endl;
        cin >> created->key;
        current->next = created;
        created->prev = current;
        created->next = 0;
        current = created;
    }

    last = current;
    return beg;
}

void print_list(List *beg)
{
    if (beg == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }

    List *current = beg;
    while (current)
    {
        cout << current->key << "\t";
        current = current->next;
    }
    cout << endl;
}

void func(List *beg, List *last, int n, int &max)
{
    if (n <= 1)
        return;

    int sum;
    max = beg->key;

    for (int i = 0; i != n / 2; ++i)
    {
        sum = beg->key + last->key;
        cout << sum << "\t";
        if (sum > max)
            max = sum;
        beg = beg->next;
        last = last->prev;
    }
}

int main()
{
    int n;
    cout << "Enter `n`: " << endl;
    cin >> n;

    List *last;
    List *beg = make_list(last, n);

    cout << "\n----------- List -----------" << endl;
    print_list(beg);

    int max;
    cout << "\nSum:" << endl;
    func(beg, last, n, max);
    cout << "\n\nMax of the sums: " << max << endl;

    return 0;
}
