/*
Построить двунаправленный список символов.
Вставить перед каждым символом цифры звездочку.
*/

#include <iostream>
using namespace std;

struct List
{
    char sym;
    List *prev, *next;
};

void add_node(List *&head, char c)
{
    List *new_node = new List; // Создаем новый узел
    new_node->sym = c;         // Устанавливаем символ
    new_node->prev = 0;        // Указатель на предыдущий узел
    new_node->next = 0;        // Указатель на следующий узел

    if (!head)
    {
        head = new_node;
    }
    else
    {
        List *temp = head;
        while (temp->next) // Идем до последнего узла
        {
            temp = temp->next;
        }
        temp->next = new_node; // Добавляем новый узел в конец
        new_node->prev = temp; // Устанавливаем указатель на предыдущий узел
    }
}

void add_asterisks(List *&head)
{
    List *temp = head;
    while (temp)
    {
        if (temp->sym >= '0' && temp->sym <= '9')
        {
            List *new_node = new List;
            new_node->sym = '*';

            // Вставляем новый узел перед текущим узлом
            new_node->next = temp;
            new_node->prev = temp->prev;

            if (temp->prev) // Если предыдущий узел существует, обновляем его
            {
                temp->prev->next = new_node;
            }
            else // Если узел был первым, то обновляем head
            {
                new_node->prev = 0;
                head = new_node;
            }
            temp->prev = new_node;
        }
        temp = temp->next;
    }
}

void print_list(List *head)
{
    List *temp = head;
    while (temp)
    {
        cout << temp->sym;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    List *head = 0;
    char input;

    cout << "Enter characters (enter '.' to complete): " << endl;

    while (true)
    {
        input = cin.get(); // Считываем символ, включая пробелы
        if (input == '.')
            break;
        add_node(head, input);
    }

    cout << "List of symbols: ";
    add_asterisks(head);
    print_list(head);
}