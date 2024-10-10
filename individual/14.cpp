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
    new_node->prev = nullptr;  // Указатель на предыдущий узел
    new_node->next = nullptr;  // Указатель на следующий узел

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

void exclude_words_by_char_code_sum(List *&head, int number)
{
    List *current = head;

    while (current)
    {
        List *start_word = nullptr, *end_word = nullptr;
        int sum = 0;

        while (current && current->sym == ' ')
        {
            current = current->next;
        }
        start_word = current;

        while (current && current->sym != ' ')
        {
            sum += current->sym;
            end_word = current;
            current = current->next;
        }

        if (sum % number == 0 && start_word && end_word)
        {
            List *to_delete = start_word;
            while (to_delete != end_word->next)
            {
                List *next_node = to_delete->next;
                delete_node(head, to_delete);
                to_delete = next_node;
            }
        }

        if (current)
            current = current->next;
    }
}

void print_list(List *head)
{
    List *current = head;
    while (current)
    {
        cout << current->sym;
        current = current->next;
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

    exclude_words_by_char_code_sum(head, your_number);

    cout << "After editing:\n";
    print_list(head);
}
