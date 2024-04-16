/*
Информацию о наличии на складе автомашин можно представить с помощью таких полей: модель 
(mk), год выпуска (yr), цвет (clr) и цена машины (prc). Описать структуру  avto. 
Создать файл из шести-семи записей, который содержит информацию об автомобилях. 
Вывести содержимое файла  на  экран  для  контроля.  Используя  созданный  файл, 
составить  программу  для  получения следующих сведений: 
а) Определить количество и вывести на экран названия моделей, которые выпускались в 1999 году. 
б) Вывести в файл Y информацию о машинах черного цвета, выпущенных за последние пять лет.  
в) Получить информацию о самой дорогой и самой дешевой машине. 
г) Получить информацию о самой старой и самой современной машине. 
д) Получить информацию о машинах данной модели и данного цвета.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_A = 50;

struct avto
{
    string mk; // marka
    int yr; // year
    string clr; // color
    double prc; // price
};

void out(ostream& os, avto& cs);

int main()
{
    ifstream in_f("../io_files/3_in.txt");
    ofstream out_f("../io_files/3_out.txt");
    
    avto cs[MAX_A]; // Массив машин
    int n = 0; // Реальное количество
    while (in_f >> cs[n].mk >> cs[n].yr >> cs[n].clr >> cs[n].prc)
    {
        out(cout, cs[n]);
        n++;
        if (n == MAX_A) break;
    }
    
    cout << "а:\n";
    int num = 0; // Количество машин 1999 года
    for (int i = 0; i < n; ++i)
    {
        if (cs[i].yr == 1999)
        {
            num++;
            cout << cs[i].mk << endl;
        }
        if ((cs[i].clr == "black") && cs[i].yr >= 2019)
        {
            out_f << "б: ";
            out(out_f, cs[i]);
        }
    }
    cout << "Number: " << num << endl;

    avto expensive = cs[0], cheap = cs[0], old = cs[0], new_car = cs[0];
    for (int i = 1; i < n; ++i)
    {
        if (cs[i].prc > expensive.prc) expensive = cs[i];
        if (cs[i].yr > new_car.yr) new_car = cs[i];
        if (cs[i].prc < cheap.prc) cheap = cs[i];
        if (cs[i].yr < old.yr) old = cs[i];
    }
    out_f << "в:\n" << "Expensive car: ";
    out(out_f, expensive);
    out_f << "Cheap car: ";
    out(out_f, cheap);
    out_f << "г:\n" << "Old car: ";
    out(out_f, old);
    out_f << "New car: ";
    out(out_f, new_car);

    string model, color;
    cout << "Enter the model and color: ";
    cin >> model >> color;
    out_f << "д:\n";
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (cs[i].mk == model && cs[i].clr == color)
        {
            out(out_f, cs[i]);
            found = true;
        }
    }
    if (!found)
        out_f << "Not found car" << endl;
}

// Печать данных авто в поток
void out(ostream& os, avto& cs)
{
    os << cs.mk << " " << cs.yr << " " << cs.clr << " " << cs.prc << endl;
}
