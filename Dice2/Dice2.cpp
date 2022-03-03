#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void dices(int p)
{
    switch (p)
    {
    case 1:
        std::cout << R"(
 - - -  
|     |
|  *  |
|     |
 - - - 
)";
        break;
    case 2:
        std::cout << R"(
 - - -  
|    *|
|     |
|*    |
 - - - 
)";
        break;
    case 3:
        std::cout << R"(
 - - -  
|    *|
|  *  |
|*    |
 - - - 
)";
        break;
    case 4:
        std::cout << R"(
 - - -  
|*   *|
|     |
|*   *|
 - - - 
)";
        break;
    case 5:
        std::cout << R"(
 - - -  
|*   *|
|  *  |
|*   *|
 - - - 
)";
        break;
    case 6:
        std::cout << R"(
 - - -  
|*   *|
|*   *|
|*   *|
 - - - 
)";
        break;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    std::cout << "<--Dice-->" << std::endl;

    bool is_game = false;

    int player = 0;
    int ai = 0;
    int cash = 0;
    int bet = 0;

    while (true)
    {
        std::cin >> cash;

        if (cash <= 0)
        {
            std::cout << "Wrong number" << std::endl;
            continue;
        }

        is_game = true;

        break;
    }

    while (is_game)
    {
        system("cls");
        std::cout << "<--Dice->Game-->" << std::endl;
        std::cout << "Cash = " << cash << std::endl;

        do
        {
            std::cout << "Make bet ";
            std::cin >> bet;
            if (bet < 0) std::cout << "wrong" << std::endl;
            else if (bet > cash) std::cout << "to much when you have" << std::endl;
            else if (bet == 0) is_game = false;
            else std::cout << "Bet  accepted" << std::endl;
        } while (bet < 0 || bet > cash);

        do 
        {
            system("pause");
            player = rand() % 6 + 1;
            ai = rand() % 6 + 1;

            dices(player);
            dices(ai);

            if (ai == player)
            {
                std::cout << "draw" << std::endl;
            }
        } while (ai == player);
                
        if (player > ai)
        {
            std::cout << "player win" << std::endl;
            cash += bet * 2;
        }
        else //player < ai
        {
            std::cout << "player lose" << std::endl;
            cash -= bet;
            if (cash == 0)
            {
                std::cout << "you have not enough for next game " << std::endl;
                is_game = false;
            }
        }
        
        system("pause");
    }
    Sleep(1500);
}