#include <iostream>

using namespace std;

int main() 
{
	int grade;
	cout << "Введите оценку: ";
	cin >> grade;

	switch (grade) {
	case 2:
		cout << "2 – «неудовлетворительно»";
		break;
	case 3:
		cout << "3 – «удовлетворительно»";
		break;
	case 4:
		cout << "4 – «хорошо»";
		break;
	case 5:
		cout << "5 – «отлично»";
		break;
	default:
		cout << "Не соответствующая оценка";
		break;
	}
}
