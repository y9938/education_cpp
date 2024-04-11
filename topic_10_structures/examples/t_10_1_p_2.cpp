/*
Создать  структуру  Картина  с  элементами 
Название,  Автор,  Цена.  Информацию  о нескольких
картинах прочитать из текстового файла. Пример содержимого
текстового файла (значения должны быть разделены пробелами,
табуляциями или переводом строки): Dali Vilabertran 20000000.00
Malevich Woodcutter 34560000.00 Klimt Sunflower 16500000.00 
*/

#include <iostream> 
#include <fstream> //для работы с файлами 
using namespace std; 

struct painting 
{  
    char title[100];  
    char author[100];  
    float price; 
}; 

int main() 
{  
    ifstream fin;  //файл для чтения  
    fin.open("e:\\инф.txt"); 
    if(!fin.is_open())  //если не удалось открыть файл  
    {   
        cout<<"Файл не найден";   
        return 1;  
    }  
    painting pic1;  
    painting pic2;  
    //записать в поля структур значения из файла  
    fin>>pic1.author>>pic1.title>>pic1.price;  
    fin>>pic2.author>>pic2.title>>pic2.price; 
    //вывод значений полей структуры   
    cout<<"Картина 1: "<<pic1.title<<" Художник: "<<pic1.author<<" Стоимость: "<< " Цена: "<<pic1.price<<endl;
    cout<<"Картина 2: "<<pic2.title<<" Художник: "<<pic2.author<<" Стоимость: "<< " Цена: "<<pic2.price<<endl;  
    //закрыть файл  
    fin.close();  
    return 0;
}