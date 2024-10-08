/*
Исключить  из списка  слова, сумма кодов символов которых кратна заданному числу.
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
    List *new_node = new List; // Создаем новый узел
    new_node->sym = input;     // Устанавливаем символ
    new_node->prev = 0;        // Указатель на предыдущий узел
    new_node->next = 0;        // Указатель на следующий узел

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

void exclude_words_by_char_code_sum(List *&head)
{
    List *temp = head;
    while (temp)
    {
        List *start_word, *end_word;
        if (temp->sym == ' ')
        {
            while (true)
            {
                if (temp->next->sym != ' ' && temp->next)
                    break;
                else
                    temp = temp->next;
            }
        }
        start_word = temp->next;
        while (temp->sym != ' ')
        {
            temp = temp->next;
        }
        end_word = temp->prev;

        cout << "start word = " << start_word->sym << endl;
        cout << "end_word = " << end_word->sym << endl;
        /*temp = temp->next;*/
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
    List *last_node = 0;
    char input;

    int your_number;
    cout << "Enter a number: ";
    cin >> your_number;

    cout << "Enter characters (enter '.' to complete): " << endl;

    while (true)
    {
        input = cin.get(); // Считываем символ, включая пробелы
        if (input == '.')
            break;
        add_node(head, input, last_node);
    }

    cout << "List of symbols: ";
    exclude_words_by_char_code_sum(head);
    print_list(head);
}
