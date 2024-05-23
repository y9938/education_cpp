/*
Выполнить сортировку массива. Алгоритм сортировки:
вставкой: сортировка второй половины массива
обменом: сортировка элементов массива, расположенных
 перед максимальным элементом;
*/

#include <iostream>
using namespace std;

void print_arr(int arr[], int size);
void insertion_sort(int arr[], int size);
void bubble_sort(int arr[], int size);

int main() {
    int C[25];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array: ";
    for (int i = 0; i < n; ++i) cin >> C[i];

    insertion_sort(C, n);
    cout << "\nAfter sort: ";
    print_arr(C, n);

    bubble_sort(C, n);
    cout << "After sort: ";
    print_arr(C, n);
}

// Функция для вывода массива
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Сортировка вставкой второй половины массива
void insertion_sort(int arr[], int size)
{
    int start = (size + 1) / 2;
    for (int i = start; i < size; i++) 
    {
        int tmp = arr[i]; // Взятие неотсортированного элемента
        int j;
        for (j = i - 1; j >= start - 1 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j]; // Сдвиг элементов вправо
        arr[j + 1] = tmp; // Вставка элемента на нужное место
    }
}

// Сортировка обменом элементов перед максимальным элементом
void bubble_sort(int arr[], int size)
{
    int max = arr[0], index_max = 0;
    for (int k = 1; k < size; ++k)
    {
        if (arr[k] > max) 
        {
            max = arr[k];
            index_max = k;
        }
    }
    
    for (int i = 0; i < index_max - 1; ++i)
        for (int j = 0; j < index_max - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
