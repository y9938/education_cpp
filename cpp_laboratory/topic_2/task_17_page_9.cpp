#include <iostream>

using namespace std;

int main() {
	int age;
	cout << "Введите возраст: ";
	cin >> age;

	if (age < 7) cout << "Дошкольник";
	else if (age < 18) cout << "Ученик";
	else if (age < 60) cout << "Работник";
	else if (age > 59) cout << "Пенсионер";
	else cout << "Возраст указан неверно";
}
