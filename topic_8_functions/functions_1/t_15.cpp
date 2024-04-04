/*
 * Даны три строки. Используя функцию, определить позицию самого первого вхождения заданного
 * символа в каждую из строк. Если строка не содержит символ, результатом работы функции должна быть –1.
*/

#include <iostream>
#include <string>
using namespace std;

void myGetLine(string& str);
int firstOccurrence(string& str, char symbol);

int main() 
{
    string str1, str2, str3;
    char symb;
    
    myGetLine(str1);
    myGetLine(str2);
    myGetLine(str3);
    
    cout<<"Enter a character to search for the first occurrence: ";
    cin>>symb;
    
    cout<<"First occurrence in str1: "<<firstOccurrence(str1, symb)<<endl;
    cout<<"First occurrence in str2: "<<firstOccurrence(str2, symb)<<endl;
    cout<<"First occurrence in str3: "<<firstOccurrence(str3, symb)<<endl;
    
    return 0;
}

void myGetLine(string& str)
{
    cout<<"Enter new string: ";
    getline(cin, str);
}

int firstOccurrence(string& str, char symbol)
{
    int length = str.length();
    for(int i=0; i<length; ++i)
    {
        if(str[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}
