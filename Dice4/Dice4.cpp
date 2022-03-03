#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
// покер на костях

void dice_throw(int& n)
{
    n = rand() % 6 + 1;
}

void dice_v(int n, int i)
{
    switch (n)
    {
    case 1:
    {
        switch (i)
        {
        case 1:
            std::cout << "|     | ";
            break;
        case 2:
            std::cout << "|  *  | ";
            break;
        case 3:
            std::cout << "|     | ";
            break;
        }
        break;
    }
    case 2:
    {
        switch (i)
        {
        case 1:
            std::cout << "|    *| ";
            break;
        case 2:
            std::cout << "|     | ";
            break;
        case 3:
            std::cout << "|*    | ";
            break;
        }
        break;
    }
    case 3:
    {
        switch (i)
        {
        case 1:
            std::cout << "|    *| ";
            break;
        case 2:
            std::cout << "|  *  | ";
            break;
        case 3:
            std::cout << "|*    | ";
            break;
        }
        break;
    }
    case 4:
    {
        switch (i)
        {
        case 1:
            std::cout << "|*   *| ";
            break;
        case 2:
            std::cout << "|     | ";
            break;
        case 3:
            std::cout << "|*   *| ";
            break;
        }
        break;
    }
    case 5:
    {
        switch (i)
        {
        case 1:
            std::cout << "|*   *| ";
            break;
        case 2:
            std::cout << "|  *  | ";
            break;
        case 3:
            std::cout << "|*   *| ";
            break;
        }
        break;
    }
    case 6:
    {
        switch (i)
        {
        case 1:
            std::cout << "|*   *| ";
            break;
        case 2:
            std::cout << "|*   *| ";
            break;
        case 3:
            std::cout << "|*   *| ";
            break;
        }
        break;
    }
    }
}

int main()
{
    srand(time(NULL));
    std::cout << "<--Dice-->" << std::endl;

    bool is_game = false;
    int cash = 0;
    int bet = 0;
    int dice_game_size = 2;
    int player_sum = 0;
    int ai_sum = 0;
    std::vector<int> player_dices;
    std::vector<int> ai_dices;

    while (true)
    {
        std::cout << "Enter your total cash: ";
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
        std::cout << "<--Dice_Game-->" << std::endl;
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
        cash -= bet;

        player_dices.resize(dice_game_size);
        ai_dices.resize(dice_game_size);


        // player part ==================================================================
        std::cout << "player: ";
        for (int i = 0; i < dice_game_size; i++) //throwing
        {
            dice_throw(player_dices[i]);
            player_sum += player_dices[i];
        }
        // test
        for (int i = 0; i < player_dices.size(); i++)   //result drawing
        {
            std::cout << player_dices[i] << " " ;
        }
        std::cout << " = " << player_sum;
        std::cout << std::endl;
        //end test
        for (int i = 0; i < 5; i++) //dice drawing 
        {
            for (int j = 0; j < dice_game_size; j++)
            {
                if (i == 0 || i == 4)
                {
                    std::cout << " - - -  ";
                }
                dice_v(player_dices[j], i);
            }
            std::cout << std::endl;
        }
        // player part ================================================================== end

        // ai part ==================================================================
        std::cout << std::endl << "AI: ";
        for (int i = 0; i < dice_game_size; i++)
        {
            dice_throw(ai_dices[i]);
            ai_sum += ai_dices[i];
        }

        // test
        for (int i = 0; i < player_dices.size(); i++)
        {
            std::cout << ai_dices[i] << " ";
        }
        std::cout << " = " << ai_sum;
        std::cout << std::endl;
        //end test

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < dice_game_size; j++)
            {
                if (i == 0 || i == 4)
                {
                    std::cout << " - - -  ";
                }
                dice_v(ai_dices[j], i);
            }
            std::cout << std::endl;
        }
        // ai part ================================================================== end

        //* На доработку / переработку 
        if (ai_sum == player_sum)
        {
            std::cout << "\nDRAW" << std::endl;
            player_sum = 0;
            ai_sum = 0;
        }
        else if (ai_sum < player_sum)
        {
            std::cout << "\nPLAYER WIN" << std::endl;
            cash += bet * 2;
            player_sum = 0;
            ai_sum = 0;
        }
        else //ai > player
        {
            std::cout << "\nPLAYER LOSE" << std::endl;
            player_sum = 0;
            ai_sum = 0;
            if (cash == 0)
            {
                std::cout << "you have not enough for next game " << std::endl;
                is_game = false;
            }
        }
        //*/
        system("pause");
    }
    Sleep(1500);

}
