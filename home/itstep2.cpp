#define _USE_MATH_DEFINES

#include <iostream>
#include <locale>
#include <cstdlib>


//using namespace std;

int main(int argc, char* argv[])
{
    //setlocale(LC_ALL, "rus");
    system("chcp 1251"); //аналог setlocale (на время лекции для вывода кирилицы)
    system("cls");

    const double PI = 3.1415926535; //константа типа double
    const float sPI = 3.14;
    double weght_atom = 2.5194e-17; // 0.000000000000000025194
    float somef = 2.25e+2;

    int _a; //объявление перемнной _a типа int 
    /*
    int _b = 0; инициализация
    int _b(0);
    int _b = {0};
    int _b{0};

    int _b; //объявление
    _b = 0; //присваивание
    */

    std::cout << "Число Пи: \t" << PI << std::endl;
    std::cout << "Масса атома: " << weght_atom << std::endl;
    std::cout << "Переменная somef = " << somef << std::endl;

    system("pause");
    system("cls");
    
    //в отдельном файле(нет)
    {
        int A;
        int B;
        int S;

        A = 0;
        B = 0;
        S = 0;

        std::cout << "--Программа для высичления площади прямоугольника--" << std::endl;
        std::cout << "Введите длину стороны A: "; std::cin >> A;
        std::cout << "Введите длину стороны B: "; std::cin >> B;

        //S = A * B площадь прямоугольника
        S = A * B;

        std::cout << "Результат, площадь прямоугольника: S = " << S << std::endl;
        system("pause");
        system("cls");
    };

    /*
    //Вопрос таков 
    //можно ли сделать подобную систему ввода вывода более оптимизированно(автоматизированно)
    //
    //             Please Login With Admin Credentials!
    //              ===================================
    //              +   [=] Enter Username:1          +   после двоеточия ввод данных
    //              +   [=] Enter Password:2          +
    //              ===================================
    //
    //код:
    //-----------------------------------------------------------------------------
    #include <string>
    std::string something, something2;

    std::cout << "                 Please Login With Admin Credentials!" << std::endl;
    std::cout << "                  ===================================" << std::endl;
    std::cout << "                  +   [=] Enter Username:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something;

    std::cout << "                  +   [=] Enter Password:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something2;

    std::cout << "                  ===================================" << std::endl;

    //-----------------------------------------------------------------------------

    //конкретнее смущают циклы с escape-последовательностью возрата/backspace
    //*/

    system("chcp 866"); // на время лабораторных для вывода псевдографики
    system("cls");
    //week 2.1 task 3
    {
        /* //вывод символов в диапозоне
        for (int i = 179; i < 219; i++)
        {
            std::cout << i << "\t:\t" << char(i) << std::endl;
        }
        */

        //вывод табоицы с символами псевдографики (не работает при сипользовании setlocale(LC_ALL, "rus"))
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

        system("pause");
        system("cls");
    };

    system("chcp 1251");
    system("cls");
    //week 2.2 task 1
    {

        std::cout << "--Программа определения високосных годов--" << std::endl;
        std::cout << "Введите год: ";
        int* a = new int(0); // year 
        std::cin >> *a;
        /*
        год является високосным в двух случаях:
        либо он кратен 4, но при этом не кратен 100,
        либо кратен 400
        */
        std::cout << "In " << *a << " year" << " = " << 365 + (int)((*a % 4 == 0 && *a % 100 != 0) || (*a % 400 == 0)) << " days" << std::endl;
        
        delete a;

        system("pause");
        system("cls");
    };

    //week 2.2 task 2
    {
        int rub; // рубли
        int cent; // копейки

        std::cout << "--Программа коррекции ввода данных--" << std::endl;
        std::cout << "Введите рубли: "; std::cin >> rub;
        std::cout << "Введите копейки: "; std::cin >> cent;

        if (cent >= 100)
        {
            rub += int(cent / 100);
            cent %= 100;
        }

        std::cout << "Результат: " << rub << " руб. " << cent << " коп. " << std::endl;

        system("pause");
        system("cls");
    };
    
    //week 2.2 task 3
    {
        std::cout << "--Программа вычесления объема паралелопипеда--" << std::endl;
        float* a = new float(0.f);//Длина
        float* b = new float(0.f);//Ширина
        float* h = new float(0.f);//Высота
        float* v = new float(0.f);//Объем

        std::cout << "Длина (см) -> "; std::cin >> *a;
        std::cout << "Ширина (см) -> "; std::cin >> *b;
        std::cout << "Высота (см) -> "; std::cin >> *h;

        //V = a*b*h
        *v = (*a) * (*b) * (*h);

        std::cout << "Объем: " << *v << " Куб. см." << std::endl;

        delete a;
        delete b;
        delete h;
        delete v;

        system("pause");
        system("cls");
    };

    //week 2.2 task 4
    {
        std::cout << "--Программа вычесления дистанции между двумя объектами на карте--" << std::endl;
        float* a = new float(0.f);//Масштаб
        float* b = new float(0.f);//Расстояние между точками на карте
        float* c = new float(0.f);//Расстояние между объектами

        std::cout << "Введите исходные данные:" << std::endl;
        std::cout << "\tМасштаб карты (количество километров в одном сантиметре) -> "; std::cin >> (*a);
        std::cout << "\tРастояние между точками на карте (см) -> "; std::cin >> (*b);
        //Результат = Масштаб * растояние на карте(см)
        (*c) = (*a) * (*b);
        std::cout << "\tРастояние между объектами " << (*c) << " км." << std::endl;


        delete a;
        delete b;
        delete c;
        system("pause");
        system("cls");
    };

    //week 2.2 task 5
    {
        #include <cmath>
        std::cout << "--Программа вычесления объема шара--" << std::endl;
        float r = 0.f;
        std::cout << "Введите радиус -> "; std::cin >> r;
        //V = (3/4) * (PI * r * r * r))
        std::cout << "Объем шара: " << double((4.f / 3.f) * (M_PI * r * r * r)) << " Куб. см." << std::endl;

        system("pause");
        system("cls");
    };

    system("chcp 866");
    system("cls");
    system("pause");

    return EXIT_SUCCESS;
}