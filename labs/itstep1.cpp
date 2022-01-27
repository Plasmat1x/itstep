#include <iostream>
#include <locale.h>
#include <cstdlib>

/// <summary>
/// Hello world
/// </summary>
/// <param name="argc">integer param</param>
/// <param name="argv">char array param</param>
/// <returns>integer: 0 - good, 1..n - bad</returns>
int main(int argc, char* argv[]) //начало программы
{
    //setlocale(LC_ALL, "rus");
    //ctrl+k,ctrl+c - установка многострочного комментария
    //ctrl+k,ctrl+u - снятие многострочного комментария
    // 
    //system("chcp 65001"); изменение кодировки
    //system("chcp 866");

    std::cout << "1\t2\t3\n-----------------\n4\t5\t6\n-----------------\n7\t8\t9\n-----------------\n*\t0\t#" << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "1\t2\t3\n";
    std::cout << "-----------------\n";
    std::cout << "4\t5\t6\n";
    std::cout << "-----------------\n";
    std::cout << "7\t8\t9\n";
    std::cout << "-----------------\n";
    std::cout << "*\t0\t#\n";

    //Raw-строка cout<<R"()";   - всё содержимое круглых скобок будет воспрянято как текст
    std::cout << R"(
1       2       3
-----------------
4       5       6
-----------------
7       8       9
-----------------
*       0       #
)" << std::endl;

    //Лабораторная работа
    //task 1
    std::cout << "Name\t\t: \"Vulkan Programming Guide: The Official Guide to Learning Vulkan (OpenGL) 1st Edition\"\n";
    std::cout << "Author\t\t: Graham Sellers, John Kessenich\n";
    std::cout << "Publisher\t: D.M.K. publishing (RU)\n";
    std::cout << "Pages\t\t: 393." << std::endl << std::endl;

    //task 2
    std::cout << "The Library of Babel is a place for scholars to do research, for artists\a\a\a\n"; // escape-последовательность \a (alert) -- вывод звукового сигнала из системного динамика
    std::cout << "and writers to seek inspiration, for anyone with curiosity or a sense of\a\a\a\n";
    std::cout << "humor to reflect on the weirdness of existence - in short, it’s just like\a\a\a\n";
    std::cout << "any other library.\t...\a\a\a" << std::endl << std::endl;

    //task 3
    for (int i = 179; i < 219; i++)
    {
        std::cout << i << "\t:\t" << char(i) << std::endl;
    }

    std::cout << char(201); for (int i = 0; i < 95; i++) { std::cout << char(205); }; std::cout << char(187) << std::endl;
    std::cout << char(186) << "\t\t\t\t\t\tSeasons\t\t\t\t\t\t" << char(186) << std::endl;
    std::cout << char(204);
    for (int i = 1; i < 96; ++i)
    {
        if (i % 24)
        {
            std::cout << char(205);

            continue;
        }
        std::cout << char(203);       
    };
    std::cout << char(185) << std::endl;

    std::cout << char(186) << "\tautumn\t\t" << char(186) << "\twinter\t\t" << char(186) << "\tspring\t\t" << char(186) << "\tsummer\t\t" << char(186) << std::endl;

    std::cout << char(200);
    for (int i = 1; i < 96; ++i)
    {
        if (i % 24)
        {
            std::cout << char(205);

            continue;
        }
        std::cout << char(202);
    };
    std::cout << char(188) << std::endl;

    return 0;
}
