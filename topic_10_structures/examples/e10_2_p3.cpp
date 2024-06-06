/*
Создать структуру Дробь с элементами a – числитель,
b – знаменатель. Реализовать с дробями арифметическое сложение.
*/

#include <iostream>
#include <fstream> //для работы с файлами
using namespace std;

float Ppol(float c1,float c2,float z1,float z2)
{
    float f = 0;
    if(z1==z2) f=(c1+c2)/z1; 
    else if(z1!=z2) f=(c1*z2+c2*z1)/(z1*z2);
    return f;
}

struct tr
{
    float a,b;
};

int main()
{
    ifstream fin; //файл для чтения
    fin.open("io_files/10_2_p3_in.txt");
    if(!fin.is_open()) //если не удалось открыть файл
    {
        cout<<"Файл не найден";
        return 1;
    }
    tr d1,d2;
    while(!fin.eof()) //пока не конец файла
    {
        fin>>d1.a>>d1.b; //записать в поля структур значения из файла
        cout<<"дробь 1: "<<d1.a<<"/"<<d1.b<<endl;
        fin>>d2.a>>d2.b; //записать в поля структур значения из файла
        cout<<"дробь 2: "<<d2.a<<"/"<<d2.b<<endl;
        float s = Ppol(d1.a,d2.a,d1.b,d2.b);
        cout<<"сумма="<<s<<endl;
    }
    fin.close(); //закрыть файл
    return 0;
}