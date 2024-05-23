/*
Выполнить поиск заданного значения в массиве
Линейный поиск: последнее вхождение
Двоичный поиск (метод интерполяции): первое вхождение
*/

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size);
int liner(const int arr[], int size, int key);
int interpolation(const int arr[], int size, int key);

int main() 
{
    int C[25];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array: ";
    for (int i = 0; i < n; ++i) cin >> C[i];

    int key;
    cout << "Key = ";
    cin >> key; // Ввод значения для поиска

    bubble_sort(C, n);
    cout << "\nAfter sort: ";
    for (int i = 0; i < n; ++i)
    {
        cout << C[i] << " ";
    }

    int ind_l = liner(C, n, key);
    if (ind_l != -1)
        cout << "\nLast occurrence = " << ind_l + 1 << endl;
    else
        cout << "\nThere is no such element!" << endl;

    int ind_i = interpolation(C, n, key);
    if (ind_i != -1)
        cout << "First occurrence at position = " << ind_i + 1 << "\n";
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

// Линейный поиск последнего вхождения
int liner(const int arr[], int size, int key)
{
    int ind_l = -1; // Индекс последнего вхождения ключа, -1 означает, что ключ не найден
    for (int i = size - 1; i > 0; --i) 
    {
        if (arr[i] == key)
        {
            ind_l = i; // Обновляем индекс последнего вхождения
            break;
        }
    }
    return ind_l;
}

// Интерполяционный поиск первого вхождения
int interpolation(const int arr[], int size, int key)
{
    int l = 0, r = size - 1, s; // Индексы левой и правой границ поиска, s - индекс текущего элемента
    while ((l <= r))
    {
        s = l + (key - arr[l]) * (r - l) / (arr[r] - arr[l]); // Вычисляем позицию для проверки
        if (arr[s] == key) 
            return s;
        else if (arr[s] < key) 
            l = s + 1;
        else 
            r = s - 1;
    }
    return -1;
}
