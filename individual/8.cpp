/*
В заданном количестве строк исключить символы с кодом больше заданного числа.
*/

#include <iostream>
#include <cstring>

using namespace std;

void del(char st[][256], const int N, int num);

int main()
{
    const int N = 2;

    int n = 0;
    printf("Enter the number: ");
    cin >> n;
    cin.ignore();

    char st[N][256];
    cout << N << " Strings:" << endl;
    for(int i = 0; i < N; i++)
    {
        cin.getline(st[i], 256);
    }
    
    del(st, N, n);
    cout << "Resulting strings:" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << st[i] << endl;
    }
}

void del(char st[][256], const int N, int num)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        k = 0;
        for (j = 0; st[i][j] != '\0'; j++)
        {
            if (st[i][j] <= num)
            {
                st[i][k++] = st[i][j];
            }
        }
        st[i][k] = '\0';
    }
}
