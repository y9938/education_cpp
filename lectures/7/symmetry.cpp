#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int i = 0, begin = 0, end = 0;
    char str[100] = {}, sl[100] = {};
    cout << " InputLine: \n";
    cin.getline(str, 100, '\n');
    int len = strlen(str);
    cout << "Words:\n ";
    while (i < len)
        //цикл прохода по строке
    {
        while (str[i] == ' ' && i < len)
            ++i;
        //пропустить пробелы
        begin = i;
        // номер первого символа слова
        while (str[i] != ' ' && i < len)
            ++i;
        // пропустить все символы слова
        end = i;
        // номер символа, следующего за последним символом слова
        strncpy(sl, &str[begin], end - begin); //записать слово в массив
        sl[end - begin] = '\0';
        // добавить символ конца строки
        bool symmetric = true;
        int length = strlen(sl);
        for (int j = 0, k = strlen(sl) - 1; j < k; ++j, --k)
        {
            if (sl[j] != sl[k])
            {
                symmetric = false;
                break;
            }
        }
        if(symmetric)
            cout << sl << '\n';
            // вывод слова
    }
    return 0;
}
