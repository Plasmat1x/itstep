/*
“Добавить в программу управления роботом промежуточные направления (Северо-Запад, Юго-Восток и тд.) при команде повернуть направо, 
направление должно меняться с учетом промежуточных направлений(робот смотрел на север, повернули на право робот смотрит на северо-восток)”
*/

#include <iostream>
#include <cstdlib>
#include <Windows.h>

int main()
{
    system("chcp 65001"); std::cout << std::endl;

    std::cout << "---robot control 2.0---" << std::endl;

    enum Commands
    {
        STOP = 00,
        LEFT = 01,
        RIGHT = 10,
        FORWARD = 11
    };

    int command = 0;
    bool is_work = true;
    int direction;

    enum directions
    {
        n   = 1,
        ne  = 2,
        e   = 3,
        se  = 4,
        s   = 5,
        sw  = 6,
        w   = 7,   
        nw  = 8
    };

    do
    {

        system("cls");

        std::cout << R"(
                        menu:   0 - Exit
                        1 - North
                        2 - North-East
                        3 - East
                        4 - South-East
                        5 - South
                        6 - South-West
                        7 - West
                        8 - North-West)";

        std::cout << "Enter direction: "; 
        std::cin >> direction;

        if (direction <= 8 && direction >= 1) //< = // > =
        {
            break;
        }

        std::cout << "wrong direction" << std::endl;
        Sleep(1500);
    } while (true);


    while (is_work)
    {
        Sleep(1500);
        system("cls");

        std::cout << "Current dirrection ";
        if (direction == 1) std::cout << " North" << std::endl;
        else if (direction == 2) std::cout << " North-East" << std::endl;
        else if (direction == 3) std::cout << " East" << std::endl;
        else if (direction == 4) std::cout << " South-East" << std::endl;
        else if (direction == 5) std::cout << " South" << std::endl;
        else if (direction == 6) std::cout << " South-West" << std::endl;
        else if (direction == 7) std::cout << " West" << std::endl;
        else if (direction == 8) std::cout << " North-West" << std::endl;

        std::cout << R"(11 - forward
01 - left
10 - right
00 - stop
99 - exit
Enter command: )"; std::cin >> command;

        switch (direction)
        {
        case directions::n:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::nw;
                std::cout << "Rotate left -> Current dir North-West" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::ne;
                std::cout << "Rotate right -> Current dir North-East" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir North" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent direction North" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::e:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::ne;
                std::cout << "Rotate left -> Current dir North-East" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::se;
                std::cout << "Rotate right -> Current dir South-East" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir East" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Current dir East" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::s:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::se;
                std::cout << "Rotate left -> Current dir South-East" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::sw;
                std::cout << "Rotate right -> Current dir South-West" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir South" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Current direction South" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::w:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::sw;
                std::cout << "Rotate left -> Current dir South-West" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::nw;
                std::cout << "Rotate right -> Current dir North-West" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir West" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent dir West" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::ne:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::n;
                std::cout << "Rotate left -> Current dir North" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::e;
                std::cout << "Rotate right -> Current dir East" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir North-East" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent dir North-East" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::se:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::e;
                std::cout << "Rotate left -> Current dir East" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::s;
                std::cout << "Rotate right -> Current dir South" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir South-East" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent dir South-East" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::sw:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::s;
                std::cout << "Rotate left -> Current dir South" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::w;
                std::cout << "Rotate right -> Current dir West" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir South-West" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent dir South-West" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        case directions::nw:
            switch (command)
            {
            case Commands::LEFT:
                direction = directions::w;
                std::cout << "Rotate left -> Current dir West" << std::endl;
                break;
            case Commands::RIGHT:
                direction = directions::n;
                std::cout << "Rotate right -> Current dir North" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir North-West" << std::endl;
                break;
            case 99:
            case Commands::STOP:
                std::cout << "Stop -> Curent dir North-West" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong command" << std::endl; break;
            }
            break;
        default: std::cout << "wrong command" << std::endl;
        }
    }
    Sleep(1500); return EXIT_SUCCESS;
}