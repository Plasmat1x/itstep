/*
Написать игру Крести-Нолики для поля 5на5,
условие победы заполнить все 5 ячеек в строке,
столбце или на диагонали.
ПО желанию добавить
"искусственный интеллект"
Под* для победы достаточно
3х одинаковых символов подряд в одной строке,
столбце или на диагонали.
*/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>

struct coord
{
    int x;
    int y;
};

void field_draw(char** arr, size_t size);
void field_nullify(char** arr, size_t size);
void freemem(char** arr, size_t size);
char** allocnew(size_t size);
void pl_move(coord vec, char glyph, char** arr, size_t size);
void ai_move(int count, int nfw, char glyph, char op_glyph, int hard_mode, char** arr, size_t size);
void check(bool& is_game, char glyph, int number_for_win, int& count, char** arr, size_t size);

int main()
{
    bool is_open = true;
    bool is_game = false;
    bool is_options = false;
    bool pl_turn = true;
    bool multiplayer = false;

    char input = ' ';
    char pl = 'o';
    char ai = 'x';

    char** field = nullptr;
    size_t size = 3;

    int number_for_win = 3;
    int count = 0;
    int hard_mode = 0;

    //------------------------------//
    field = allocnew(size);
    field_nullify(field, size);
    //------------------------------//

    while (is_open)
    {
        system("cls");
        std::cout << (multiplayer ? "multi-player mode\n" : "single-player mode\n") << "\n";
        std::cout << R"(X_O game

Menu:

1. play
2. options
3. exit)" << "\n\nenter number of menu option > ";

        std::cin >> input;

        switch (input)
        {
        case '1':
            pl_turn = true;
            count = 0;
            field_nullify(field, size);
            is_game = true;
            break;
        case '2':
            is_options = true;
            break;
        case '3':
            freemem(field, size);
            is_open = false;
        default:
            break;
        }

        while (is_options)
        {
            system("cls");
            std::cout << "X_O game\n"
                << "\nOptions:\n\n"
                << "1. field size = " << size << "\n"
                << "2. player glyph = " << pl << "\n"
                << "3. ai glyph = " << ai << "\n"
                << "4. number glyphs in row for win = " << number_for_win << "\n"
                << "5. game type (0 single, 1 multi) = " << multiplayer << "\n"
                << "6. ai mode = " << hard_mode << "\n"
                << "\nx. Exit from options\n\n"
                << "\nenter number of option for change them: ";
            std::cin >> input;

            switch (input)
            {
            case '1':
            {
                freemem(field, size);
                std::cout << "enter value of parameter size: ";
                std::cin >> size;
                field = allocnew(size);
                if (number_for_win > size)
                    number_for_win = size;
            }
            break;

            case '2':
            {
                std::cout << "enter glyph for player: ";
                std::cin >> pl;
            }
            break;
            case '3':
            {
                std::cout << "enter glyph for ai: ";
                std::cin >> ai;
            }
            break;
            case '4':
            {
                int nfw = 0;
                std::cout << "enter number glyphs for win: ";
                std::cin >> nfw;
                if (nfw <= size)
                    number_for_win = nfw;
                else
                    number_for_win = size;
            }
            break;
            case '5':
            {
                std::cout << "enter game type (ai 0, second player 1): ";
                std::cin >> multiplayer;
            }
            break;
            case '6':
            {
                std::cout << "enter ai mode: ";
                std::cin >> hard_mode;
            }
            break;
            case 'x':
                is_options = false;
                break;
            default:
                break;
            }
        }
        while (is_game)
        {
            field_draw(field, size);

            std::cout << count << " turn\n";
            std::cout << "Player glyph: " << pl << " | AI glyph: " << ai << std::endl;

            coord move;

            if (pl_turn == true)
            {
                while (pl_turn == true)
                {
                    std::cout << pl << " > enter coords (x,y): ";
                    std::cin >> move.x >> move.y;
                    
                    if (move.x <= size && move.x >= 1 && move.y <= size && move.y >= 1)
                    {
                        if (field[move.y - 1][move.x - 1] == ' ')
                        {
                            pl_move(move, pl, field, size);
                            pl_turn = !pl_turn;
                            count++;
                            field_draw(field, size);
                            check(is_game, pl, number_for_win, count, field, size);
                            Sleep(1000);
                        }
                    }
                    else if (move.x == 0 && move.y == 0)
                    {
                        is_game = false;
                        break;
                    }
                }
            }
            else if(pl_turn == false && multiplayer == true)
            {
                while (pl_turn == false)
                {
                    std::cout << ai << " > enter coords (x,y): ";
                    std::cin >> move.x >> move.y;
                    if (move.x <= size && move.x >= 1 && move.y <= size && move.y >= 1)
                    {
                        if (field[move.y - 1][move.x - 1] == ' ')
                        {
                            pl_move(move, ai, field, size);
                            pl_turn = !pl_turn;
                            count++;
                            field_draw(field, size);
                            check(is_game, ai, number_for_win, count, field, size);
                            Sleep(1000);
                        }
                    }
                    else if (move.x == 0 && move.y == 0)
                    {
                        is_game = false;
                        break;
                    }       
                }
            }
            else
            {
                while (pl_turn == false)
                {
                    ai_move(count, number_for_win, ai, pl, hard_mode, field, size);
                    pl_turn = !pl_turn;
                    count++;
                    field_draw(field, size);
                    check(is_game, ai, number_for_win, count, field, size);
                    Sleep(1000);
                }
            }    
        }    
    }
    //------------------------------//


    return 0;
}

void field_draw(char** arr, size_t size)
{
    system("cls");
    std::cout << "+";
    for (int i = 0; i < size; i++)
            std::cout << "-+";
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "|";
        for (int j = 0; j < size; j++)
        {
            std::cout << arr[i][j] << "|";
        }
        std::cout << std::endl;
        std::cout << "+";
        for (int j = 0; j < size; j++)
        {
            std::cout << "-+";
        }
        std::cout << std::endl;
    }
}

void field_nullify(char** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void freemem(char** arr, size_t size)
{
    for (int i = 0; i < size; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}

char** allocnew(size_t size)
{
    char** newarr = nullptr;
    newarr = new char* [size];
    for (int i = 0; i < size; i++)
        newarr[i] = new char[size];
    
    return newarr;
}

void pl_move(coord vec, char glyph, char** arr, size_t size)
{
    if ((arr[vec.y - 1][vec.x - 1] == ' ') && ((vec.x > 0) && (vec.y > 0) && (vec.x < size + 1) && (vec.y < size + 1)))
    {
        arr[vec.y - 1][vec.x - 1] = glyph;
    }
}

void ai_move(int count, int nfw, char glyph, char op_glyph, int hard_mode, char** arr, size_t size)
{
    /*
    Доделать ИИ
    */
    switch (hard_mode)
    {
    case 0:
    {
        int i = 0, j = 0;
        do
        {
            i = rand() % size;
            j = rand() % size;
        } while (arr[i][j] != ' ');
        arr[i][j] = glyph;
    }
    break;
    case 1:
    {
        int i = 0; int j = 0;
        if (count == 1)
        {
            {
                i = rand() % size;
                j = rand() % size;
            } while (arr[i][j] != ' ');
            arr[i][j] = glyph;
        }

        if ((count % nfw - 1) == 0)
        {

        }
    }
    break;
    default:
        break;
    }
}

/*
Идея реализации под различную длину символов и размеря поля. xxx, xxxx, xxxxx...
Размер поля устанваливается в опциях игроком
при игре с полем более 3x3 учитывать выйгрышные диагональные комбинации с длиной меньше чем игровое поле

 |X| |
O| |X|
 |O| |X     - X комбинация диагонали, и O комбинация диагонали, должны считаться выйгрышной, при параметрах: длина выйгрышной комбинации = 3, размер поля = 4 
 | |O|
*/
void check(bool& is_game, char glyph, int number_for_win, int& count, char** arr, size_t size)
{   
    if (count >= number_for_win * 2 - 1)
    {
        int hwc = 0;
        int vwc = 0;
        int dwc = 0;
        int swc = 0;

        for (size_t i = 0; i < size; i++) // row
        {
            for (size_t j = 0; j < size;j++) // col 
            {
                hwc = 0;
                vwc = 0;
                dwc = 0;
                swc = 0;

                for (size_t w = 0; w < number_for_win; w++) // check combination
                {
                    if ((j + number_for_win) <= size) // horizontal chek
                    {
                        if (arr[i][j] != ' ' && arr[i][j + w] == glyph && arr[i][j] == arr[i][j + w])
                        {
                            hwc++;
                        }
                        else
                        {
                            hwc = 0;
                        }
                    }
                    else
                        hwc = 0;

                    if ((i + number_for_win) <= size) // vertical check 
                    {
                        if (arr[i][j] != ' ' && arr[i + w][j] == glyph && arr[i][j] == arr[i + w][j])
                        {
                            vwc++;
                        }
                        else
                        {
                            vwc = 0;
                        }
                    }
                    else
                        vwc = 0;

                    if ((i + number_for_win) <= size && (j + number_for_win) <= size) // diagonal chek
                    {
                        if (arr[i][j] != ' ' && arr[i + w][j + w] == glyph && arr[i][j] == arr[i + w][j + w])
                        {
                            dwc++;
                        }
                        else
                        {
                            dwc = 0;
                        }
                    }
                    else
                        dwc = 0;

                    if ((i + number_for_win) <= size && (j - number_for_win) >= 0) //side diagonal check
                    {
                        if (arr[i][j] != ' ' && arr[i + w][j - w] == glyph && arr[i][j] == arr[i + w][j - w])
                        {
                            swc++;
                        }
                        else
                        {
                            swc = 0;
                        }
                    }
                    else
                        swc = 0;
                }

                if (hwc == number_for_win || vwc == number_for_win || dwc == number_for_win || swc == number_for_win)
                {
                    std::cout << glyph << " winner";

                    if(hwc)
                        std::cout << " horizontal\n";
                    else if(vwc)
                        std::cout << " vertical\n";
                    else if (dwc)
                        std::cout << " diagonal\n";
                    else if (swc)
                        std::cout << " side-diagonal\n";

                    system("pause");
                    is_game = false;
                    return;
                }
            }
        }
    }

    if (count >= size * size)
    {
        std::cout << "draw \n";
        system("pause");
        is_game = false;
        return;
    }
}

/* 
//dynamic memory allocate
    char** arr = new char* [size];
    for (int i = 0; i < size; i++)
        arr[i] = new char[size];

//free memory
    for (int i = 0; i < size; i++)
        delete[] arr[i];
    delete[] arr;
*/