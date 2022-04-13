// recursiveCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Ќаписать рекурсивную функцию подсчета количества
чисел в массиве из 20 случайных чисел, которые больше
заданного(введенного с клавиатуры).
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

int count = 0;

template<typename T>
void counter(T arr[], int size, T n)
{
    if (size < 0)
        return;

    if (arr[size] > n)
        count++;

    counter(arr, size - 1, n);
}

int main()
{
    srand(time(NULL));

    const int size = 20;
    int arr[size];
    int input_;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (100 - (-99)) - 99;
        std::cout << arr[i] << "\n";
    }
    std::cout << std::endl;

    std::cout << "enter number: ";
    std::cin >> input_;
    counter(arr, size - 1, input_);
    std::cout << count <<" elements more than "<< input_ << std::endl;

    return 0;
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
