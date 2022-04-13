// MirrorArr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Написать функцию, меняющую порядок следования
элементов передаваемого ей массива
(10 элементов от -99 до 99) на
противоположный
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

void mirror(int* arr, int size);

int main()
{
    const int size = 10;
    int arr[size]{};

    std::cout << "<-Nirror array->" << std::endl;

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        do
        {
            arr[i] = rand() % (100 - (-99)) - 99;
        } while (arr[i] > -10 && arr[i] < 10);

        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    mirror(arr, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}

void mirror(int* arr, const int size)
{
    int* tmp = new int[size]();

    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }

    for (int i = 0, j = size-1; j >= 0; i++, j--)
    {
        arr[j] = tmp[i];
    }

    delete[] tmp;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
