#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size);
void linear(const int arr[], int size, int key);
void binary_search_all_occurrences(int arr[], int size, int key);

int main() {
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
    cout << endl;

    cout << "Linear search:\n";
    linear(C, n, key);
    cout << "Binary search:\n";
    binary_search_all_occurrences(C, n, key);
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Линейный поиск первого вхождения
void linear(const int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == key)
        {
            cout << "Key " << key << " found at index " << i << "." << endl;
            return; // Завершаем функцию после нахождения первого вхождения
        }
    }
    // Если ключ не найден, выводим сообщение
    cout << "Key " << key << " not found in the array." << endl;
}

// Функция для бинарного поиска всех вхождений ключа
void binary_search_all_occurrences(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    int mid;
    bool found = false;

    // Классический бинарный поиск
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            found = true;
            break;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found)
    {
        // Найдено одно вхождение, теперь ищем все вхождения
        int first = mid;
        int last = mid;

        // Ищем влево от найденного индекса
        while (first > 0 && arr[first - 1] == key)
        {
            first--;
        }

        // Ищем вправо от найденного индекса
        while (last < size - 1 && arr[last + 1] == key)
        {
            last++;
        }

        // Выводим все вхождения
        cout << "Key " << key << " found at positions: ";
        for (int i = first; i <= last; ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Key " << key << " not found in the array." << endl;
    }
}
