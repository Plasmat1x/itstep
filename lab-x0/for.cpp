#include "for.h"

#include <iostream>
#include <cstdlib>

void mfor::my_for()
{   
    std::cout << "<-for loop->" << std::endl;

    int n = 15; 

    for (int i = 1; i <= n; i++)
    {
        std::cout << "Action A \t" << i << " \ttimes" << std::endl;
    }

    //int i;
    //for(i = 0; ; )
    //{ 
    //  if(i < 15) break; 
    //  i++;
    //}
    std::cout << std::endl;

    int j = 0;
    for (; j < 7; j++)
    {
        std::cout << "Action B \t" << j << "\ttimes" << std::endl;
    }
    std::cout << "count B \t\t" << j << "\ttimes" << std::endl;

    std::cout << std::endl;

    for (; j <= 15;)
    {
        std::cout << "Action C \t" << j << "\ttimes" << std::endl;
        j++;
    }
    std::cout << "count C \t\t" << j << "\ttimes" << std::endl;

    std::cout << std::endl;

    int k = 0;
    for (; ;)
    {
        k++;
        std::cout << "Action D \t" << k << "\ttimes" << std::endl;
        if (k == 25) break;
    }
    std::cout << "count D \t\t" << k << "\ttimes" << std::endl;

    float T = 100.0f;
    for (; ;)
    {
        std::cout << "Enter T \t";
        std::cin >> T;
        if (T >= 65) break;
    }
}