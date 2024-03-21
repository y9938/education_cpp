/*
 * В заданном количестве строк исключить символы с кодом больше заданного числа.
*/

#include <iostream>
#include <cstring>

using namespace std;

void del(char strings[][256], const int N, int num)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        k = 0;
        for (j = 0; strings[i][j] != '\0'; j++)
        {
            if (strings[i][j] <= num)
            {
                strings[i][k++] = strings[i][j];
            }
        }
        strings[i][k] = '\0';
    }
}

int main()
{
    const int N = 1;

    int n = 0;
    printf("Enter the number: ");
    cin >> n;
    cin.ignore();

    char strings[N][256];
    cout << N << " Strings:" << endl;
    for(int i = 0; i < N; i++)
    {
        cin.getline(strings[i], 256);
    }
    
    del(strings, N, n);
    cout << "Resulting strings:" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << strings[i] << endl;
    }
}
