#include "enum.h"

#include <iostream>

void enu::enu()
{
    std::cout << "-- Программа для определения дня недели --" << std::endl;
    int day = 0;

    std::cout << "enter number of day "; std::cin >> day;

    enum DaysOfWeek
    {
        Error,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    switch (day)
    {
    case Monday:
        std::cout << "Mon" << std::endl;
        break;
    case Tuesday:
        std::cout << "Tue" << std::endl;
        break;
    case Wednesday:
        std::cout << "Wed" << std::endl;
        break;
    case Thursday:
        std::cout << "Thu" << std::endl;
        break;
    case Friday:
        std::cout << "Fri" << std::endl;
        break;
    case Saturday:
        std::cout << "Sat" << std::endl;
        break;
    case Sunday:
        std::cout << "Sun" << std::endl;
        break;
    case Error:
        std::cout << "Err" << std::endl;
        break;
    default:
        std::cout << "Not" << std::endl;
        break;
    }

}