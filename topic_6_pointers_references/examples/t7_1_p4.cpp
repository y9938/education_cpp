#include <iostream>
using namespace std;

int main() 
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int* arr = new int [size];

	// Заполнение массива
	for (int i = 0; i < size; ++i)
	{
		*(arr + i) = i;
		cout << "Num: " << *(arr + i) << endl;
		// *(arr + i) == arr[i]
	}

	// Указатель на адрес первого элемента массива
	int* p = arr;
	int sum = 0;

	for (int i = 0; i < size; ++i, ++p) 
	{
		/* При ++p происходит:
			0x000001f9f9c42110 (адрес ячейки памяти) + 
			+ 1 (так как ++p увеличение на 1) и * на тип int = 4 byte
			Тем самым переход к следующей ячейке памяти, то есть к
			следующему элементу массива
		*/
		// '*p' - Разыменование указателя
		if (*p % 2 == 0)
		{
			sum += *p;
		}
	}
	cout << "\nSum: " << sum << endl;

	delete[] arr;

	return 0;
}
