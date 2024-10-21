/*
Если  первое слово списка  симметрично,
то вывести все слова списка в обратном порядке.
Сформировать двунаправленный список символов, заканчивая
ввод точкой. Слова в этом списке разделены пробелами. Выполнить
указанные действия.
*/

#include <iostream>
using namespace std;

struct List
{
    char sym;
    List *prev, *next;
};

void add_node(List *&head, char input, List *&last_node)
{
    List *new_node = new List{input, nullptr, nullptr};

    if (!head)
    {
        head = new_node;
        last_node = head;
    }
    else
    {
        last_node->next = new_node; // Добавляем новый узел в конец
        new_node->prev = last_node; // Устанавливаем указатель на предыдущий узел
        last_node = new_node;
    }
}

void print_list(List *node, bool reverse = false)
{
    if (reverse)
    {
        while (node)
        {
            cout << node->sym;
            node = node->prev;
        }
    }
    else
    {
        while (node)
        {
            cout << node->sym;
            node = node->next;
        }
    }
    cout << endl;
}

bool is_symmetric(List *left, List *right)
{
    while (left != right && left && right)
    {
        if (left->sym != right->sym)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

void func(List *head, List *last_node)
{
    List *current = head;

    // Выделение слова и работа с ним
    List *word_start = nullptr, *word_end = nullptr;
    int sum = 0;

    while (current && current->sym == ' ')
    {
        current = current->next;
    }
    word_start = current;

    while (current && current->sym != ' ')
    {
        sum += current->sym;
        word_end = current;
        current = current->next;
    }

    if (is_symmetric(word_start, word_end))
        print_list(last_node, true);
    else
        print_list(head);
}

int main()
{
    List *head = 0, *last_node = 0;
    char input;

    cout << "Enter characters (enter '.' to complete): " << endl;

    while (true)
    {
        input = cin.get(); // Считываем символ, включая пробелы
        if (input == '.')
            break;
        add_node(head, input, last_node);
    }

    func(head, last_node);
}
