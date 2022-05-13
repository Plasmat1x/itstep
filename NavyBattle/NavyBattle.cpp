//Developed by Mryasov M.
//Navy Battle
/*
==классической реализация==
Морской бой(поле 10х10, 10 кораблей)

Rules:

игра для двух участников, в которой игроки по очереди называют координаты на
неизвестной им карте соперника. Если у соперника по этим координатам имеется
корабль (координаты заняты), то корабль или его часть «топится»,
а попавший получает право сделать ещё один ход.
Цель игрока — первым потопить все корабли противника.


Игровое поле — обычно квадрат 10×10 у каждого игрока,
на котором размещается флот кораблей. Вертикали обычно нумеруются сверху вниз,
а горизонтали помечаются буквами слева направо.
При этом используются буквы русского алфавита от «а» до «к»
(буквы «ё» и «й» обычно пропускаются)
либо от «а» до «и» (с использованием буквы «ё»),
либо буквы латинского алфавита от «a» до «j».

Размещаются:

1 корабль — ряд из 4 клеток («четырёхпалубный»; линкор)
2 корабля — ряд из 3 клеток («трёхпалубные»; крейсера)
3 корабля — ряд из 2 клеток («двухпалубные»; эсминцы)
4 корабля — 1 клетка («однопалубные»; торпедные катера)
Другой вариант названия кораблей: «…-трубные» (напр. двухтрубные).

При размещении корабли не могут касаться друг друга сторонами и углами.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define DRAW draw(mfield, efield)

struct cell
{
    int val;
    bool hit;

    cell(int v = 0, bool h = 0)
    {
        val = v;
        hit = h;
    }
};


void draw(cell** mfield, cell** efield);

int chartoint(char x);

void hit(int x, int y, cell** target);

void deployment(int x, int y, bool o, int type, cell** field);

bool available(int x, int y, bool o, int type, cell** field);

//win chek required

int main()
{
    system("chcp 1251");
    system("cls");
    
    srand(time(NULL));

    bool is_game = true;
    bool is_preporation = true;
    bool turn = true;

    // размер игрового поля остается 10х10, добавлена буферная зона для возможности расстановки кораблей рядом с границей: 1, 10, а, к линия
    cell** mfield = new cell * [12]; // my field (player) 
    cell** efield = new cell * [12]; // enemy field (AI)
    for (int i = 0; i < 12; i++)
    {
        mfield[i] = new cell[12];
        efield[i] = new cell[12];
    }

// fields clear
    for(int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            mfield[i][j] = { 0,0 };
            efield[i][j] = { 0,0 };
        }

// while(menu) // possible variation for replay
    DRAW;

    //========================================================
    while (is_preporation)  // deployment ship loop
    {
        for (int i = 0; i < 10; i++)// player deploy
        {
            DRAW;
            char cx, co;
            int x, y;
            bool o;

            do 
            {
                std::cout << "-Расстановка кораблей-\nВведите координаты (А 1): ";
                std::cin >> cx >> y;
                x = chartoint(cx);
                std::cout << "расположение (В_ертикально/Г_оризонтально): ";
                std::cin >> co;

                if (co == 'г' || co == 'Г')
                    o = true;
                else
                    o = false;


                if (i == 0 && available(x, y, o, 4, mfield)) break;
                else if ((i >= 1 && i <= 2) && available(x, y, o, 3, mfield)) break;
                else if ((i >= 3 && i <= 5) && available(x, y, o, 2, mfield)) break;
                else if ((i >= 6 && i <= 10) && available(x, y, o, 1, mfield)) break;
                else std::cout << "Не верно" << std::endl;

            } while (true);

            if (i == 0) deployment(x, y, o, 4, mfield);
            else if(i >= 1 && i <= 2) deployment(x, y, o, 3, mfield);
            else if(i >= 3 && i <= 5) deployment(x, y, o, 2, mfield);
            else if(i >= 6 && i <= 10) deployment(x, y, o, 1, mfield);
        }

        for (int i = 0; i < 10; i++) // ai deploy
        {
            DRAW;
            int x, y;
            bool o;

            do
            {
                x = rand() % 9 + 1;
                y = rand() % 9 + 1;
                o = (bool)(rand() % 1);

                if (i == 0 && available(x, y, o, 4, efield)) break;
                else if ((i >= 1 && i <= 2) && available(x, y, o, 3, efield)) break;
                else if ((i >= 3 && i <= 5) && available(x, y, o, 2, efield)) break;
                else if ((i >= 6 && i <= 10) && available(x, y, o, 1, efield)) break;

            } while (true);

            if (i == 0) deployment(x, y, o, 4, efield);
            else if (i >= 1 && i <= 2) deployment(x, y, o, 3, efield);
            else if (i >= 3 && i <= 5) deployment(x, y, o, 2, efield);
            else if (i >= 6 && i <= 10) deployment(x, y, o, 1, efield);
        }
        DRAW;
        is_preporation = false;
    }
    system("pause");
    //========================================================

    turn = true;
    while (is_game) // game loop
    {
        DRAW;

        char cx = 0;
        int x = 0, y = 0;

        //====================================================
        do // player turn
        {
            DRAW;
            do // check right coordinates
            {
                std::cout << "Введите координаты атаки (A 1): ";
                std::cin >> cx >> y;
            } while (((cx < 0 && cx > 'к') || (cx < 'а' && cx > 'К') || (cx < 'А')) || (y < 1 || y > 10));

            x = chartoint(cx);

            if (efield[y][x].hit) // double time coordinates msg
            {
                std::cout << "-Уже был произведен залп по данным координатам, задайте новые!" << std::endl;
            }                         
            else if (efield[y][x].val > 0) // hit msg +turn
            {
                hit(x, y, efield);
                DRAW;
                std::cout << "-Вы попали по врагу, продолжайте ввести огонь!" << std::endl;
                turn = true;
            }
            else
            {
                hit(x, y, efield); // miss msg -turn
                DRAW;
                std::cout << "-Мимо, приготовиться к ответному огню!" << std::endl;
                turn = false;
            }
            
            Sleep(2000);
        } while (turn);
        //====================================================

        do // AI turn
        {
            DRAW;
            do // check right coordinates
            {
                x = rand() % 10 + 1;
                y = rand() % 10 + 1;
            } while ((x < 1 || x > 10) || (y < 1 || y > 10));

            if (mfield[y][x].val > 0) // hit msg +turn
            {
                hit(x, y, mfield);
                DRAW;
                std::cout << "-Враг по нам попал, приготовиться к следующему залпу!" << std::endl;
                turn = false;
            }
            else
            {
                hit(x, y, mfield); // miss msg -turn
                DRAW;
                std::cout << "-Враг промахнулся, в контратаку!" << std::endl;
                turn = true;
            }

            Sleep(2000);
        } while (!turn);

        //====================================================
        Sleep(2000);
    }

    //clear mem
    //====================================================
    for (int i = 0; i < 12; i++)
    {
        delete[] mfield[i];
        delete[] efield[i];
    }
    delete[] mfield;
    delete[] efield;


    return 0;
}

//test enable comment uncomment requaired for release
void draw(cell** mfield, cell** efield)
{
    system("cls");
    std::cout << "--Navy Battle--\n" << std::endl;

    std::cout << "   а б в г д е ж з и к \t\t";
    std::cout << "   а б в г д е ж з и к \n";
    for (int i = 1; i < 11; i++)
    {
        std::cout << i << " ";
        for (int j = 1; j < 11; j++) // mfield draw
        {
            if (mfield[i][j].hit == false && mfield[i][j].val == 0)
            {
                if(i == 10 && j == 1)
                    std::cout << "~";
                else
                    std::cout << " ~";
            }   
            else if (mfield[i][j].hit == false && mfield[i][j].val > 0)
            {
                if (i == 10 && j == 1)
                    std::cout << "O";
                else
                    std::cout << " O";
            }
            else if (mfield[i][j].hit == true && mfield[i][j].val > 0)
            {
                if (i == 10 && j == 1)
                    std::cout << "X";
                else
                    std::cout << " X";
            }
            else if (mfield[i][j].hit == true && mfield[i][j].val == 0)
            {
                if (i == 10 && j == 1)
                    std::cout << " ";
                else
                    std::cout << "  ";
            }
        }

        //TEST DRAW
        std::cout << "\t\t" << i << " ";
        for (int j = 1; j < 11; j++) //efield draw
        {
            if (efield[i][j].hit == false && efield[i][j].val > 0)
            {
                if (i == 10 && j == 1)
                    std::cout << efield[i][j].val;
                else
                    std::cout << " " << efield[i][j].val;
            }
            else if (efield[i][j].hit == false && efield[i][j].val == 0)
            {
                if (i == 10 && j == 1)
                    std::cout << "~";
                else
                    std::cout << " ~";
            }
            else if (efield[i][j].hit == true && efield[i][j].val > 0)
            {
                if (i == 10 && j == 1)
                    std::cout << "X";
                else
                    std::cout << " X";
            }
            else if (efield[i][j].hit == true && efield[i][j].val == 0)
            {
                if (i == 10 && j == 1)
                    std::cout << " ";
                else
                    std::cout << "  ";
            }
        }


        /*release draw
        std::cout << "\t\t" << i << " ";
        for (int j = 1; j < 11; j++) //efield draw
        {
            if (efield[i][j].hit == false)
            {
                if (i == 10 && j == 1)
                    std::cout << "~";
                else
                    std::cout << " ~";
            }
            else if (efield[i][j].hit == true && efield[i][j].val > 0)
            {
                if (i == 10 && j == 1)
                    std::cout << "X";
                else
                    std::cout << " X";
            }
            else if (efield[i][j].hit == true && efield[i][j].val == 0)
            {
                if (i == 10 && j == 1)
                    std::cout << " ";
                else
                    std::cout << "  ";
            }
        }
        */
        std::cout << "\n";
    }
    std::cout << "\n" << std::endl;
}

int chartoint(char x)
{
    int i = -1;
    switch (x)
    {
    case 'а':
    case 'А':
    {
        i = 1;
        return i;
    }
    break;
    case 'б':
    case 'Б':
    {
        i = 2;
        return i;
    }
    break;
    case 'В':
    case 'в':
    {
        i = 3;
        return i;
    }
    break;
    case 'Г':
    case 'г':
    {
        i = 4;
        return i;
    }
    break;
    case 'Д':
    case 'д':
    {
        i = 5;
        return i;
    }
    break;
    case 'Е':
    case 'е':
    {
        i = 6;
        return i;
    }
    break;
    case 'Ж':
    case 'ж':
    {
        i = 7;
        return i;
    }
    break;
    case 'З':
    case 'з':
    {
        i = 8;
        return i;
    }
    break;
    case 'И':
    case 'и':
    {
        i = 9;
        return i;
    }
    break;
    case 'К':
    case 'к':
    {
        i = 10;
        return i;
    }
    break;
    }

    return i;
}

void hit(int x, int y, cell** target)
{
    target[y][x].hit = true;
}

bool available(int x, int y, bool o, int type, cell** field)
{
    if (x + type > 10) return false;
    if (y + type > 10) return false;
    if (field[y][x].val > 0) return false;

    if (type == 1)
    {
        if (
            field[y - 1][x].val > 0 ||
            field[y - 1][x + 1].val > 0 ||
            field[y][x + 1].val > 0 ||
            field[y + 1][x + 1].val > 0 ||
            field[y + 1][x].val > 0 ||
            field[y + 1][x - 1].val > 0 ||
            field[y][x - 1].val > 0 ||
            field[y - 1][x - 1].val > 0
            )
            return false;
    }

    for (int i = 0; i < type; i++) //empleace 
    {
        if (o) // horizontal
        {
            if (i == 0)
            {
                if (
                    field[y - 1][x].val > 0 ||
                    field[y - 1][x - 1].val > 0 ||
                    field[y][x - 1].val > 0 ||
                    field[y + 1][x - 1].val > 0 ||
                    field[y + 1][x].val > 0
                    )
                    return false;
            }
            else if (i == type - 1)
            {
                if (
                    field[y - 1][i+x].val > 0 ||
                    field[y - 1][i+x + 1].val > 0 ||
                    field[y][i+x + 1].val > 0 ||
                    field[y + 1][i+x + 1].val > 0 ||
                    field[y + 1][i+x].val > 0
                    )
                    return false;
            }
            else
            {
                if (field[y + 1][i+x].val > 0 ||
                    field[y - 1][i+x].val > 0)
                    return false;
            }
        }
        else // vertical
        {
            if (i == 0)
            {
                if (
                    field[y][x - 1].val > 0 ||
                    field[y - 1][x - 1].val > 0 ||
                    field[y - 1][x].val > 0 ||
                    field[y - 1][x + 1].val > 0 ||
                    field[y][x + 1].val > 0
                    )
                    return false;
            }
            else if (i == type - 1)
            {
                if (
                    field[i+y][x + 1].val > 0 ||
                    field[i+y + 1][x + 1].val > 0 ||
                    field[i+y + 1][x].val > 0 ||
                    field[i+y + 1][x - 1].val > 0 ||
                    field[i+y][x - 1].val > 0
                    )
                    return false;
            }
            else
            {
                if (field[i+y][x - 1].val > 0 ||
                    field[i+y][x + 1].val > 0)
                    return false;
            }
        }

    }
    return true;
}

void deployment(int x, int y, bool o, int type, cell** field)
{
    for (int i = 0; i < type; i++) //empleace 
    {
        if (o) //horizontal
            field[y][x + i].val = type;
        else   //vertical
            field[y + i][x].val = type;
    }
}