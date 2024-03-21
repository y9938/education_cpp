#include <iostream> 
#include <clocale> 

int main() {
    setlocale(LC_CTYPE, "RU");

    int num, d1, d2, d3, d4, s1, s2;
    std::cout << "Введите четырехзначное число = ";
    std::cin >> num;

    // поиск разрядов четырехзначного числа 
    d1 = num / 1000;
    d2 = num / 100 % 10;
    d3 = num / 10 % 10;
    d4 = num % 10;

    // вывод разрядов четырехзначного числа 
    std::cout << d1 << "\n";
    std::cout << d2 << "\n";
    std::cout << d3 << "\n";
    std::cout << d4 << "\n";

    // вычисление сумм 
    s1 = d1 + d4;
    s2 = d2 + d3;

    std::cout << "Сумма первого и последнего разрядов = " << s1 << "\n";
    std::cout << "Сумма второго и предпоследнего разрядов = " << s2 << "\n";
}
