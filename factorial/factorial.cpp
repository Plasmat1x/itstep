#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

namespace myMath
{
    int i = 1;
    unsigned long int result;

    unsigned long int factorial(unsigned long int x)
    {
        if (x == 1 || x == 0)
            return 1;

        i++;
        result = x * factorial(x - 1);

        return result;
    }
}

void t0()
{
    myMath::factorial(6);

    std::cout << myMath::result << std::endl;
}

int main()
{
    t0();
    return 0;
}