// Dice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>



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
        
        system("pause");
        player = rand() % 6 + 1;
        ai = rand() % 6 + 1;

        std::cout << "Player dice = " << player << std::endl;
        std::cout << "AI dice = " << ai << std::endl;

        switch (player)
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

        switch (ai)
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

        while (ai == player)
        {
            player = rand() % 6 + 1;
            ai = rand() % 6 + 1;

            std::cout << "Player dice = " << player << std::endl;
            std::cout << "AI dice = " << ai << std::endl;

            switch (player)
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

            switch (ai)
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
