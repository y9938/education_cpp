/*
 Удаление слов в строке, если сумма ASCII-кодов символом слова меньше вводимого числа.
*/

#include <iostream>
#include <string>

using namespace std;

string filter(string st, int l);

int main()
{
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    
    int l;
    cout << "Enter the number: ";
    cin >> l;
    
    string str;
    for(int i = 0; i < n; ++i)
    {
        cout<<"Enter the string: ";
        getline(cin, str);
        cout<<"Result: "<<filter(str, l);
    }

    return 0;
}

string filter(string st, int l)
{
    int i = 0, begin = 0, end;
    st+=" ";
    while (i < st.size()-1)
    {
        while(st[i] == ' ' && i < st.size()-1)
        {
            ++i;
        }
        begin = i;
        while(st[i] != ' ' && i < st.size()-1)
        {
            ++i;
        }
        end = i;
        
        int wordlen = end - begin;
        int sum = 0;
        for(int j = begin; j < end; ++j)
        {
            sum += st[j];
        }
        if(sum < l)
        {
            st.erase(begin, wordlen);
            i -= wordlen;
        }
    }
    return st;
}
