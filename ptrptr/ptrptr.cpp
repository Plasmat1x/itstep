/*
Написать Функцию, с помощью указателя на указатель, 
удаляющую из массива случайных целых чисел 
все положительные нечетные элементы.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

void positiveNotEvenDel(int** arr, int& size);

int main()
{
    srand(time(NULL));

    int size = 0;
    int** arr = nullptr;

    std::cout << "Enter size: ";
    std::cin >> size;

    int* ptr = nullptr;
    ptr = new int[size];
    arr = &ptr;

    for (int i = 0; i < size; i++)
    {
        (* arr)[i] = rand() % (100 - (-99)) - 99;
        std::cout << (* arr)[i] << "  ";
    }
    std::cout << "\n" << std::endl;
    
    positiveNotEvenDel(arr, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << (*arr)[i] << "  ";
    }
    std::cout << "\n" << std::endl;

    delete[] *arr;
    return 0;
}

void positiveNotEvenDel(int** arr, int& size)
{
    int* nptr = nullptr;
    int nsize = 0;

    for (int i = 0; i < size; i++)
    {
        if (!(*(*arr + i) % 2) || *(*arr + i) <= 0) nsize++;
    }

    nptr = new int[nsize];

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(*(*arr + i) % 2) || *(*arr + i) <= 0) nptr[j++] = *(*arr + i);
    }

    if (*arr) { delete[] * arr; *arr = nullptr; }
    
    size = nsize;
    *arr = nptr;
}
