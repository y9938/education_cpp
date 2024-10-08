#include <iostream>
#include <string.h>
using namespace std;

struct List // описание структуры
{
    int key;           // поле данных
    List *pred, *next; // адресные поля
};

// формирование списка из n элементов
List *make_list()
{
    int n;
    cout << "n-?";
    cin >> n;
    List *p, *r, *beg;
    p = new List; // создать первый элемент
    beg = p;      // запомнить адрес в переменную beg, в которой хранится начало списка
    cout << "key-?";
    cin >> p->key; // заполнить поле данных
    p->pred = 0;
    p->next = 0;                // заполнить адресные поля
    for (int i = 1; i < n; i++) /*добавить элементы в конец списка*/
    {
        r = new List; // новый элемент
        cout << "key-?";
        cin >> r->key; // заполнить поле данных
        p->next = r;   // связать начало списка с r
        r->pred = p;   // связать r с началом списка
        r->next = 0;   /*обнулить последнее адресное поле*/
        p = r;         /*передвинуть p на последний элемент списка*/
    }
    return beg; // вернуть начало списка
}

/*печать списка, на который указывает указатель beg*/
void print_list(List *beg)
{
    if (beg == 0) // если список пустой
    {
        cout << "The list is empty\n";
        return;
    }
    List *p = beg;
    while (p) // пока не конец списка
    {
        cout << p->key << "\t";
        p = p->next; // перейти на следующий
    }
    cout << "\n";
}

// удаление элемента с номером к
List *del_List(List *beg, int k)
{
    List *p = beg;
    if (k == 1) // удалить первый элемент
    {
        beg = beg->next; /*переставить начало списка на следующий элемент*/
        if (beg == 0)
            return 0;  /*если в списке только один элемент*/
        beg->pred = 0; /*обнулить адрес предыдущего элемента */
        delete p;      // удалить первый элемент
        return beg;    // вернуть начало списка
    }
    // если удаляется элемент из середины списка
    for (int i = 0; i < k - 2 && p != 0; i++, p = p->next)
        ; /*пройти по списку либо до элемента с предыдущим
номером, либо до конца списка*/
    if (p == 0 || p->next == 0)
        return beg;    // если в списке нет элемента с номером k
    List *r = p->next; // встать на удаляемый элемент
    p->next = r->next; // изменить ссылку
    delete r;          // удалить r
    r = p->next;       // встать на следующий
    if (r != 0)
        r->pred = p; /*если r существует, то связать элементы*/
    return beg;      // вернуть начало списка
}

// добавление элемента с заданным номером
List *add_List(List *beg, int k)
{
    List *p;
    p = new List; /*создать новый элемент изаполнить поле данных*/
    cout << "key-?";
    cin >> p->key;
    p->pred = 0; // обнулить адрес предыдущего
    p->next = 0; // обнулить адрес следующего
    if (k == 1)  // если добавляется первый элемент
    {
        p->next = beg; // добавить перед beg
        beg->pred = p; // связать список с добавленным элементом
        beg = p;       // запомнить первый элемент в beg
        return beg;    // вернуть начало списка
    }
    List *r = beg; // встать на начало списка
    for (int i = 0; i < k - 2 && r->next != 0; i++, r = r->next)
        ;              /*пройти по списку либо до конца списка,
                либо до элемента с номером k-1*/
    p->next = r->next; // связать р с элементом, следующим за вставляемым
    if (r->next != 0)
        r->next->pred = p; /*если элемент не последний, то связать элемент, следующий за
вставляемым, с р */
    p->pred = r;           // связать р и r
    r->next = p;
    return beg; // вернуть начало списка
}

int main()
{
    List *beg;
    int i, k;
    do
    {
        cout << "1.Make list\n";
        cout << "2.Print list\n";
        cout << "3.Add List\n";
        cout << "4.Del List\n";
        cout << "5.Exit\n";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            beg = make_list();
            break;
        }
        case 2:
        {
            print_list(beg);
            break;
        }
        case 3:
        {
            cout << "\nk-?";
            cin >> k;
            beg = add_List(beg, k);
            break;
        }
        case 4:
        {
            cout << "\nk-?";
            cin >> k;
            beg = del_List(beg, k);
            break;
        }
        }
    } while (i != 5);
}
