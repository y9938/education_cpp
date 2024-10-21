/*
Продублировать слова, сумма кодов символов которых кратна заданному числу.
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

void delete_node(List *&head, List *&node)
{
    if (node == head)
    {
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete node;
    }
    else
    {
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        delete node;
    }
}

void duplication_word(List *left, List *right)
{
    List *start = left;
    int count = 1;
    while (left != right)
    {
        left = left->next;
        ++count;
    }
    List *after_end = right->next;
    left = start;
    for (int i = 0; i < count; ++i)
    {
        List *new_node = new List{left->sym, right, after_end};
        if (after_end)
        {
            after_end->prev = new_node;
        }
        right->next = new_node;
        right = new_node;
        left = left->next;
    }
}

void func(List *head, int number)
{
    List *current = head;

    // Выделение слова и работа с ним
    while (current)
    {
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

        if (word_start && word_end && sum % number == 0)
        {
            duplication_word(word_start, word_end);
        }
    }
}

void print_list(List *node)
{
    while (node)
    {
        cout << node->sym;
        node = node->next;
    }
    cout << endl;
}

int main()
{
    List *head = 0;
    List *last_node = 0;
    char input;

    int your_number;
    cout << "Enter a number: ";
    cin >> your_number;
    cin.ignore(); // Игнорируем символ новой строки после ввода числа

    cout << "Enter characters (enter '.' to complete): " << endl;

    while (true)
    {
        input = cin.get(); // Считываем символ, включая пробелы
        if (input == '.')
            break;
        add_node(head, input, last_node);
    }

    func(head, your_number);

    cout << "After editing:\n";
    print_list(head);
}
