#include <iostream>  
#include <cstring>  
#include <cctype>  
  
using namespace std;  
  
int main()  
{     
    string str, sl;  
      
    cout << "Input Line: ";  
    getline(cin, str, '\n');  
    str += " ";  
      
    int len = str.size();  
    int i = 0, count = 0;  
      
    cout << "Result\n";  
    while (i < len - 1)  
    {  
        while ((isspace(str[i]) || ispunct(str[i])) && i < len - 1)  
            ++i;  
  
        int begin = i;  
        while (!isspace(str[i]) && !ispunct(str[i]) && i < len - 1)  
            ++i;  
  
        int end = i;  
          
        if (count++ % 2 == 0)  
        {  
            sl += str.substr(begin, end - begin) + " ";  
        }  
    }  
    cout << sl << "\n";  
      
    return 0;  
}
