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
    bool hard_mode = false;

    srand(time(NULL));

    while (is_game)
    {
        m_n = (rand() % 9 + 1);

        std::cout << "<-magic number game                   ->" << std::endl;
        std::cout << "<-number from 1 to 9, attempts " << attempts << " times->" << std::endl;
        std::cout << "choose game difficult 0 - easy, 1 - hard" << std::endl;
        std::cin >> hard_mode;

        for (int i = 1; i <= attempts; i++)
        {
            system("cls");
            std::cout << "<-magic number game                   ->" << std::endl;
            std::cout << "<-number from 1 to 9, attempts " << attempts << " times->" << std::endl;
            std::cout << "Difficult " << hard_mode << std::endl;
            std::cout << "Attempt " << i << std::endl;
            std::cout << "Eneter number ";
            std::cin >> n;

            if (i == attempts && n != m_n) std::cout << "You lose" << std::endl;

            if (n == m_n) { std::cout << "You win" << std::endl; Sleep(2000); break; }
            else if (n > m_n && !hard_mode) std::cout << "Less" << std::endl;
            else if (n < m_n && !hard_mode) std::cout << "More" << std::endl;

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