//Developed by Mryasov M.
//Sapper
/*
==классической реализация==
Сапер(поле 10х10, 10-20 мин)

Плоское или объёмное игровое поле разделено на смежные ячейки 
(квадраты, шестиугольники, кубы и т. п.), некоторые из которых «заминированы»; 
количество «заминированных» ячеек известно. 
Целью игры является открытие всех ячеек, не содержащих мины.

Игрок открывает ячейки, стараясь не открыть ячейку с миной. Открыв ячейку с миной, 
он проигрывает. Мины расставляются после первого хода, поэтому в новых версиях 
проиграть на первом же ходу невозможно. В первой версии (Windows 95-Windows XP) 
довольно частая ситуация, что под первой открытой ячейкой оказывалась мина. 
Если под открытой ячейкой мины нет, то в ней появляется число, показывающее, 
сколько ячеек, соседствующих с только что открытой, 
«заминировано» (в каждом варианте игры соседство определяется по-своему); 
используя эти числа, игрок пытается рассчитать расположение мин, 
однако иногда даже в середине и в конце игры некоторые 
ячейки всё же приходится открывать наугад. 
Если под соседними ячейками тоже нет мин, 
то открывается некоторая «не заминированная» область до ячеек, 
в которых есть цифры. «Заминированные» ячейки игрок может пометить, 
чтобы случайно не открыть их. 
Открыв все «не заминированные» ячейки, игрок выигрывает.
*/

#define sym_M (char)0xA4

#include <iostream>
#include <stdlib.h>
#include <time.h>

struct cell
{
    int value;
    bool hide;

    cell(int val = 0, bool hi = true)
    {
        value = val;
        hide = hi;
    }
};

void draw();
void generate();
bool check();
void opensafe(int x, int y);


//opensafefnc <recursive>

cell** arr = nullptr;
int count_mine = 0;
int count_turns = 0;

int main()
{
    srand(time(NULL));
    system("chcp 1251");

    //var
    bool is_game = true;

    //create array
    arr = new cell * [12];
    for (int i = 0; i < 12; i++)
    {
        arr[i] = new cell[12];
    }

    generate();

    while (is_game) // game loop
    {
        draw();
        int x = 0, y = 0;
        do
        {
            std::cout << "Введите координаты ячейки которые хотите открыть (x y):";
            std::cin >> x >> y;
        } while ((x < 1 || x > 10) || (y < 1 || y > 10));

        opensafe(x, y);
        arr[y][x].hide = false;

        if (check() == false)
        {
            for (int i = 1; i < 11; i++)
            {
                for (int j = 1; j < 11; j++)
                {
                    if (arr[i][j].value > 8)
                        arr[i][j].hide = false;
                }
            }

            draw();
            int v = rand() % 5;
            is_game = false;
            std::cout << "КОНЕЦ. ";

            switch (v)
            {
            case 0: std::cout << "Сапер всегда выполнит свою работу.\n - Даже если, обезвреживая мину, он ошибся, разминирование он все равно произвел.)" << std::endl; break;
            case 1: std::cout << "Сапер ошибается два раза в жизни:\n- Первый раз при выборе профессии, второй раз - когда разминирует." << std::endl; break;
            case 2: std::cout << "Чем отличается десантник от сапера? - направлением полета." << std::endl; break;
            case 3: std::cout << "\"Ноги моей здесь больше не будет\" - подумал сапер, наступая на мину." << std::endl; break;
            case 4: std::cout << "Учиться на своих ошибках — довольно распространенная практика.\n- Но саперы были вынуждены пойти другим путем." << std::endl; break;
            }
            system("pause");
        }
    }

    //free memory
    for (int i = 0; i < 12; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

void draw()
{
    system("cls");
    std::cout << "\t\t--Sapper game--\n\n"
    << "Количество мин: " << count_mine << "\tколичество ходов: " << count_turns <<"\n\n" 
    << "    1 2 3 4 5 6 7 8 9 10\n\n";

    for (int i = 1; i < 11; i++)
    {
        if (i < 10)
            std::cout << " " << i << " ";
        else
            std::cout << i << " ";
        for (int j = 1; j < 11; j++)
        {
            if (arr[i][j].hide == false)
            {
                if (arr[i][j].value > 8)
                    std::cout << " " << sym_M;
                else if (arr[i][j].value == 0)
                    std::cout << "  ";
                else
                    std::cout << " " << arr[i][j].value ;
            }
            else
            {
                std::cout << " #";
            }
            
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

    count_turns++;
}

void generate()
{
    //nullify array
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            arr[i][j].value = 0;
            arr[i][j].hide = 1;
        }
    }

    //generate count mines
    count_mine = rand() % 10 + 10;

    //deployt mines
    for (int i = 0; i < count_mine; i++)
    {
        int x = 0, y = 0;
        do
        {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;

        } while (arr[y][x].value > 8);

        arr[y][x].value = 9;
        arr[y - 1][x].value++;
        arr[y - 1][x + 1].value++;
        arr[y][x + 1].value++;
        arr[y + 1][x + 1].value++;
        arr[y + 1][x].value++;
        arr[y + 1][x - 1].value++;
        arr[y][x - 1].value++;
        arr[y - 1][x - 1].value++;
    }
}

bool check()
{
    int j = 0;
    for (int i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (arr[i][j].value > 8 && arr[i][j].hide == false) return false;
        }

        if (arr[i][j].value < 9 && arr[i][j].hide == false) continue;
    }

    return true;
}

void opensafe(int x, int y)
{
    if (x < 1) return;
    if (x > 10) return;
    if (y < 1) return;
    if (y > 10) return;
    if (arr[y][x].hide == false) return;

    if (arr[y][x].value < 9 && arr[y][x].value > 0)
    {
        arr[y][x].hide = false;
        return;
    }

    arr[y][x].hide = false;

    opensafe(x - 1, y);
    opensafe(x + 1, y);
    opensafe(x, y - 1);
    opensafe(x, y + 1);
}

/* clear field

var 2:

  а б в г д е ж з и к
  ...
   1 2 3 4 5 6 7 8 9 10
 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 2 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 3 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
10 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

*/
