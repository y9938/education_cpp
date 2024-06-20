#include <iostream>
using namespace std;

void shaker_sort(double arr[], int N)
{
    // Find the minimum value and its index
    double min_val = arr[0];
    int min_idx = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
            min_idx = i;
        }
    }

    // Perform shaker sort only up to the minimum element (exclusive)
    int left = 0, right = min_idx - 1;
    double t;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
            }
        }
        left++;
    }
}

int main()
{
    int N = 13;
    double arr[] = {9, 8, 7, 6, 5, 4, 2, 8, 9, 10, 28, 111, 12};

    // Output the original array
    cout << "Original array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort using shaker sort up to the minimum element
    shaker_sort(arr, N);

    // Output the sorted array
    cout << "Partially sorted array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
