#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>


void gym();
void frfr();

int main()
{
    //gym();
    //frfr();

    return 0;
}

void gym()
{
    std::cout << "<--forfor-->" << std::endl;

    unsigned int approaches = 0U;
    unsigned int repeats = 0U;

    std::cout << "Enter number of aproaches > ";
    std::cin >> approaches;

    std::cout << "Enter number of repeats > ";
    std::cin >> repeats;

    for (int i = 1; i <= approaches; i++)
    {
        std::cout << "Aprroach " << i << std::endl;
        for (int j = 1; j <= repeats; j++)
        {
            std::cout << "Repeats " << j << " repeats last " << repeats - j << std::endl;
            Sleep(500);
        }

        if (i <= repeats)
        {
            std::cout << "Approach " << i << " completed take rest 2 min" << std::endl;
            Sleep(2000);
        }
    }
    std::cout << "Completed" << std::endl;
}

void frfr()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            std::cout << "| " << j << " x " << i << " = " << i * j << "\t";
        }

        std::cout << std::endl;
    }
}