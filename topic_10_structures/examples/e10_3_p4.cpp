/*
Создать структуру Книга: название, имя автора, цена,
количество экземпляров книги в книжном магазине. Найти самую
дорогую книгу. Создать новый файл с информацией о книгах,
упорядоченной по полю «количество экземпляров» 
(отсортировать массив структур).
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct book
{
    string title;
    string author;
    float price;
    int count;
};

// сортировка массива структур по полю «количество экземпляров»
void sort(book arr[], int size)
{
    for (int i=size-1; i > 0; --i)
        for (int j=0; j < i; ++j)
            if (arr[j].count>arr[j+1].count)
            {
                book tmp = arr [j];
                arr [j] = arr [j+1];
                arr [j+1] = tmp;
            }
}

// поиск самой дорогой книги
void max_price(book arr[], int size) 
{
    float max = arr[0].price;
    string max_title = arr[0].title;
    string max_author = arr[0].author;
    for (int j = 1; j < size; ++j) {
        if (max < arr[j].price) {
            max = arr[j].price;
            max_title = arr[j].title;
            max_author = arr[j].author;
        }
    }
    cout << "\nСАМАЯ ДОРОГАЯ КНИГА - " << max_title << " " << max_author << " ЕЕ ЦЕНА " << max << "\n";
}

int main()
{
    ifstream fin("../io_files/10_3_p4_in.txt"); //исходный файл
    ofstream bookf; //файл для записи отсортированного массива
    bookf.open("../io_files/10_3_p4_out.txt");
    if(!fin.is_open())
    {
        cout<<"Файл не найден";
        return 1;
    }
    book b[10]; //массив из 10 структур book
    int N=0; //первое значение в файле - размер массива структур
    fin>>N;
    fin.ignore(); // Пропустить символ новой строки после чтения N
    for (int i = 0; i < N; i++) 
    {
        getline(fin, b[i].title); // Чтение названия книги
        getline(fin, b[i].author); // Чтение имени автора
        fin >> b[i].price; // Чтение цены
        fin >> b[i].count; // Чтение количества экземпляров
        fin.ignore(); // Пропустить символ новой строки после чтения числа
    }
    cout<<"ИСХОДНЫЙ МАССИВ\n\n";
    cout<<setw(25)<<left<<"title"<<setw(10)<<left<<"author"<<"\t"<<"price"<<"\t"<<"count"<<"\n\n";
    //вывод массива на экран
    for(int i = 0; i < N; i++)
        cout<<setw(25)<<left<<b[i].title<<setw(10)<<left<<b[i].author<<"\t"<<b[i].price<<'\t'<<b[i].count<<'\n';
    sort(b, N);
    cout<<"\nМАССИВ ОТСОРТИРОВАННЫЙ ПО ПОЛЮ count\n\n";
    //вывод массива на экран и запись в файл
    for(int i = 0; i < N; i++)
    {
        cout<<setw(25)<<left<<b[i].title<<setw(10)<<left<<b[i].author<<"\t"<<b[i].price<<'\t'<<b[i].count<<'\n';
        bookf<<setw(25)<<left<<b[i].title<<setw(10)<<left<<b[i].author<<'\t'<<b[i].price<<'\t'<<b[i].count<<'\n';
    }
    max_price(b, N);
    fin.close(); //закрыть файл
    bookf.close();
    return 0;
}
