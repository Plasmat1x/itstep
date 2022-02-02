#include <iostream>
#include <cstdlib>

int main()
{
    /*
    “В первый день улитка проползла 15 см. Каждый следующий день она проползала на 2 см дальше, 
    чем в предыдущий день. Определить какое общее расстояние проползет улитка через N дней.(N вводит пользователь). 
    Примечание. Например,  пользователь ввел число 4. Следовательно, улитка ползла 4 дня, поэтому суммарный путь составит 72 см. 
    Под* решить эту задачу с помощью всех трех циклов, while, do while, for все три реализации должны работать по одной логике.”
    */

    //for loop
    system("cls");
    std::cout << "<--Ulitka-->(for)" << std::endl;
    int days = 0;
    std::cout << "Enter number of days "; std::cin >> days;

    int result = 0;
    for (int i = 1, d = 15; i <= days; i++, d += 2)
    {
        //if (days == 0) break; // for skip
        std::cout << "in day " << i << " distance " << d << " cm" << std::endl;
        result += d;
    }
    std::cout << "Total distance " << result << " cm" << std::endl;

    //while loop
    system("cls");
    std::cout << "<--Ulitka-->(while)" << std::endl;
    std::cout << "Enter number of days "; std::cin >> days;
    int iterator = 1;
    int distance_per_day = 15;
    result = 0;
    while (iterator <= days)
    {
        //if (days == 0) break; // for skip
        std::cout << "in day " << iterator << " distance " << distance_per_day << " cm" << std::endl;
        result += distance_per_day;
        distance_per_day += 2;
        iterator++;
    }
    std::cout << "Total distance " << result << " cm" << std::endl;

    //do while loop
    //не вижу/не чувствую разницы от while и for, лишь проверка условия в конце цикла а не сначала
    system("cls");
    std::cout << "<--Ulitka-->(do while)" << std::endl;
    std::cout << "Enter number of days "; std::cin >> days;
    iterator = 1;
    distance_per_day = 15;
    result = 0;
    do
    {
        //if (days == 0) break; // for skip
        std::cout << "in day " << iterator << " distance " << distance_per_day << " cm" << std::endl;
        result += distance_per_day;     
        distance_per_day += 2;
        iterator++;
    } while (iterator <= days);
    std::cout << "Total distance " << result << " cm" << std::endl;
}