/*
 * Создайте перегруженную функцию sum, которая находит сумму двух целых чисел,
 * трех вещественных чисел и сумму кодов четырех символов
*/

#include <stdio.h>     
   
int sum(int a, int b); 
float sum(float a, float b, float c); 
int sum(char a, char b, char c, char d); 

int main()   
{  
    printf("Sum of two integers: %d\n", sum(2, 3));
    printf("Sum of three floats: %.2f\n", sum(3.5, 1.1, 5.2));
    printf("Sum of four characters: %i\n", sum('a', 'b', 'c', 'd'));
}

int sum(int a, int b)
{
    return a + b;
}

float sum(float a, float b, float c)
{
    return a + b + c;
}

int sum(char a, char b, char c, char d)
{
    return a + b + c + d;
}
