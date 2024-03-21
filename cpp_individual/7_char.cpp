#include <iostream> 
#include <cstring> 
#include <cctype> 

using namespace std; 
 
int main() 
{    
    char str[100] = {}, sl[100] = {}; 
     
    cout << "Input Line: "; 
    cin.getline(str, 100, '\n'); 
    strcat(str, " "); 
     
    int len = strlen(str); 
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
            strncat(sl, str + begin, end - begin); 
            strcat(sl, " "); 
        } 
    } 
    cout << sl << "\n"; 
     
    return 0; 
}
