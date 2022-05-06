// Sorting algorithms + searching algorithms 
#include <iostream>
#include <stdlib.h>
#include <time.h>

//sorting func
template<typename T>
bool ascending(T a, T b);

template<typename T>
bool descending(T a, T b);

template<typename T>
void select_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

template<typename T>
void bubble_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

template<typename T> 
void set(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

template<typename T>
void insert_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

template<typename T>
void shell_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

template<typename T>
void quick_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

/*
Дз. Реализовать алгоритм "Сортировка шейкер" -
написать шаблонную функцию с выбором направления
сортировки, проверить её и остальные
сортировки на массивах разных типов данных
V*/
template<typename T>
void shake_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T));

//search func
template<typename T>
unsigned int binary_search(T arr[], unsigned int size, T srch, bool (*comparsionFcn)(T, T));

//-------------------------------------------------------------------------//
int main()
{
    //---init---
    srand(time(NULL));
    std::cout << "<--sort array-->" << std::endl;

    const int size = 10;
    int iarr[size]{};
    float farr[size]{};

    char type = '<';

    for (int i = 0; i < size; i++)
    {
        iarr[i] = rand() % (100 - (-99)) - 99; //int
        farr[i] = (rand() % (100 - (-99)) - 99) + ((rand() % (100 - (-99)) - 99) * 0.01f); //float    
    }

    //---pre-render---
    for (int i = 0; i < size; i++)
        std::cout << "array[" << i << "] = " << iarr[i] << ";\n";
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
        std::cout << "array[" << i << "] = " << farr[i] << ";\n";
    std::cout << std::endl;

    //---control---
    std::cout << R"(
    Choose type sorting:
< - ascending
> - descending
)";
    std::cin >> type;

//select_sort(arr, size, ascending);
//bubble_sort(arr, size, ascending);
//insert_sort(arr, size, ascending);
//quick_sort(arr, size, ascending);
//shell_sort(arr, size, ascending);
//shake_sort(iarr, size, ascending);
//shake_sort(farr, size, ascending);

    if (type == '<')
    {
        quick_sort(iarr, size, ascending);
    }
    else if (type == '>')
    {
        quick_sort(iarr, size, descending);
    }
    
    //---render---
    for (int i = 0; i < size; i++)
        std::cout << "array[" << i << "] = " << iarr[i] << ";\n";
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
        std::cout << "array[" << i << "] = " << farr[i] << ";\n";
    std::cout << std::endl;

    int srch = 0;
    std::cin >> srch;
    std::cout << binary_search(iarr, srch, 15, ascending) << std::endl;

    return 0;
}

//-------------------------------------------------------------------------------------//
template<typename T>
bool ascending(T a, T b)
{
        return a < b;
}

template<typename T>
bool descending(T a, T b)
{
        return a > b;
}

template<typename T>
void select_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    for (unsigned int startIndex = 0; startIndex < size; ++startIndex)
    {
        int bestIndex = startIndex;

        for (unsigned int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (comparsionFcn(arr[bestIndex], arr[currentIndex]))
                bestIndex = currentIndex;
        }
        std::swap(arr[startIndex], arr[bestIndex]);
    }
}

template<typename T>
void bubble_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = 0; j < size - i - 1; j++)
        {
            if (comparsionFcn(arr[j], arr[j+1]))
            {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

template<typename T>
void set(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    T tmp = arr[0];
    int i = 0;
    for (i = 1; i < size; i++)
    {
        if (comparsionFcn(arr[i], tmp)) tmp = arr[i];
    }
    arr[0] = tmp;
}

template<typename T>
void insert_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    T b = arr[0];
    T tmp = 0;
    int i = 0;
    int j = 0;
    set(arr, size, *comparsionFcn);

    for (i = 1; i < size; i++)
    {
        tmp = arr[i];
        for (j = i - 1; comparsionFcn(tmp, arr[j]); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }

    for (j = 1; j < size && comparsionFcn(arr[j], b); j++)
    {
        arr[j - 1] = arr[j];
    }
    arr[j - 1] = b;
}

template<typename T>
void quick_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    int i = 0;
    int j = size - 1; 
    T p = arr[size / 2];
    T tmp = 0;

    do //while (i <= j)
    {

        while (comparsionFcn(arr[i], p)) 
            i++;
        while (comparsionFcn(p, arr[j])) 
            j--;

        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }

    } while (i <= j);

    if (j > 0) quick_sort(arr, j + 1, *comparsionFcn);
    if (i < size) quick_sort(arr + i, size - i, *comparsionFcn);
}

template <typename T> 
void shell_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    int i = 0;
    int j = 0;
    int step = 0;
    T tmp = 0;
    for (step = size / 2; step > 0; step /= 2)
    {
        for (i = step; i < size; i++)
        {
            for (j = i - step; j >= 0 && comparsionFcn(arr[j + step], arr[j]); j -= step)
            {
                tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
            }
        }
    }
}

/*
Дз. Реализовать алгоритм "Сортировка шейкер" -
написать шаблонную функцию с выбором направления
сортировки, проверить её и остальные
сортировки на массивах разных типов данных

V*/
template<typename T>
void shake_sort(T arr[], unsigned int size, bool (*comparsionFcn)(T, T))
{
    int l = 0;
    int r = size - 1;
    int flag = 1;
    T t = 0;

    while ((l < r) && flag > 0)
    {
        flag = 0;
        for (int i = l; i < r; i++)
        {
            if (comparsionFcn(arr[i + 1], arr[i]))
            {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = 1;
            }
        }
        r--;
        for (int i = r; i > l; i--)
        {
            if (comparsionFcn(arr[i], arr[i - 1]))
            {       
                t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;
            }
        }
        l++;
    }
}

//---------------------------------------------------------------------------------------//

template<typename T>
unsigned int binary_search(T arr[], unsigned int size, T srch, bool (*comparsionFcn)(T, T))
{
    unsigned int p = 0;
    unsigned int l = 0;
    unsigned int r = size;

    while (true)
    {
        p = (l + r) / 2;

        /*
        if (comparsionFcn(srch, arr[p]))
        {
            r = p - 1;
        }
        else if(comparsionFcn(arr[p], srch))
        {
            l = p + 1;
        }
        else
        {
            return p;
        }
        if (l > r)
        {
            return 0;
        }
        */

        if (srch < arr[p])
        {
            r = p - 1;
        }
        else if (srch > arr[p])
        {
            l = p + 1;
        }
        else
        {
            return p;
        }
        if (l > r)
        {
            return 0;
        }
    }
    return 0;
}