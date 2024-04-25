#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size);

int main() {
    int a[100];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    int key;
    cout << "Key = ";
    cin >> key; // Ввод значения для поиска

    bubble_sort(a, n);
    cout << "\nAfter sort: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }

    // Линейный поиск последнего вхождения
    int ind_l = -1; // Индекс последнего вхождения ключа, -1 означает, что ключ не найден
    for (int i = n - 1; i > 0; --i) 
    {
        if (a[i] == key)
        {
            ind_l = i; // Обновляем индекс последнего вхождения
            break;
        }
    }
    if (ind_l != -1)
        cout << "\nLast occurrence = " << ind_l + 1 << endl;
    else
        cout << "\nThere is no such element!" << endl;

    // Интерполяционный поиск первого вхождения
    int l = 0, r = n - 1, s; // Индексы левой и правой границ поиска, s - индекс текущего элемента
    bool found = false;
    while ((l <= r) && !found) 
    { 
        s = l + (key - a[l]) * (r - l) / (a[r] - a[l]); // Вычисляем позицию для проверки
        if (a[s] == key) 
            found = true;
        else if (a[s] < key) 
            l = s + 1;
        else 
            r = s - 1;
    }
    if (found)
        cout << "First occurrence at position = " << s + 1 << "\n";
    else
        cout << "Element not found!\n";
}

void bubble_sort(int arr[], int size)
{
    for (int i = size - 1; i > 0; --i) 
        for (int j = 0; j < i; ++j) 
            if (arr[j] > arr[j+1]) 
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}
