#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath> // Для числа пи
#include <cstdlib>

void secondsToFormat(const int& seconds);
void moneySepFromFloat(const float& sum);
void daysToWeeks(const int& days);
void calcRuningSpeed(const int& dist, const float& time);

int main6(int argc, char* argv[])
{
    /*
    “Написать программу вычисления площади круга и длины окружности, 
    радиус вводится с клавиатуры. Результат выводится на экран. 
    (Для вычислений использовать переменные вещественных типов данных)”
    */
    system("chcp 1251");
    system("cls");

    float r = 0.f;//Радиус
    float l = 0.f;//Длина окружности
    float s = 0.f;//Площадь

    std::cout << "--Программа вычисления площади круга и длины окружности--" << std::endl;
    std::cout << "Введите радиус => "; std::cin >> r;

    //l=sqrt(S*4*PI) or l=2*PI*r
    //s=2*PI*r*r

    s = 2 * M_PI * r * r;
    l = 2 * M_PI * r;

    std::cout << "Резултат:" << std::endl;
    std::cout << "\tПлощадь окружности => " << s << std::endl;
    std::cout << "\tДлина окружности => " << l << std::endl;

    system("pause");
    system("cls");

    {
        std::cout << "--Программа конвертации секунд в форматное время (ЧЧ:ММ:СС)--" << std::endl;
        int seconds = 0;
        std::cout << "Введите время в секундах: "; std::cin >> seconds;
        secondsToFormat(seconds);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--Программа конвертации суммы денег ввида \"12.75\" в 12$ 75c--" << std::endl;
        float value = 0;//Сумма денег
        std::cout << "Введите сумму (дробное): "; std::cin >> value;
        moneySepFromFloat(value);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--Программа конвертации дней в недели + дни--" << std::endl;
        int value = 0;//дней
        std::cout << "Введите количество дней: "; std::cin >> value;
        daysToWeeks(value);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--Программа вычисления скорости бега--" << std::endl;
        float time = 0.f;
        int distance = 0;
        std::cout << "Введите длину дистацнии (метров) = "; std::cin >> distance;
        std::cout << "Введите время (мин.сек) = "; std::cin >> time;
        calcRuningSpeed(distance, time);

    };

    system("pause");
    system("cls");

    {
        /*
        Написать программу, которая предлагает пользователю
        ввести сумму денежного вклада в евро, а также процент годовых, которые выплачивает банк. Определить сумму денег,
        выплачиваемых банком вкладчику каждый месяц.
        */
        std::cout << "--Программа расчета дохода по вкладу--" << std::endl;
        float _value = 0.f; // сумма
        float _precent = 0.f; // процентная ставка
        float _income = 0.0f; // доход капитала

        std::cout << "Введите сумму вклада (euro): "; std::cin >> _value;
        std::cout << "Введите процентную ставку: "; std::cin >> _precent;

        float prec_val = _value / 100;
        _income = prec_val * _precent;
        std::cout << "Годовая сумма выплаты по ставке " << _precent << " % годовых: " << _income << " euro" << std::endl;
        _income /= 12;
        std::cout << "Ежемесечная сумма выплаты по ставке " << _precent << " % годовых: " << _income << " euro" << std::endl;
        
    };
    system("pause");
    system("cls");

    return EXIT_SUCCESS;
}

void secondsToFormat(const int& seconds)
{
    int Hours = 0;
    int Minutes = 0;
    int Seconds = 0;

    Seconds = seconds % 60;
    Minutes += seconds / 60;
    Hours += Minutes / 60;
    Minutes %= 60;

    std::cout << "Время: " << Hours << ":" << Minutes << ":" << Seconds << std::endl;
}

void moneySepFromFloat(const float& val)
{
    std::cout << int(val) << " $ " << int(100*(val-int(val))) << " c " << std::endl;
}

void daysToWeeks(const int& days)
{
    int _days = 0;
    int _weeks = 0;

    _days = days % 7;
    _weeks = days / 7;

    std::cout << _weeks << " недели " << _days << " дня" << std::endl;
}

void calcRuningSpeed(const int& dist, const float& time)
{
    int min = 0;
    int sec = 0;
    int sum_sec = 0;
    float speed = 0;

    sec += (time - int(time)) * 100;
    min += int(time) + (sec/60);
    sec %= 60;
    sum_sec += min * 60 + sec;

    speed = (float)dist / sum_sec;

    float speed_kmph = 3.6f * speed;

    std::cout << "Дистанция: " << dist << " м" << std::endl;
    std::cout << "Время: " << min << " мин " << sec << " сек = " << sum_sec << " сек" << std::endl;
    std::cout << "Вы бежали со скоростью " << speed_kmph << " км/ч" << std::endl;
}
