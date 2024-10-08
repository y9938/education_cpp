/*
В двунаправленном списке поменять (первый и последний),
 (второй и предпоследний) элементы до середины.
Пример: 1 2 3 4 5 6
Вывод 6 5 4 3 2 1
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

void func(List *beg, List *last, int n)
{
    if (n <= 1)
        return;

    int tmp;

    for (int i = 0; i != n / 2; ++i)
    {
        tmp = beg->key;
        beg->key = last->key;
        last->key = tmp;

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

    cout << "\n----------- Changed List -----------" << endl;
    func(beg, last, n);
    print_list(beg);

    return 0;
}
