/*
Для натурального N и действительных A1,...,A2n
получить A1 * A2n + A2 * A2n-1 + ... + An * An+1.
Ввести элементы списка и выполнить указанные действия.
*/

#include <cstddef>
#include <exception>
#include <iostream>
#include <sys/types.h>
using namespace std;

struct List
{
    int value;
    List* next;
};

List* Init(int N);
void print_list(List* head);
double calculate_expression(List* head, int N);
void delete_even_nodes(List*& head);
void append_node(List*& head, int value);

int main()
{
    int N;
    cout << "Enter the N: ";
    cin >> N;

    List* head = Init(N * 2);

    double result = calculate_expression(head, N);
    cout << "Result of the expression: " << result << endl;
    print_list(head);

    delete_even_nodes(head);
    print_list(head);
}

List* Init(int N)
{
    if (N <= 0) return nullptr;

    List* head = new List;
    cout << "Enter the value 1: ";
    cin >> head->value;
    head->next = nullptr;

    List* current = head;
    for (int i = 1; i < N; ++i)
    {
        List* new_node = new List;
        cout << "Enter the value " << i + 1 << ": ";
        cin >> new_node->value;
        new_node->next = nullptr;
        current->next = new_node;
        current = new_node;
    }

    return head;
}

void print_list(List* head)
{
    List* current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

double calculate_expression(List* head, int N)
{
    double result = 0;
    List* left = head;
    List* right = head;

    for (int i = 0; i < N; ++i)
    {
        right = right->next;
    }
    
    for (int i = 0; i < N; ++i)
    {
        result += left->value * right->value;
        left = left->next;
        right = right->next;
    }

    return result;
}

void delete_even_nodes(List*& head)
{
    List* current = head;
    List* prev = nullptr;

    while (current != nullptr)
    {
        if (current->value % 2 == 0)
        {
            List* temp = current;
            if (prev == nullptr)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            current = current->next;
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void append_node(List*& head, int value)
{
    List* new_node = new List;
    cout << "Enter the value: ";
    cin >> new_node->value;
    new_node->next = nullptr;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        List* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}
