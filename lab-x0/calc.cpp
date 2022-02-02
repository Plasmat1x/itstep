#include "calc.h"

#include <iostream>
#include <cstdlib>

// namespace для факториала
int i = 1;
unsigned long int result = 0;

unsigned long int mmath::factorial(unsigned long int x)
{
    if (x == 1 || x == 0)   // условие завершения рекурсии
        return 1;           // после выполнения условия код ниже не выполняется -> рекурсия прерывается
    else
    {
        i++;
        result = x * factorial(x - 1);
    }
    return result;
}

void m_calc::calc20()
{
    system("cls");
    std::cout << "---calc2 prog---" << std::endl;
    double a = 0;
    double b = 0;
    char op;
    std::cout << "enter number: "; std::cin >> a;

    bool _iswork = true; // булл для выхода из цикла;

    /*
    X - to stop cycle;

    суть данного решения в цикличности выполнения операций пока пользователь не завершит программу через операцию
    */

    while (_iswork) // вариант бесконечного цикла пока _iswork = true будет работать цикл
    {
        //system("cls");
        std::cout << "resault: " << a << std::endl;
        std::cout << R"(
'+' - Сложение
'-' - Вычитание
'*' - Умножение
'/' - Деление
'^' - Число А в степени В
'V' - Корень А-ой степени из В
'!' - Факториал числа А
'%' - остаток деления числа А на число B
)" << std::endl;
        std::cout << "enter operation: "; std::cin >> op; // при вводе +3 выполняется корректно

        switch (op)
        {
        case '+': //сложение b
            std::cout << "enter number: "; std::cin >> b;
            a += b;
            std::cout << a << std::endl;
            break;
        case '-': //вычитание b
            std::cout << "enter number: "; std::cin >> b;
            a -= b;
            std::cout << a << std::endl;
            break;
        case '*': //умножение на b
            std::cout << "enter number: "; std::cin >> b;
            a *= b;
            std::cout << a << std::endl;
            break;
        case '/': //деление на b
            std::cout << "enter number: "; std::cin >> b;
            if (b == 0) { std::cout << "error div 0 imposible" << std::endl; break; }
            a /= b;
            std::cout << a << std::endl;
            break;
        case '^': //возведение в степень b
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, b);
            std::cout << a << std::endl;
            break;
        case '%': //отстаток от деления на b
            std::cout << "enter number: "; std::cin >> b;
            a = int(a) % (int)b;
            std::cout << a << std::endl;
            break;
        case 'v':
        case'V': //корень степени b от числа
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, 1.0 / b);
            std::cout << a << std::endl;
            break;
            //*
        case'!': //факториал числа a
            //функция_рекурсии(a);
            a = mmath::factorial(a);
            std::cout << a << std::endl;
            break;
            //*/
        case 'x':
        case'X':
            _iswork = false; //условие выхода из цикла
            break;
        default:
            std::cout << "wrong operation!" << std::endl;
            break;
        }
    }
}