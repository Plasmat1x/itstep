#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

int main()
{
    int m_n = 0;
    int n = 0;
    int attempts = 3;
    char answer = 'Y';
    bool is_game = true;

    srand(time(NULL));

    while (is_game)
    {
        m_n = (rand() % 9 + 1);
        //std::cout << m_n << std::endl;

        for (int i = 1; i <= attempts; i++)
        {
            system("cls");
            std::cout << "<-magic number game                   ->" << std::endl;
            std::cout << "<-number from 1 to 9, attempts 5 times->" << std::endl;
            std::cout << "Attempt " << i << std::endl;
            std::cout << "Eneter number ";
            std::cin >> n;

            if (i == attempts && n != m_n) std::cout << "You lose" << std::endl;

            if (n == m_n) { std::cout << "You win" << std::endl; Sleep(2000); break; }
            else if (n > m_n) std::cout << "Less" << std::endl;
            else if (n < m_n) std::cout << "More" << std::endl;

            Sleep(2000);
        }

        std::cout << "One more time? Y/n " << std::endl;
        std::cin >> answer;

        if (answer == 'N' || answer == 'n')
        {
            is_game = false;
            Sleep(2000);
        }
    }

    Sleep(2000);
    return 0;
}

