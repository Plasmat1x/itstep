// overloadTemp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Дз. Реализуйте перегруженные функции для
Нахождения максимального значения двух целых
чисел; Нахождения максимального значения трёх
целых чисел.Нахождения максимального значения
четырех целых чисел. Под* сделать перегруженные
функции шаблонными
*/

#include <iostream>

template<typename T>
T max(T a, T b );

template<typename T>
T max(T a, T b, T c);

template<typename T>
T max(T a, T b, T c, T d);


int main()
{
    std::cout << max(10, -3) << std::endl;
    std::cout << max(8, 11, 13) << std::endl;
    std::cout << max(3.5, 3.6, 2.4, 0.4) << std::endl;

    return 0;
}


template<typename T>
T max(T a, T b)
{
    T result = (a > b ? a : b);

    return result;
}

template<typename T>
T max(T a, T b, T c)
{
    T result = max(a, b);
    result = (result > c ? result : c);

    return result;
}

template<typename T>
T max(T a, T b, T c, T d)
{
    T result = max(a, b, c);
    result = (result > d ? result : d);

    return result;
}
// Но зависимость функций

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
