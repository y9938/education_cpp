/*
Построить список из n целых чисел.
Вычислить произведение первого,
наибольшего и наименьшего чисел списка.
*/

#include <cstddef>
#include <iostream>
using namespace std;

struct List
{
    int value;
    List* next;
};

List* Init(int n);

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    List* head = Init(n);
    
    List* current = head;
    int product = 1;
    product *= head->value; // product first element 
    int min = head->value;
    int max = head->value;
    while (current != nullptr)
    {
        if (current->value > max) max = current->value;
        if (current->value < min) min = current->value;
        current = current->next;
    }
    product *= max * min;
    cout << "Our product: " << product << endl;
}

List* Init(int n)
{
    if(n <= 0) return nullptr;

    List* head = new List;
    cout << "Enter the value 1: ";
    cin >> head->value;
    head->next = nullptr;

    List* current = head;
    for (int i = 1; i < n; ++i)
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
