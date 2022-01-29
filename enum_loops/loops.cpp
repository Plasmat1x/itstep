#include "loops.h"

#include <iostream>
#include <windows.h>

void lps::loops()
{
    /*
    std::cout << "--program phys--" << std::endl;

    int count = 0;
    int in = 0;

    std::cout << "enter number of required action "; std::cin >> in;

    //проверка на дурака если решат ввести отрицательное;
    while (count != in)
    {
        if (count < 0)
            count *= -1;

        std::cout << "up down "<< count + 1 << std::endl;

        count--;
    }

    std::cout << "complete!" << std::endl << std::endl;

    system("pause");
    system("cls");

    std::cout << "--program washing--" << std::endl;
    int number_of_object = 0;
    std::cout << "enter number of objects "; std::cin >> number_of_object;

    while (number_of_object >= 0)
    {
        if (number_of_object > 10)
        {
            std::cout << "to much" << std::endl;
            break;
        }

        if (number_of_object == 5)
        {
            std::cout <<"object " << number_of_object << " strong dirty" << std::endl;
            number_of_object--;
            continue;
        }

        if (number_of_object == 2)
        {
            std::cout << "next time continue!" << std::endl;
            break;
        }

        if (number_of_object == 0)
            std::cout << "completed!" << std::endl;
        else
            std::cout << "objects last " << number_of_object << std::endl;

        number_of_object--;
    }

    system("pause");
    system("cls");
    */

    std::cout << "--prog temperature--" << std::endl;
    float temperature = 100;

    do
    {
        std::cout << "enter temepature "; std::cin >> temperature;

        if (temperature >= 65)
            std::cout << "overheat " << std::endl;

        Sleep(5000);

    } while (temperature < 65);

    
        
}