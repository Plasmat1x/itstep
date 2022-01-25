#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
    bool is_run = true;

    unsigned int dt = 0;
    unsigned int start_time = 0;
    unsigned int end_time = 0;

    unsigned int runtime = 0;
    unsigned int timer1 = 0;

    while (is_run)
    {   
        if (runtime / 1000 >= 6.0)  //after 30 sec end cycle
        {
            is_run = false;
        }

        start_time = std::clock();

        //eleapsed time cout
        system("cls");
        std::cout << (double)runtime / 1000.0 << " s" << std::endl;
        std::cout << (double)timer1 / 1000.0 << " s" << std::endl;
        
        if (timer1 >= 2000)
        {
            std::cout << "message " << runtime / 1000 << " s" << std::endl;
            timer1 -= timer1;
        }

        end_time = std::clock();
        dt = end_time - start_time;

        runtime += dt;
        timer1 += dt;
    }

    return EXIT_SUCCESS;
}
