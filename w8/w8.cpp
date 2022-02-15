#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void w8t1();
void w8t2();

int main()
{
    //w8t1();
    //w8t2();
    return 0;
}

void w8t1()
{
    /*
    Написать программу, которая выводит на экран линию
заданным символом, вертикальную или горизонтальную, при-
чем линия может выводиться быстро, нормально и медленно.
Общение с пользователем организовать через меню.
    */
    bool isw = true;
    int com = 0;

    char sym = '-';
    int size = 1;
    int speed_mode = 0;
    bool horizontal = true;


    
    while (isw)
    {
        system("cls");
        std::cout << "<--Line draw with symbol + drawing speed-->" << std::endl;

        std::cout << "Parameters:" << std::endl;
        std::cout << "symbol for rendering \t= " << sym << std::endl;
        std::cout << "line size (symbols) \t= " << size << std::endl;
        std::cout << "layout \t\t\t=" << (horizontal ? " horizontal " : " vertical ") << std::endl;
        std::cout << "<0 - vertical, 1 - horizontal>" << std::endl;;
        std::cout << "speed mode \t\t= " << speed_mode << std::endl;
        std::cout << "<0 - slow, 1 - medium, 2 - fast>" << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << R"(command menu:
0 - draw and exit
1 - set symbol
2 - set size
3 - set speed mode
4 - set layout)" << std::endl;
        std::cout << "enter command > ";
        std::cin >> com;

        switch (com)
        {
        case 0:
            isw = false;
            break;
        case 1:
            std::cout << "enter symbol > ";
            std::cin >> sym;
            break;
        case 2:
            std::cout << "enter size > ";
            std::cin >> size;
            break;
        case 3:
            std::cout << "enter speed mode > ";
            std::cin >> speed_mode;
            break;
        case 4:
            std::cout << "enter layout > ";
            std::cin >> horizontal;
        default:
            std::cout << "wrong command" << std::endl;
            break;
        }

    }
    
    for (int i = 0; i < size; i++)
    {
        std::cout << sym;

        switch (speed_mode)
        {
        case 0:
            Sleep(1500);
            break;//slow
        case 1:
            Sleep(1000);
            break;//medium
        case 2:
            Sleep(500);
            break;//fast
        default: break;
        }

        if (!horizontal)
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    
    system("pause");
}
void w8t2()
{
    /*
    Написать игру «Кубики». Пользователь и компьютер по
очереди бросают 2 кубика. Победитель — тот, у кого по резуль-
татам трех бросков сумма больше. Предусмотреть красивый
интерфейс игры.
    */

    bool pt = true;

    int player[3][2] = {
        {0,0},
        {0,0},
        {0,0}
    };
    int AI[3][2] = {
        {0,0},
        {0,0},
        {0,0}
    };

    int player_sum = 0;
    int AI_sum = 0;

    srand(time(NULL));

    //game loop
    for (int i = 0; i < 6; i++)
    {
        system("cls");
        std::cout << "<--  Dice  -->" << std::endl;
        std::cout << "Player|__AI__" << std::endl;
        std::cout << "=============" << std::endl;
        //table draw loop
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                std::cout << " " << player[i][j];
            }

            std::cout << "  |  ";

            for (int j = 0; j < 2; j++)
            {
                std::cout << AI[i][j] << " ";
            }

            std::cout << std::endl;
        }
        std::cout << "player sum = " << player_sum << std::endl;
        std::cout << "AI sum = " << AI_sum << std::endl;

        std::cout << (pt ? "player turn" : "AI turn ") << "\r";
        system("pause");
        std::cout << "                                     \r";

        if (pt)
        {
            player[(i / 2)][0] = rand() % 6 + 1;
            player[(i / 2)][1] = rand() % 6 + 1;

            player_sum += player[(i / 2)][0] + player[(i / 2)][1];
    
        }
        else
        {
            AI[(i / 2)][0] = rand() % 6 + 1;
            AI[(i / 2)][1] = rand() % 6 + 1;

            AI_sum += AI[(i / 2)][0] + AI[(i / 2)][1];

        }
        pt = !pt;

    }

    //last update table
    system("cls");
    std::cout << "<--  Dice  -->" << std::endl;
    std::cout << "Player|__AI__" << std::endl;
    std::cout << "=============" << std::endl;
    //table draw loop
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << " " << player[i][j];
        }

        std::cout << "  |  ";

        for (int j = 0; j < 2; j++)
        {
            std::cout << AI[i][j] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << "player sum = " << player_sum << std::endl;
    std::cout << "AI sum = " << AI_sum << std::endl;
    std::cout << std::endl << (player_sum > AI_sum ? "Player win" : "AI win");

    Sleep(5000);
}
void w8t3()
{
    /*
    Написать игру «GUESS MY NUMBER». Пользователь
угадывает число, которое «загадал» компьютер. Возможны
2 уровня сложности: на первом уровне число от 1 до 10, на
втором от 10 до 100. В начале игры пользователь выбирает
уровень.
Неделя 8
2
В начале каждого уровня игроку даются «жизни» — 50%
от длины диапазона угадывания на первом уровне и 25% — на
втором (пример приведен ниже). За каждую ошибку игрок
штрафуется — минус одна жизнь. Предусмотреть в игре воз-
можность подсказки: «загаданное число больше — меньше
твоего». Стоимость подсказки — одна жизнь (пользователь
может принять подсказку в случае ошибки или отказаться от
нее). Уровень продолжается, пока игрок жив или не угадает
(состояние игрока «жив» — «убит» отображается рисунком
в консоли).
Очки после уровня — количество оставшихся жизней,
умноженные на 5 для первого уровня и на 10 для второго.
Результат игры, количество очков или «Проигрыш», вывести
в консоль.
    */
}

void w8t4()
{
    /*
    Модифицировать игру «GUESS MY NUMBER» следующим
образом:
■■ пользователь не выбирает уровень, т. к. переход ко второму
уровню возможен только после завершения первого без
проигрыша (если игрок желает продолжать);
■■ первый уровень длится три раунда (на каждом раунде
загадывается новое число), а второй — два раунда. Новые
жизни начисляются игроку перед новым раундом.
■■ если пользователь проиграл раунд, то компьютеру на-
числяются очки за раунд в размере начальные жизни
пользователя, умноженные на 5 для первого уровня и на
10 для второго;
■■ количество очков сохраняется и накапливается в раундах
и уровнях;
■■ промежуточные итоги выводятся после каждого раунда
и уровня.
    */
}

/* lab
Тема: Функции. Перегрузка функций.
Рекурсия
Задания для самостоятельной работы 1
Задание 1. Дан одномерный массив целых чисел. Напишите
рекурсивную функцию, которая осуществляет нахождения
искомого значения с помощью бинарного поиска. Функция возвращает позицию вхождения искомого значения.
Проиллюстрируйте работу функции примером.
Задание 2. Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива вправо.
Например:
Дан массив:
4 5 6 7
1 2 4 1
4 5 6 9
Сдвигаем на три вправо:
5 6 7 4
2 4 1 1
5 6 9 4
Задание 3. Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива влево.
Неделя 13
1
Например
Дан массив:
4 5 6 7
1 2 4 1
4 5 6 9
Сдвигаем на два влево:
6 7 4 5
4 1 1 2
6 9 4 5
Задание 4. Напишите рекурсивную функцию, которая
принимает двухмерный массив целых чисел и количество
сдвигов и выполняет круговой сдвиг массива вниз.
Например:
Дан массив:
4 5 6 7
1 2 4 1
4 3 6 8
Сдвигаем низ на один:
4 3 6 8
4 5 6 7
1 2 4 1
*/