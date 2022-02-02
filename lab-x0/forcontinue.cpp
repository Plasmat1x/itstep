#include "forcontinue.h"

#include <iostream>
#include <cstdlib>

void forcontinue::forcontinue()
{
    std::cout << "--nechet 0..n" << std::endl;
    int n = 0;
    std::cout << "Enter n: "; std::cin >> n;
    int sum = 0;

    int j = 0;
    /*
    for (int i = 0; i <= n; i++)
    {
        if (!(i % 2)) continue;
        std::cout << i << std::endl;
        j++;
        sum += i;
    }
    */

    /* pomoika style
    for (int i = 1, j = 3; i < n && j >= 0; std::cout << "; ", sum +=i,j++, i+=2)
    {

    }
    */


    std::cout << "Count nechet " << j << std::endl;
    std::cout << "Result " << sum << std::endl;


}