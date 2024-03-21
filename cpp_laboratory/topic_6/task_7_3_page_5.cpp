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

	int min;
	bool hasOdd = false;
	int* p = arr;

	cout << "Array: ";
	for (int i = 0; i < size; ++i, ++p)
	{
		// Вывод элементов массива
		cout << *p << " ";

		// Ходим по нечетным числам в массиве
		if (*p % 2 != 0)
		{
			// Если нечетное число еще не найдено
			if (!hasOdd)
			{
				min = *p;
				hasOdd = true;
			}
			else
			{
				// Находим минимальное среди нечетных
				if (*p < min)
				{
					min = *p;
				}
			}
		}
	}
	cout << endl;

	// Сообщение с выводом минимального
	if (hasOdd)
	{
		cout << "Minimum number among the odd numbers: " << min;
	}
	// Если в массиве нет нечетных чисел
	else
	{
		cout << "There are no odd numbers in the array.";
	}
	cout << endl;

	delete[] arr;

	return 0;
}
