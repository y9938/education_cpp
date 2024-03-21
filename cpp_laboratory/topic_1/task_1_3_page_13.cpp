#include <iostream> 
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int num, d1, d2, d3, product;
    cout << "Введите трехзначное число = ";
    cin >> num;

    if (num < 100 || num > 999) {
        cout << "Введено некорректное трехзначное число. \n";
        return 1; // Возврат ненулевого значения при ошибке
    }

    // Нахождение разрядов
    d1 = num / 100;
    d2 = (num / 10) % 10;
    d3 = num % 10;

    // Произведение цифр
    product = d1 * d2 * d3;
    
    cout << "Цифры числа: " << d1 << ", " << d2 << ", " << d3 << "\n";
    cout << "Произведение его цифр равно: " << product;

    return 0;
}
