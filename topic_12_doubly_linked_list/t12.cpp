/*
Построить  двунаправленный список  из  n целых  чисел.
Добавить  в  начало  списка  элемент, содержащий  сумму  всех  элементов списка,
а  в конец  –  элемент,  содержащий  произведение  всех элементов списка.
*/

#include <iostream>
using namespace std;

// Описание структуры узла двунаправленного списка
struct List
{
    int key;    // Поле данных
    List *prev; // Указатель на предыдущий элемент
    List *next; // Указатель на следующий элемент
};

// Функция для создания списка из n элементов
List *make_list(List *&last, int n)
{
    int key;
    List *current, *created, *beg;
    current = new List; // Создать первый элемент
    beg = current;      // Запомнить начало списка

    cout << "\nВведите ключ: " << endl;
    cin >> current->key; // Заполнить поле данных первого элемента
    current->prev = 0;
    current->next = 0;

    for (int i = 1; i < n; ++i)
    {
        created = new List; // Создать новый элемент
        cout << "Введите ключ: " << endl;
        cin >> created->key;     // Заполнить поле данных нового элемента
        current->next = created; // Связать текущий элемент с новым
        created->prev = current; // Связать новый элемент с текущим
        created->next = 0;       // Обнулить указатель на следующий элемент
        current = created;       // Перейти к новому элементу
    }

    last = current; // Запомнить последний элемент
    return beg;     // Вернуть начало списка
}

// Функция для печати списка
void print_list(List *beg)
{
    if (beg == 0) // Если список пустой
    {
        cout << "Список пуст" << endl;
        return;
    }

    List *current = beg; // Начать с первого элемента
    while (current)      // Пока не достигнут конец списка
    {
        cout << current->key << "\t"; // Вывести ключ текущего элемента
        current = current->next;      // Перейти к следующему элементу
    }
    cout << endl;
}

// Функция для подсчета суммы всех элементов списка и произведения всех элементов
void calculation(List *beg, int &product_nodes, int &sum_nodes)
{
    List *current = beg;

    while (current != nullptr) // Пока не достигнут конец списка
    {
        sum_nodes += current->key;
        product_nodes *= current->key;

        current = current->next;
    }
}

// Фукнция для добавления node начало ставим sum_nodes, а в конец product_nodes
void add_sv(List *&beg, List *last, int &product_nodes, int &sum_nodes)
{
    // Add first node
    List *p;
    p = new List;
    p->key = sum_nodes;
    p->prev = 0;
    p->next = beg;
    beg->prev = p;
    beg = p;
    // Add last node
    p = new List;
    p->key = product_nodes;
    p->prev = last;
    p->next = 0;
    last->next = p;
    last = p;
}

// Основная функция программы
int main()
{
    List *beg = nullptr;  // Указатель на начало списка (инициализация)
    List *last = nullptr; // Указатель на последний элемент (если нужно)
    int i, n;

    int sum_nodes = 0;
    int product_nodes = 1;

    do
    {
        cout << "1. Создать список\n";
        cout << "2. Печать списка\n";
        cout << "3. Посчитать сумму и произведение всех элементов\n";
        cout << "4. Добавить сумму как первую node, а произведение как last node\n";
        cout << "5. Выход\n";
        cin >> i;

        switch (i)
        {
        case 1:
            cout << "Введите количество элементов: ";
            cin >> n;
            beg = make_list(last, n); // Создать список и сохранить его начало в beg
            break;

        case 2:
            print_list(beg); // Печать списка на экран
            break;

        case 3:
            calculation(beg, product_nodes, sum_nodes); // Подсчет суммы всех элементов списка и произведения всех элементов
            cout << "Выполнены подсчеты.\n"
                 << "Сумма всех элементов: " << sum_nodes << "\nПроизведение: " << product_nodes << endl;
            break;

        case 4:
            add_sv(beg, last, product_nodes, sum_nodes);
            cout << "Добавлены nodes." << endl;
            break;
        }
    } while (i != 5); // Продолжать до выбора выхода

    return 0;
}
