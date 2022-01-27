#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cmath>

int main(int argc, char* argv[])
{
    //homework

    /*
    јлгоритм перехода дороги:
    0. Ќачало
    1. ќпределить наличие светофора
    2. ≈сли светофор есть и он работает то определить текущий цвет светофора иначе посмотреть на лево //(логическое и в условии) if (true && true)
    2.1. если цвет зеленый то убедившись в безопасности перейти дорогу иначе пока не горит зеленый цвет
    2.1.1. подождать
    2.1.2. определить текущий цвет
    2.1.3. убедившись в безопасности перейти дорогу
    2.2. определить наличие машин 
    2.3. пока есть машины
    2.3.1. подождать, посмотреть на лево
    2.3.2. определить наличие машин
    2.4. убедившись в безопасности дойти до середины дороги
    2.5. до тех пор пока есть машины
    2.5.1. если смотрели на право подождать иначе посмотреть на право
    2.5.2. определить наличие машин
    2.5.3. убедитьс€ в безопасности, дойти до конца дороги
    3. конец
    */
    std::cout << "\n" << "The Library of Babel is a place for scholars to do research, for artists\n";
    std::cout << "\t" << "and writers to seek inspiration, for anyone with curiosity or a sense of\n";
    std::cout << "\t\t" << "humor to reflect on the weirdness of existence - in short, itТs just like\n";
    std::cout << "\t\t\t" << "any other library.If completed, it would contain every possible\n";
    std::cout << "\t\t\t\t" << "combination of 1, 312, 000 characters, including lower case letters,\n";
    std::cout << "\t\t\t\t\t" << "space, comma, and period.Thus, it would contain every book that ever\n";   
    std::cout << "\t\t\t\t\t\t" << "has been written, and every book that ever could be - including every\n";
    std::cout << "\t\t\t\t\t\t\t" << "play, every song, every scientific paper, every legal decision, every\n";
    std::cout << "\t\t\t\t\t\t\t\t" << "constitution, every piece of scripture, and so on.At present it contains\n";
    std::cout << "\t\t\t\t\t\t\t\t\t" << "all possible pages of 3200 characters, about 104677 books.\n";
    std::cout << "\n" << "Since I imagine the question will present itself in some visitorsТ minds\n";
    std::cout << "\t" << "(a certain amount of distrust of the virtual is inevitable) IТll head off any\n";
    std::cout << "\t\t" << "doubts : any text you find in any location of the library will be in the\n";
    std::cout << "\t\t\t" << "same place in perpetuity.We do not simply generateand store books as\n";
    std::cout << "\t\t\t\t" << "they are requested - in fact, the storage demands would make that\n";
    std::cout << "\t\t\t\t\t" << "impossible.Every possible permutation of letters is accessible at this\n";
    std::cout << "\t\t\t\t\t\t" << "very moment in one of the library's books, only awaiting its discovery. \n";
    std::cout << "\t\t\t\t\t\t\t" << " We encourage those who find strange concatenations among the\n";
    std::cout << "\t\t\t\t\t\t\t\t" << "variations of letters to write about their discoveries in the forum, so\n";
    std::cout << "\t\t\t\t\t\t\t\t\t" << "future generations may benefit from their research.\n";

    std::cout << std::endl << std::endl;

    std::cout << R"(
The Library of Babel is a place for scholars to do research, for artists 
    and writers to seek inspiration, for anyone with curiosity or a sense of 
        humor to reflect on the weirdness of existence - in short, itТs just like 
            any other library. If completed, it would contain every possible 
                combination of 1,312,000 characters, including lower case letters, 
                    space, comma, and period. Thus, it would contain every book that ever 
                        has been written, and every book that ever could be - including every 
                            play, every song, every scientific paper, every legal decision, every 
                                constitution, every piece of scripture, and so on. At present it contains 
                                    all possible pages of 3200 characters, about 104677 books.

Since I imagine the question will present itself in some visitorsТ minds 
    (a certain amount of distrust of the virtual is inevitable) IТll head off any 
        doubts: any text you find in any location of the library will be in the 
            same place in perpetuity. We do not simply generate and store books as 
                they are requested - in fact, the storage demands would make that 
                    impossible. Every possible permutation of letters is accessible at this 
                        very moment in one of the library's books, only awaiting its discovery. 
                            We encourage those who find strange concatenations among the 
                                variations of letters to write about their discoveries in the forum, so 
                                    future generations may benefit from their research.
)";

    //task 1

    double R0, R1, R2, R3; //множествена€ инициализаци€
    R0 = R1 = R2 = R3 = 0; //множественное присвоение

    std::cout << "input R1: ";
    std::cin >> R1;
    std::cout << "input R2: ";
    std::cin >> R2;
    std::cout << "input R3: ";
    std::cin >> R3;

    R0 = 1 / R1 + 1 / R2 + 1 / R3;
    R0 = 1 / R0;

    std::cout << "1/R0 = 1/R1 + 1/R2 + 1/R3\tR0= " << R0 << std::endl;

    std::cout << std::endl << std::endl;

    //task 2

    const double PI = 3.14; // константа - нельз€ изменить во врем€ выполнени€
    double S, R, L;
    S = R = L = 0;
    std::cout << "input length circle: ";
    std::cin >> L;

    //L = 2 * PI * R
    //L? 
    //R = P/2*PI
    R = L / (2 * PI);

    //S = PI * R^2
    S = PI * std::pow(R, 2); // pow(a, b) из библиотеки cmath где а - число b - степень;
    std::cout << "result S = " << S;
    std::cout << std::endl << std::endl;
    
    //task 3

    double v, t, a;
    S = v = t = a = 0; // множественное присвоение, так как S уже была проинициализирована остаетьс€ только обнулить 
    
    //S = v * t + (a * t^2) / 2
    std::cout << "input speed: ";
    std::cin >> v;

    std::cout << "input time: ";
    std::cin >> t;

    std::cout << "input acceleration: ";
    std::cin >> a;
    S = v * t + ((a * pow(t, 2)) / 2);
    
    std::cout << "range S = " << S << std::endl;
    std::cout << std::endl << std::endl;

    return 0;
}