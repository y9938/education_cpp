/*
Сформировать однонаправленный список из слов, содержащих цифры.
Сформировать двунаправленный список символов, заканчивая
ввод точкой. Слова в этом списке разделены пробелами. 
Выполнить указанные действия.
"hello1 world2 test."
Однонаправленный список: "hello1" и "world2".
Двунаправленный список: 'h','e','l','l','o','1',' ','w','o','r'..
*/

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

struct List
{
    int data;
    List* next;
};

List* Init(int N);
void print_list(List* head);

int main()
{
    int N;
    cout << "Enter the N: ";
    cin >> N;

    List* head = Init(N);
}

List* Init(int N)
{
    if (N <= 0) return nullptr;

    List* head = new List;
    cout << "Enter the data 1: ";
    cin >> head->data;
    head->next = nullptr;

    List* current = head;
    for (int i = 0; i < N; ++i)
    {
        List* new_node = new List;
        cout << "Enter the data " << i << ": ";
        cin >> new_node->data;
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
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
