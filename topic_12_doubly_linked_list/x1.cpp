/*
Удалить все отрицательные числа из двунаправленного списка.
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

// Функция для удаления всех отрицательных чисел из списка
List *remove_negatives(List *beg)
{
    List *current = beg;

    while (current != nullptr) // Пока не достигнут конец списка
    {
        if (current->key < 0) // Проверить, является ли ключ отрицательным
        {
            List *to_delete = current; // Сохранить узел для удаления

            // Настроить указатели на соседние элементы
            if (current->prev != nullptr) // Если это не первый узел
            {
                current->prev->next = current->next; // Связать предыдущий узел с следующим
            }
            else // Если это первый узел
            {
                beg = current->next; // Переместить указатель начала на следующий узел
            }

            if (current->next != nullptr) // Если это не последний узел
            {
                current->next->prev = current->prev; // Связать следующий узел с предыдущим
            }

            current = current->next; // Перейти к следующему узлу после удаления текущего
            delete to_delete;        // Удалить отрицательный узел из памяти
        }
        else
        {
            current = current->next; // Перейти к следующему узлу, если текущий не был удалён
        }
    }

    return beg; // Вернуть обновлённый указатель на начало списка
}

// Основная функция программы
int main()
{
    List *beg = nullptr;  // Указатель на начало списка (инициализация)
    List *last = nullptr; // Указатель на последний элемент (если нужно)
    int i, n;

    do
    {
        cout << "1. Создать список\n";
        cout << "2. Печать списка\n";
        cout << "3. Удалить отрицательные числа\n";
        cout << "4. Выход\n";
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
            beg = remove_negatives(beg); // Удаление отрицательных чисел из списка
            cout << "Отрицательные числа удалены.\n";
            break;
        }
    } while (i != 4); // Продолжать до выбора выхода

    return 0;
}
