/*
 * Даны символьные массивы С1(n) и С2(m). Определить общее число строчных гласных латинских букв
 * (a,e,i,o,u) в этих массивах
*/

#include <iostream>
using namespace std;

void printMatrix(int arr[], int p) 
{
    for (int i = 0; i < p; ++i) 
    {
        cout << arr[i] << " ";
    } 
    cout << endl;
}

void fillMatrixNumbers(char arr[], int p) 
{
    for (int i = 0; i < p; ++i)
        cin >> arr[i];
    cout << endl;
}

int isLetterVowel(char arr[], int p) 
{
    int counter = 0;
    char vowels[] = {'a','i','e','y','u','o'};
    for (int i = 0; i < p; ++i)
        for(int k = 0; k < 6; ++k)
            if (arr[i] == vowels[k])
                counter++;
    return counter;
}

int main() 
{
    char C1[3];
    char C2[3];
    cout<<"Input 1 array"<<endl;
    fillMatrixNumbers(C1,3);
    cout<<"Input 2 array"<<endl;
    fillMatrixNumbers(C2,3);
    int counter1= isLetterVowel(C1,3);
    int counter2 = isLetterVowel(C2,3);
    cout << "Кол-во гласных: в первой : " << counter1 << endl;
    cout << "Кол-во гласных во второй : " << counter2 << endl;
    return 0;
}
