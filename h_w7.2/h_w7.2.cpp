#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>



//------------------------------------------------------------------------//
// 7 неделя
void w7t1();
void w7t2();
void w7t3();
void w7t4();

void w7l1(int* arr, int size);
void w7l2(int* arr, int size);
void w7l3(int* arr, int size);

// 6 неделя
void w6t1();
void w6t2();
void w6t3();
void w6t4();
void w6t5();
//------------------------------------------------------------------------//

int main()
{
    //Программное изменения шрифта для отображения псевдографики utf-8 в консоли (в моем случае позволяет выводит кириллицу в консоль после перехода системы на unicode) 
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 6;
    cfi.dwFontSize.X = 7;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = 54;
    cfi.FontWeight = 400;
#pragma warning(suppress : 4996)
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);
//------------------------------------------------------------------------//
    system("chcp 65001"); std::cout << std::endl;
//------------------------------------------------------------------------//
    
    //system("pause");

    //w7t1();
    //w7t2();
    //w7t3();
    //w7t4();

    int arr[10] = { 200,23,53,7,4,2,90,255,0,3 };

    //w7l1(arr, 10);
    //w7l2(arr, 10);
    //w7l3(arr, 10);

    //w6t1();
    //w6t2();
    //w6t3();
    //w6t4();
    w6t5();

//------------------------------------------------------------------------//
    Sleep(2000); return EXIT_SUCCESS;
}

void w7t1()
{
    /*
    Пользователь вводит число. Определить количество цифр
в этом числе, посчитать их сумму и среднее арифметическое.
Определить количество нулей в этом числе. Общение с поль-
зователем организовать через меню.
    */
    system("cls");
    std::cout << "<--number analyze-->" << std::endl;

    int number = 0;
    std::cout << "Enter number: "; std::cin >> number;
    
    int command = 0;
    

    while(true)
    {
        system("cls");
        std::cout << "Number " << number << std::endl;
        std::cout << R"(
    menu:
        1 - Count digits
        2 - Sum of digits
        3 - averge arythmetic from digits
        4 - Count of zeros
        5 - Reenter number
        0 - Exit
    )" << std::endl;

        std::cout << "Enter command: "; std::cin >> command;

        switch (command)
        {
        case 1:
        {
            int n = number;
            int c = 1;
            while ((n /= 10) > 0) c++;
            std::cout << "Count digits " << c << std::endl;
            Sleep(3000);
        }
            break;
        case 2:
        {
            int n = number;
            int c = 1;
            int r = 0;
            while ((n /= 10) > 0) c++;
            n = number;
            for (int i = 0; i < c; i++)
            {      
                r += n % 10;
                n /= 10;
            }
            std::cout << "Sum digits " << r << std::endl;
            Sleep(3000);
        }
            break;
        case 3:
        {
            int n = number;
            int c = 1;
            int r = 0;
            while ((n /= 10) > 0) c++;
            n = number;
            for (int i = 0; i < c; i++)
            {
                r += n % 10;
                n /= 10;
            }
            r /= c;
            std::cout << "Averge arythmetic digits " << r << std::endl;
            Sleep(3000);
        }
            break;
        case 4:
        {
            int n = number;
            int c = 1;
            int r = 0;
            while ((n /= 10) > 0) c++;
            n = number;
            for (int i = 0; i < c; i++)
            {
                if (n % 10 == 0) r++;
                n /= 10;

            }
            std::cout << "Count of zeros " << r << std::endl;
            Sleep(3000);
        }
            break;
        case 5:
            std::cout << "Enter new number "; std::cin >> number;
            break;
        case 0:
            return;
            break;
        default:
            std::cout << "wrong command" << std::endl;
            break;
        }


    }

    Sleep(3000);
}

void w7t2()
{
/* Написать программу, которая выводит на экран шахматную
доску с заданным размером клеточки.

Например,
***---***---***---***---
***---***---***---***---
***---***---***---***---
---***---***---***---***
---***---***---***---***
---***---***---***---***

8x8 */
    system("cls");
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { 80, 60 };
    system("mode con cols=80 lines=40");
    SetConsoleScreenBufferSize(hWnd, bufferSize);

//------------------------------------------------------------------------//
    std::cout   
                << "\t\t\t\t<--░░██░░██-->\n" //<< std::endl
                << "\t\t\t\t<--██░░██░░-->\n" //<< std::endl
                << "\t\t\t\t<--░░██░░██-->\n" //<< std::endl
                << "\t\t\t\t<--██░░██░░-->\n" //<< std::endl
                << "\t\t\t\t<-- Chess  -->\n";

    std::cout << std::setw(80) << std::setfill('_') << "_" << std::endl;
    std::cout << std::setfill(' ');
//------------------------------------------------------------------------//
    const unsigned short base_size = 8;
    unsigned short cell_size = 1;
    const char* field_type1 = "█"; // по заданию символы * и -
    const char* field_type2 = "░";
    bool render = true;

    std::cout << "Enter cell size: "; std::cin >> cell_size;
    std::cout << std::setw(80) << std::setfill('_') << "_" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::endl;
    std::cout << std::endl;

    if (cell_size < 1)
    {
        std::cout << "Chess field collapsing" << std::endl;
    }
    if (cell_size > 8)
    {
        std::cout << "It's too big, rendering will be wrong -> rendering aborted" << std::endl;
        render = false;
    }

    for (int i = 0; i < base_size && render; i++)
    {    
        //вертикальная отрисовка
        //for (int j = 0; j < cell_size; j++) // по заданию 
        for (int j = 0; j < cell_size / 2 ; j++) // + к восприятию
        {
            std::cout << "\t";
            if (i % 2)  // изменение порядка
            {
                for (int i = 0; i < base_size / 2 ; i++)
                {
                    for (int i = 0; i < cell_size; i++) //отрисовка '█'
                        std::cout << field_type1;
                    for (int i = 0; i < cell_size; i++) // затем '░'
                        std::cout << field_type2;
                }
            }
            else
            {
                for (int i = 0; i < base_size / 2; i++)
                {
                    for (int i = 0; i < cell_size; i++)
                        std::cout << field_type2;
                    for (int i = 0; i < cell_size; i++)
                        std::cout << field_type1;
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

//------------------------------------------------------------------------//
    system("pause");
    Sleep(3000);
    system("mode con cols=80 lines=25");
    bufferSize = { 80, 9000 };
    SetConsoleScreenBufferSize(hWnd, bufferSize);
}

void w7t3()
{
    /*
    Реализовать программу расчета заказа в кафетерии
при условии, что заказ может быть на несколько человек и
каждый клиент формирует свою часть заказа. Необходимо
спросить у пользователя на сколько человек заказ. Далее
каждому человеку выводиться меню (названия напитков,
кондитерских изделий и их цена) и он выбирает. Предусмот-
реть возможность выбора нескольких элементов меню для
клиента, если он желает добавить еще что-то в свой заказ.
Результат работы программы — итоговая сумма общего
заказа всей компании.
    
    "Предусмотреть возможность выбора нескольких элементов меню для клиента, если он желает добавить еще что-то в свой заказ." //??? Шта?
    
    1 ввод количество клиентов
    2 вывод меню нескольким клиентам //??? (в консоли реализация циклом for? на каждой итерации цикла обрабатываем одного клиента)
    3 ввод позиций
    4 расчет итогов
    5 вывод расчетов
    */
    system("cls");
    std::cout << "<--Coffee shop-->" << std::endl;

    //Реализация в другом файле

    Sleep(1500);
}

void w7t4()
{
    /*
    Есть пустое поле игры «Морской бой».
        Вывести в консоль номера полей игры :
    A0 B0 C0 D0 E0 F0 G0 H0 I0 J0
        A1 B1 C1 D1 E1 F1 G1 H1 I1 J1
        …..
        A9 B9 C9 D9 E9 F9 G9 H9 I9 J9
    */

    system("cls");
    std::cout << "<--Navy battle-->" << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            switch (i)
            {
            case 0:
                std::cout << "A" << j;
                break;
            case 1:
                std::cout << "B" << j;
                break;
            case 2:
                std::cout << "C" << j;
                break;
            case 3:
                std::cout << "D" << j;
                break;
            case 4:
                std::cout << "E" << j;
                break;
            case 5:
                std::cout << "F" << j;
                break;
            case 6:
                std::cout << "G" << j;
                break;
            case 7:
                std::cout << "H" << j;
                break;
            case 8:
                std::cout << "I" << j;
                break;
            case 9:
                std::cout << "J" << j;
                break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    Sleep(1500);
}

void w7l1(int* arr, int size)
{
    /*
    Задание 1. Написать функцию, определяющую минимум
и максимум (значение и номер) элементов передаваемого
ей массива.
    */
    system("cls");
    std::cout << "<--min max arr-->" << std::endl;

    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    int min_index = 0;
    int max_index = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (min > arr[i]) { min = arr[i]; min_index = i; }
        if (max < arr[i]) { max = arr[i]; max_index = i; }
    }
    std::cout << "Minimum " << min << " with index " << min_index << std::endl;
    std::cout << "Maximum " << max << " with index " << max_index << std::endl;


    Sleep(1500);
}

void w7l2(int* arr, int size)
{
    /*
    Задание 2. Написать функцию, меняющую порядок сле-
дования элементов передаваемого ей массива на проти-
воположный.
    */
    system("cls");
    std::cout << "<--Mirror array-->" << std::endl;

    std::cout << "before: " << std::endl;
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    int* tmp = new int[size];
    for (int i = 0; i < size; i++) tmp[i] = arr[i];
    for (int i = size - 1, j = 0; i >= 0; i--, j++) arr[j] = tmp[i];
    //или халтурно вывести массив в обратном порядке, но тогда в памяти измененй не будет.

    std::cout << "after: " << std::endl;
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] tmp;

    Sleep(1500);
}

bool prim(int n) 
{
    for (int d = 2; d <= n / 2; d++)
        if (n % d == 0)
            return false;
    return true;
}

void w7l3(int* arr, int size)
{
    /*
    Задание 3. Написать функцию, возвращающую количе-
ство простых чисел в передаваемом ей массиве.
    */
    system("cls");
    std::cout << "<--Prime numbers-->" << std::endl;

    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (prim(arr[i])) count++;
        if (arr[i] == 0 || arr[i] == 1) count--;
    }

    std::cout << "Count prime numbers " << count << std::endl;
    Sleep(1500);
}

void w6t1()
{
    /*
    Напишите программу, которая вычисляет сумму целых
чисел от а до 500 (значение a вводится с клавиатуры).
    */
    system("cls");
    std::cout << "<--sum n..500-->" << std::endl;

    int a = 0;
    std::cout << "Enter number a (a must be less than 500) "; std::cin >> a;
    int sum = 0;
    for (; a <= 500; a++)
    {
        sum += a;
    }
    std::cout << "Result "  << sum << std::endl;

    Sleep(1500);
}
void w6t2()
{
    /*
    Напишите программу, которая запрашивает два целых числа
x и y, после чего вычисляет и выводит значение x в степени y.
    */
    system("cls");
    std::cout << "<--pow | (x^y)-->" << std::endl;

    int x = 0, y = 0, r = 1;

    std::cout << "enter number x "; std::cin >> x;
    std::cout << "enter number y "; std::cin >> y;

    for (int i = 0; i < y; i++) r *= x;

    std::cout << "Result " << r << std::endl;

    Sleep(1500);
}
void w6t3()
{
    /*
    Найти среднее арифметическое всех целых чисел от 1 до 1000.
    */
    system("cls");
    std::cout << "<--averge arythmetic 1..1000-->" << std::endl;

    int r=0;

    for (int i = 1; i <= 1000; i++) r += i;

    r /= 1000;

    std::cout << "Resault " << r << std::endl;

    Sleep(1500);
}
void w6t4()
{
    /*
    Найти произведение всех целых чисел от a до 20 (значение
a вводится с клавиатуры: 1 <=a <= 20).
    */
    system("cls");
    std::cout << "<--mult of numbers a..20-->" << std::endl;
    
    int a = 0;
    unsigned long long r = 1;
    std::cout << "Enter number a (a > 0 & a <= 20) "; std::cin >> a;

    for (int i = a; i <= 20; i++) r *= i;

    std::cout << "Result " << r << std::endl;

    Sleep(1500);
}

void w6t5()
{
    /*
    Написать программу, которая выводит на экран таблицу
умножения на k, где k — номер варианта. Например, для 7-го
варианта:
7 x 2 = 14;
7 x 3 = 21.
    */
    system("cls");
    std::cout << "<--mult table-->" << std::endl;

    int k = 0;
    std::cout << "enter variant "; std::cin >> k;

    for (int i = 1; i < 10; i++)
    {
        std::cout << k << " x " << i << " = " << k * i << std::endl;
    }

    Sleep(1500);
}