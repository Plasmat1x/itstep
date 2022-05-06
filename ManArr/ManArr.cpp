#include <iostream>
#include <stdlib.h>
#include <time.h>

/*
ДЗ. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив С минимально возможного размера,
в котором нужно собрать элементы обоих массивов. 
Память выделенную под А и В нужно освободить, остаться должен только массив С.
*/

void draw(const int* arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

void gen(int* arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

int* arrMerge(const int* A, const int& sizeA, const int* B, const int& sizeB, int& sizeOut)
{
    sizeOut = sizeA + sizeB;
    int* arr = new int[sizeOut];

    for (int i = 0; i < sizeA; i++)
    {
        arr[i] = A[i];
    }

    for (int i = 0; i < sizeB; i++)
    {
        arr[sizeA + i] = B[i];
    }

    return arr;
}

int main()
{
    srand(time(NULL));

    int* A = nullptr;
    int* B = nullptr;
    int* C = nullptr;

    int sizeA = 0;
    int sizeB = 0;
    int sizeC = 0;

    std::cout << "-Array merge-\n" << std::endl;

    std::cout << "enter A array size: ";
    std::cin >> sizeA;
    A = new int[sizeA];
    gen(A, sizeA);
    draw(A, sizeA);
    std::cout << "\n";

    std::cout << "enter B array size: ";
    std::cin >> sizeB;
    B = new int[sizeB];
    gen(B, sizeB);
    draw(B, sizeB);
    std::cout << "\n";


    C = arrMerge(A, sizeA, B, sizeB, sizeC);
    delete[] A;
    delete[] B;

    draw(C, sizeC);
    std::cout << "\n";

    delete[] C;
    return 0;
}
