#include "factorial.h"

#include <iostream>
#include <cstdlib>

void m_fact::factorial()
{
    unsigned int n = 0;
    int i = 1; //counter i=1...i=n
    //unsigned long long F = 1;
    double F = 1.0;
    std::cout << "<--factorial-->" << std::endl;
    std::cout << "enter number: "; std::cin >> n;

    if (n < 0) std::cout << "error::wrong_number::" << n << std::endl;
    else
    {
        if (!n) std::cout << "F = 1;" << std::endl;
        else
        {
            while (i <= n)
            {
                F *= i;
                i++;
                std::cout << "F " << i - 1 << "\t=\t" << F << std::endl;
            }
        }
    }

    std::cout << "Result: " << F << std::endl;
}