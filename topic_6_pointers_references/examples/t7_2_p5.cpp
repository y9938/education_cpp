#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int* arr = new int[size];

	// Ввод массива
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; ++i)
	{
		cin >> *(arr + i);
	}

	int* p = arr;

	// Вывод массива
	cout << "Array: ";
	for (int i = 0; i < size; ++i, ++p)
	{
		cout << *p << " ";
	}
	cout << endl;

	p = arr;
	bool b = true;

	// Убывающая ли последовательность
	for (int i = 0; i < size - 1; ++i, ++p)
	{
		if (*(p + 1) > *p)
		{
			b = false;
			break;
		}
	}

	// Вывод сообщения с результатом
	if (b)
	{
		cout << "Array is in descending order.";
	}
	else
	{
		cout << "Array is not in descending order.";
	}
	cout << endl;

	delete[] arr;

	return 0;
}
