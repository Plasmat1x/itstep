#include <iostream>
#include <cstdlib>
#include <Windows.h>

void regioncode();
void factorial();

void shape_out();
void color_shape_out();

enum Colors {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

template<Colors txt = White, Colors bg = Black>
std::ostream& color(std::ostream& text);

void half_year_income();
void revers_print();
void pentagram_border_lenght();
void year_min_max_income();

int main()
{
    system("chcp 1251");
    system("cls");

    //regioncode();
    system("pause");

    system("cls");
    //factorial();
    system("pause");

    system("cls");
    //shape_out();
    system("pause");

    system("cls");
    //color_shape_out();
    system("pause");
    
    system("cls");
    //half_year_income();
    system("pause");

    system("cls");
    //revers_print();
    system("pause");

    system("cls");
    //pentagram_border_lenght();
    system("pause");

    system("cls");
    year_min_max_income();

    system("pause");
    system("chcp 866");
    return 0;
}

void regioncode()
{
    std::cout << "---prog region code---" << std::endl;

    int code = 0;
    std::cout << "enter code "; std::cin >> code;

    enum Regions
    {

        Chel = 74,
        Chel1 = 174,
        Chel2 = 774,

        Ekb = 66,
        Ekb1 = 96,
        Ekb2 = 166,
        Ekb3 = 196,

        Tom = 70,
        Alt = 22,
        Dag = 05,
        Kem = 42,
        Ksn = 124,
        Tyv = 17,

        Vld = 25,
        Vld1 = 125,

        spb = 78,
        spb1 = 98,
        spb2 = 178,

        MskObl = 50,
        MskObl1 = 90,
        MskObl2 = 150,
        MskObl3 = 190,
        MskObl4 = 750,
        MskObl5 = 790,

        Msk = 77,
        Msk1 = 97,
        Msk2 = 99,
        Msk3 = 177,
        Msk4 = 197,
        Msk5 = 199,
        Msk6 = 277,
        Msk7 = 299,
        Msk8 = 777,
        Msk9 = 799,
    };

    switch (code)
    {
    case Regions::Msk:
    case Regions::Msk1:
    case Regions::Msk2:
    case Regions::Msk3:
    case Regions::Msk4:
    case Regions::Msk5:
    case Regions::Msk6:
    case Regions::Msk7:
    case Regions::Msk8:
    case Regions::Msk9:
        std::cout << "Москва!" << std::endl;
        break;

    case Regions::MskObl:
    case Regions::MskObl1:
    case Regions::MskObl2:
    case Regions::MskObl3:
    case Regions::MskObl4:
    case Regions::MskObl5:
        std::cout << "Московская область!" << std::endl;
        break;

    case Regions::Ekb:
    case Regions::Ekb1:
    case Regions::Ekb2:
    case Regions::Ekb3:
        std::cout << "Свердловская область!" << std::endl;
        break;

    case Regions::Chel:
    case Regions::Chel1:
    case Regions::Chel2:
        std::cout << "Челябинская область!" << std::endl;
        break;

    case Regions::spb:
    case Regions::spb1:
    case Regions::spb2:
        std::cout << "Ленинградская область!" << std::endl;

    case Regions::Vld:
    case Regions::Vld1:
        std::cout << "Приморский край!" << std::endl;
        break;

    case Regions::Tom:
        std::cout << "Томкася область!" << std::endl;
        break;
    case Regions::Alt:
        std::cout << "Алтайский край!" << std::endl;
        break;
    case Regions::Dag:
        std::cout << "Республика Дагестан!" << std::endl;
        break;
    case Regions::Kem:
        std::cout << "Кемеровская область!" << std::endl;
        break;
    case Regions::Ksn:
        std::cout << "Красноярский край!" << std::endl;
        break;
    case Regions::Tyv:
        std::cout << "Республика Тыва!" << std::endl;

    default:
        std::cout << "region not found!" << std::endl;
        std::cout << "buy premium edition!" << std::endl;
        break;
    }
}

void factorial()
{
    std::cout << "<--Вычисление факториала-->" << std::endl;
    int n; 
    std::cout << "Введите число "; std::cin >> n;
    int i = n;
    while (i > 1)
    {
        i--;
        n *= i;
    }
    std::cout << "Факториал числа равен " << n << std::endl;
}

void shape_out() 
{
    //Задание 1. Вывести на экран прямоугольник с заданными
    //сторонами заданным символом.

    std::cout << "--Прямоугольник из символов--" << std::endl;
    int A, B;
    char ch;
    std::cout << "введите сторону A "; std::cin >> A;
    std::cout << "введите сторону B "; std::cin >> B;
    std::cout << "введите символ которым хотите рисовать "; std::cin >> ch;
    
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < A; j++)
        {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

template<Colors txt, Colors bg>
std::ostream& color(std::ostream& text) 
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    return text;
}

void color_shape_out()
{
    //Задание 2. Вывести на экран пустой прямоугольник
    //с заданными размерами заданным символом заданного
    //цвета.
    std::cout << "--Прямоугольник из символов--" << std::endl;
    int A, B;
    char ch;
    int color_;
    std::cout << "введите сторону A "; std::cin >> A;
    std::cout << "введите сторону B "; std::cin >> B;
    std::cout << "введите символ которым хотите рисовать "; std::cin >> ch;
    std::cout << R"(
    Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7,
    DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, 
    LightMagenta = 13, Yellow = 14, White = 15)" << std::endl;
    std::cout << "введите номер цвета символа "; std::cin >> color_;

    switch (color_)
    {
    case Colors::Black:
        std::cout << color<Black, White>;
        break;
    case Colors::Blue:
        std::cout << color<Blue, Black>;
        break;
    case Colors::Green:
        std::cout << color<Green, Black>;
        break;
    case Colors::Cyan:
        std::cout << color<Cyan, Black>;
        break;
    case Colors::Red:
        std::cout << color<Red, Black>;
        break;
    case Colors::Magenta:
        std::cout << color<Magenta, Black>;
        break;
    case Colors::Brown:
        std::cout << color<Brown, Black>;
        break;
    case Colors::LightGray:
        std::cout << color<LightGray, Black>;
        break;
    case Colors::DarkGray:
        std::cout << color<DarkGray, Black>;
        break;
    case Colors::LightBlue:
        std::cout << color<LightBlue, Black>;
        break;
    case Colors::LightGreen:
        std::cout << color<LightGreen, Black>;
        break;
    case Colors::LightCyan:
        std::cout << color<LightCyan, Black>;
        break;
    case Colors::LightMagenta:
        std::cout << color<LightMagenta, Black>;
        break;
    case Colors::Yellow:
        std::cout << color<Yellow, Black>;
        break;
    case Colors::White:
        std::cout << color<White, Black>;
        break;
    default:break;
    }


    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < A; j++)
        {
            if (i == 0 || i == B - 1) std::cout << ch;
            else if (j == 0 || j == A - 1) std::cout << ch;
            else std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << color<White, Black>;
}

void half_year_income()
{
    //Задание 1. Написать, программу, которая вычисляет при-
    //быль фирмы за 6 месяцев.Пользователь вводит прибыль
    //фирмы за каждый месяц.

    std::cout << "<-- half-year income --> " << std::endl;
    int arr[6];
    int sum = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << "Enter income in month " << i + 1 << " "; std::cin >> arr[i];
        sum += arr[i];
    }
    std::cout << "total income for 6 months " << sum << std::endl;
}

void revers_print()
{
    //Задание 2. Написать программу, которая выводит одно-
    //мерный массив в обратном порядке.
    std::cout << "<-- revers print -->" << std::endl;

    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void pentagram_border_lenght()
{
    /*
    Задание 3. Пользователь вводит длину сторон пятиуголь-
    ника, каждая сторона заноситься в массив, необходимо
    вычислить периметр пятиугольника (периметр — сумма
    всех сторон).
    */

    std::cout << "<-- Pentagram borders lenght -->" << std::endl;

    int sum=0;
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter border " << i+1 << " lenght "; std::cin >> arr[i];
        sum += arr[i];
    }
    std::cout << "Sum = " << sum << std::endl;

}

void year_min_max_income()
{
    /*
    Задание 4. Пользователь вводит прибыль фирмы за год
    (12 месяцев). Необходимо определить месяц, в котором
    прибыль была максимальна и месяц, в котором прибыль
    была минимальна.
    */

    std::cout << "<-- year income --> " << std::endl;
    int min = 0; 
    int max = 0;
    int m_max = 0;
    int m_min = 0;
    int arr[12];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << "Enter income in month " << i + 1 << " "; std::cin >> arr[i];

        if (i == 0)
        {
            min = arr[i];
            max = arr[i];
        }

        if (arr[i] > max) { max = arr[i]; m_max = i; }
        if (arr[i] < min) { min = arr[i]; m_min = i; }
    }

    std::cout << "Max income was in " << m_max << " month with $" << max << std::endl;
    std::cout << "Min income was in " << m_min << " month with $" << min << std::endl;
}
