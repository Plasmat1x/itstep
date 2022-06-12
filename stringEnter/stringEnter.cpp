/*
ДЗ. Пользователь вводит строку с клавиатуры в фиксированный массив. 
Необходимо проверить, сколько элементов массива теперь занято печатными 
символами и сколько свободно, для добавления новых символов
*/

//https://snipp.ru/handbk/table-ascii

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main()
{
    system("chcp 1251");
    system("cls");

    char str[255]{};

    gets_s(str, 255);

    std::cout << str << std::endl;

    int it = 0;
    int printable = 0;
    int nonprintable = 0;
    while (str[it] != '\0')
    {
        if (str[it] > 31 || str[it] < 127)
            printable++;
        else
            nonprintable++;

        it++;
    }

    std::cout << "printable symbols = " << printable << std::endl;
    std::cout << "non printable = " << nonprintable << std::endl;
    std::cout << "symbols last with non print = " << 255 - (nonprintable + printable) << std::endl;
    std::cout << "sysmbols last with only printable = " << 255 - printable << std::endl;
}
