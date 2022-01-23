#include <iostream>
#include <cstdlib>
#include <cmath>

void radius()
{
    system("cls");
    std::cout << "---Программа определения принадлежности точки кольцу!---" << std::endl;
    float R1 = 0.0F, R2 = 0.0F, X0 = 0.0F, Y0 = 0.0F, x = 0.0F, y = 0.0F, L = 0.0F, a = 0.0F, b = 0.0F;

    //х,у - координаты точки
    //X0,Y0 - координаты центра кольца
    //R1 - внутренний радиус кольца
    //R2 - внешний радиус кольца
    //L - растояние от точки до центра кольца
    //a,b - отклонение точки от центра по осям X и Y
    std::cout << "Введите координаты центар кольца: " << std::endl;
    std::cout << "X0: "; std::cin >> X0;
    std::cout << "Y0: "; std::cin >> Y0;
    std::cout << "Radius's: " << std::endl;
    std::cout << "inner: "; std::cin >> R1;
    std::cout << "outer: "; std::cin >> R2;

    if ((R1 < 0) && (R2 < 0) && (R2 < R1)) // условие проверки на неправильно введеные данные если выполнится выдаст ошибку
    {
        std::cout << "Error:: R1 or R2 less than zero, or R2 less than R1" << std::endl;
        return;
    }

    std::cout << "Введите координаты точки: " << std::endl;
    std::cout << "x: "; std::cin >> x;
    std::cout << "y: "; std::cin >> y;
    a = x - X0;
    b = y - Y0;
    L = sqrtf(powf(a, 2) + powf(b, 2));

    if ((R1 <= L) && (L <= R2))
        std::cout << "Coords (" << x << "; " << y << ") included into ring" << std::endl;
    else 
        std::cout << "Coords (" << x << "; " << y << ") not included into ring" << std::endl;

    system("pause");
    return;
}

void _transport()
{
    system("cls");
    int cash = 0;

    std::cout << "<-Программа выбора транспорта->" << std::endl;
    std::cout << "\nВведите сумму денег в наличие: " << std::endl; std::cin >> cash;

    //тут должны быть отдельные переменные для транспортов (необходимо для удобной модификации программы что бы не лезть в глубину кода)

    if (cash == 0)
    {
        std::cout << "Выбираем ноги" << std::endl;
    }
    else if (cash >= 25 && cash < 35)
    {
        std::cout << "выбираем автобус" << std::endl;
    }
    else if (cash >= 35 && cash < 125)
    {
        std::cout << "выбираем трамвай" << std::endl;
    }
    else if (cash >= 125)
    {
        std::cout << "выбираем такси" << std::endl;
    }
    else
    {
        std::cout << "ошибка сумма меньше 0" << std::endl;
        system("pause");
        return;
    }

    system("pause");
    return;
}

int main(int argc, char* argv[])
{
    system("chcp 1251");
    //---------------------------------

    // < > >= <= == != - операторы сравнения и равенства

    // &&(and) ||(or) !(not) - операторы обьеденения и инверсии

    // if() условие 
    
    bool result = false;
    result = 10 > 11;
    std::cout << result << std::endl; // output 0

    bool bA, bB, bC;
    bA = bB = bC = false;
    
    //...
    //process var bA bB bC
    //...

    if (!bA != (bB && bC)) // условие с применением операторов объединения
    {
        //if do
    }
    else
    {
        //else do
    }

    system("pause");
    _transport();
    radius();

    //---------------------------------
    system("chcp 866");
    return 0;
}