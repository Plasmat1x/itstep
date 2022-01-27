#include <cstdlib>
#include <iostream>
#include <cmath>

int main()
{
    system("chcp 1251");
    system("cls");

    /*
    if (true) { ; }
    else if (false) { ; }
    else { ; }
    */

    float sum = 0.0f;
    float discount = 0.0f;
    float to_disc = 0.0f;

    std::cout << "discount " << std::endl;
    std::cout << "sum "; std::cin >> sum;

    if (sum < 1)
    {
        std::cout << "wrong sum" << std::endl;
        return EXIT_FAILURE;
    }

    if (sum < 1000)                     { discount = 0.00f;     to_disc = 1000 - sum; }
    else if (sum >= 1000 && sum < 2000) { discount = 0.05f;     to_disc = 2000 - sum; }
    else if (sum >= 2000 && sum < 3000) { discount = 0.10f;     to_disc = 3000 - sum; }
    else if (sum >= 3000 && sum < 4000) { discount = 0.15f;     to_disc = 4000 - sum; }
    else if (sum >= 4000 && sum < 5000) { discount = 0.20f;     to_disc = 5000 - sum; }
    else if (sum >= 5000 && sum < 6000) { discount = 0.25f;     to_disc = 6000 - sum; }
    else if (sum >= 6000 && sum < 7000) { discount = 0.30f;     to_disc = 7000 - sum; }

    std::cout << "discount " << discount * 100.0f << "% to next discount " << to_disc << " to pay: " << sum * (1.0f - discount) << std::endl;

    system("chcp 866");
    return EXIT_SUCCESS;
}