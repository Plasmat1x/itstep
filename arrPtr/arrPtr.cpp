/*
ДЗ. Дан массив из 20 целых чисел. Написать функцию: с помощью указателей, 
поменять местами элементы массива с четными и нечетными индексами 
(т.е. те элементы массива, которые стоят на четных местах, 
поменяйте с элементами, которые стоят на нечетных местах).
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

void swapi(int* arr, int size);

int main()
{
    srand(time(NULL));
    const int size = 20;
    int arr[size] = {};

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    
    swapi(arr, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;

    return 0;
}

void swapi(int* arr, int size)
{
    for (int i = 1; i < size; i += 2)
    {
        std::swap(arr[i], arr[i - 1]);
    }
}
