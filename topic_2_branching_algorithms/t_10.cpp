#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int k;
	cout << "Введите трехзначное число: ";
	cin >> k;

	if (k < 100 || k >= 1000) {
		cout << "Число не трехзначное\n";
		return 1;
	}

	int ones, tens, hundreds;
	hundreds = k / 100;
	tens = (k / 10) % 10;
	ones = k % 10;

	int sum_of_digits_cubed = pow(ones + tens + hundreds, 3);

	if (sum_of_digits_cubed == pow(k, 2))
		cout << "Да, квадрат числа равен кубу суммы цифр этого числа\n";
	else cout << "Нет, квадрат числа не равен кубу суммы цифр этого числа\n";

	return 0;
}
