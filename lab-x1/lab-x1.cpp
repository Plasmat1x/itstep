#include <iostream>
#include <cstdlib>
#include <Windows.h>

int main()
{
    system("chcp 65001"); std::cout << std::endl;

    std::cout << "---robot control---" << std::endl;

    enum Commands
    {
        STOP = 00,
        LEFT = 01,
        RIGHT = 10,
        FORWARD = 11
    };

    int command = 0;
    bool is_work = true;
    char direction = ' ';
    //hw add direction: se, sw, ne, nw
    /*
    int dir;
    enum direct
    {
    n = 1;
    e = 2;
    s = 3;
    w = 4;
    ne = 12;
    es = 23;
    sw = 34;
    wn = 41;
    }
    */

    do
    {

        system("cls");
        std::cout << R"(
menu:
N,n - North
E,e - East
S,s - South
W,w - West
)";
        std::cout << "Enter direction: "; std::cin >> direction;

        if ((direction == 'n' || direction == 'N' ||
            direction == 'e' || direction == 'E' ||
            direction == 's' || direction == 'S' ||
            direction == 'w' || direction == 'W'))
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
        if (direction == 'n' || direction == 'N') std::cout << " North" << std::endl;
        else if (direction == 'e' || direction == 'E') std::cout << " East" << std::endl;
        else if (direction == 's' || direction == 'S') std::cout << " South" << std::endl;
        else if (direction == 'w' || direction == 'W') std::cout << " West" << std::endl;

        std::cout << R"(11 - forward
01 - left
10 - right
00, X, x - stop
Enter command: )"; std::cin >> command;

        switch (direction)
        {
        case 'n':
        case 'N':
            switch (command)
            {
            case Commands::LEFT:
                direction = 'w';
                std::cout << "Rotate left -> Current dir West" << std::endl;
                break;
            case Commands::RIGHT:
                direction = 'e';
                std::cout << "Rotate right -> Current dir East" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir North" << std::endl;
                break;

            case Commands::STOP:
            case 'x':
            case 'X':
                std::cout << "Stop" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong" << std::endl; break;
            }
            break;
        case 'e':
        case 'E':
            switch (command)
            {
            case Commands::LEFT:
                direction = 'n';
                std::cout << "Rotate left -> Current dir North" << std::endl;
                break;
            case Commands::RIGHT:
                direction = 's';
                std::cout << "Rotate right -> Current dir South" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir East" << std::endl;
                break;

            case Commands::STOP:
            case 'x':
            case 'X':
                std::cout << "Stop" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong" << std::endl; break;
            }
            break;
        case 's':
        case 'S':
            switch (command)
            {
            case Commands::LEFT:
                direction = 'e';
                std::cout << "Rotate left -> Current dir East" << std::endl;
                break;
            case Commands::RIGHT:
                direction = 'w';
                std::cout << "Rotate right -> Current dir West" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir South" << std::endl;
                break;

            case Commands::STOP:
            case 'x':
            case 'X':
                std::cout << "Stop" << std::endl;
                is_work = false;
                break;
            default: std::cout << "wrong" << std::endl; break;
            }
            break;
        case 'w':
        case 'W':
            switch (command)
            {
            case Commands::LEFT:
                direction = 's';
                std::cout << "Rotate left -> Current dir South" << std::endl;
                break;
            case Commands::RIGHT:
                direction = 'n';
                std::cout << "Rotate right -> Current dir North" << std::endl;
                break;
            case Commands::FORWARD:
                std::cout << "Move forward -> Current dir West" << std::endl;
                break;

            case Commands::STOP:
            case 'x':
            case 'X':
                std::cout << "Stop" << std::endl;
                is_work = false;
                break;

                break;
            default: std::cout << "wrong" << std::endl; break;
            }
        }
    }
    Sleep(1500); return EXIT_SUCCESS;
}

/*
мой вариант прототип
enum DIR
    {
        FORWARD = 11,
        RIGHT = 10,
        LEFT = 01,
        STOP = 00,
    };

    bool l_rotor = false;
    bool r_rotor = false;

    int dir;
    std::cin >> dir;

    switch (dir)
    {
    case DIR::FORWARD:
        l_rotor = true;
        r_rotor = true;
        break;
    case DIR::RIGHT:
        l_rotor = true;
        r_rotor = false;
        break;
    case DIR::LEFT:
        r_rotor = true;
        l_rotor = false;
        break;
    case DIR::STOP:
    default:
        l_rotor = false;
        r_rotor = false;
        break;
    }

*/

/*
//лекция
// Robot
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h> //библиотека функция от ОС Windows
//#include <synchapi.h>  //библиотека содержит команду Sleep
//#include <unistd.h> //библиотека для Unix

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout<<"---Программа управления роботом!---"<<endl;
    int Command = 0; //команда вводимая с колавиаутры
    enum Commands{Go=11,Right=10,Left=01,Stop=00};
    //1 2 3 4 5 6 7
    char Direction = ' '; //направление движения робота
    //Для ДЗ
    //int Direction = 0;
    //enum Directions{N=1,NE=12,E=2,SE=32,S=3,SW=34,W=4,NW=14};
do //цикл ввода первоначального направления
{
    cout << R"(
Введите первоначальное направление робота:
N(n) - Север
E(e) - Восток
S(s) - Юг
W(w) - Запад
)";
    cin >> Direction;
    system("cls");
    //если введен нужный символ цикл прервется
    if (Direction == 'N' || Direction == 'n' || Direction == 'E' || Direction == 'e' ||
        Direction == 'S' || Direction == 's' || Direction == 'W' || Direction == 'w')break;
    else cout << "Введено некорректное направление! Повторите ввод!" << endl;
} while (true); //бесконечный цикл
do //цикл движения робота
{
    system("cls");
    cout << R"(
Робот готов и ожидает команду:
11 - Двигаться вперед
10 - Повернуть направо
01 - Повернуть налево
00 - Остановиться
)";
    cin >> Command;
    switch (Direction) //выбор текущего направления(начального)
    {
        //если текущее направление север
    case 'N':
    case 'n':
        switch (Command) //выбор команды робота
        {
        case Commands::Go:    //case Go:   //case 11:
            cout << "Робот поедет вперед - на север!" << endl;
            break;
        case Right:
            cout << "Робот повернет на восток!" << endl;
            Direction = 'E'; //смена направления робота
            break;
        case Left:
            cout << "Робот повернет на запад!" << endl;
            Direction = 'W'; //смена направления робота
            break;
        default:
            cout << "Некорректная команда!" << endl;
            break;
        case Stop:
            cout << "Робот остановился и смотрит на север!" << endl;
            break;
        }
        break;
        //если текущее направление юг
    case 'S':
    case 's':
        switch (Command) //выбор команды робота
        {
        case Commands::Go:    //case Go:   //case 11:
            cout << "Робот поедет вперед - на юг!" << endl;
            break;
        case Right:
            cout << "Робот повернет на запад!" << endl;
            Direction = 'W'; //смена направления робота
            break;
        case Left:
            cout << "Робот повернет на восток!" << endl;
            Direction = 'E'; //смена направления робота
            break;
        default:
            cout << "Некорректная команда!" << endl;
            break;
        case Stop:
            cout << "Робот остановился и смотрит на юг!" << endl;
            break;
        }
        break;
        //если текущее направление восток
    case 'E':
    case 'e':
        switch (Command) //выбор команды робота
        {
        case Commands::Go:    //case Go:   //case 11:
            cout << "Робот поедет вперед - на восток!" << endl;
            break;
        case Right:
            cout << "Робот повернет на юг!" << endl;
            Direction = 'S'; //смена направления робота
            break;
        case Left:
            cout << "Робот повернет на север!" << endl;
            Direction = 'N'; //смена направления робота
            break;
        default:
            cout << "Некорректная команда!" << endl;
            break;
        case Stop:
            cout << "Робот остановился и смотрит на восток!" << endl;
            break;
        }
        break;
        //если текущее направление запад
    case 'W':
    case 'w':
        switch (Command) //выбор команды робота
        {
        case Commands::Go:    //case Go:   //case 11:
            cout << "Робот поедет вперед - на запад!" << endl;
            break;
        case Right:
            cout << "Робот повернет на север!" << endl;
            Direction = 'N'; //смена направления робота
            break;
        case Left:
            cout << "Робот повернет на юг!" << endl;
            Direction = 'S'; //смена направления робота
            break;
        default:
            cout << "Некорректная команда!" << endl;
            break;
        case Stop:
            cout << "Робот остановился и смотрит на запад!" << endl;
            break;
        }
        break;
    }
    if (Command == Commands::Stop)
    {
        cout << "Для продолжения работы робота введите 11, для выключения робота введите 00: ";
        cin >> Command;
    }
    Sleep(1500); //задержка программы в 1500 миллисекуд (1.5 секунды)
} while (Command != Commands::Stop); //while(Command!=Stop); //while(Command!=0);
cout << "Выключение робота!" << endl;
//system("pause");
Sleep(1500); //задержка программы в 1500 миллисекуд (1.5 секунды)
}

*/