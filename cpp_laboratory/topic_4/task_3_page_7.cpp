#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	const int size = 100;
	int number_array[size];
	int sum = 0;

	for (int i = 0; i < size; i++) {
		number_array[i] = rand() % 100;
	}
	
	int max = number_array[0];
	int min = number_array[0];
	int index_min = 0;
	int index_max = size - 1;

	for (int i = 0; i < size; i++) {
		if (number_array[i] > max) {
			max = number_array[i];
			index_max = i;
		}
		if (number_array[i] < min) {
			min = number_array[i];
			index_min = i;
		}
	}

	double temp;
	if (index_min > index_max) {
		temp = index_min;
		index_min = index_max;
		index_max = temp;
	}

	for (int i = index_min; i <= index_max; i++) {
		sum += number_array[i];
	}

	cout << "Минимальное значение: " << min << endl;
	cout << "Максимальное значение: " << max << endl;
	cout << "Сумма чисел между минимальным и максимальным: " << sum << endl;

	return 0;
}
