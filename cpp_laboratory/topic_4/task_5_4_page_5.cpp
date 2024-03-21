#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array (up to 25): ";
    cin >> n;

    const int SIZE = 25;
    int a[SIZE] = {};

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    int t, r;
    for (t = 0; t < k; t++) {
        r = a[n - 1]; // Сохраняем последний элемент массива
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i - 1]; // Сдвигаем элементы массива вправо
        }
        a[0] = r; // Помещаем сохраненный элемент в начало массива
    }

    cout << "Array after cyclic shift to the right: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
