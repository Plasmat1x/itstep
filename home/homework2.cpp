#include<iostream>
#include<cstdlib>
#include<cmath>

namespace mmath // minus global scope
{
    // namespace для факториала
    int i = 1;
    unsigned long int result;

    unsigned long int factorial(unsigned long int x)
    {
        if (x == 1 || x == 0)   // условие завершения рекурсии
            return 1;           // после выполнения условия код ниже не выполняется -> рекурсия прерывается
        else
        {
            i++;
            result = x * factorial(x - 1);
        }
        return result;
    }
}

void calc2();
void h_w5_t1();
void h_w5_t2();
void h_w5_t3();
void l_w6_t1t2t3t4();

int main()
{
    system("chcp 1251");
    system("cls");

    calc2();
    h_w5_t1();
    h_w5_t2();
    h_w5_t3();
    l_w6_t1t2t3t4();

    system("chcp 866");
    return 0;
}

void h_w5_t1()
{
    /*
    Пользователь вводит с клавиатуры символ. Определить,
    какой это символ: Буква, цифра, знак препинания или другое.
    */


    char sym; //ввод

    std::cout << "<-Проверка введенного символа->" << std::endl;
    std::cout << "Введите символ: "; std::cin >> sym;

    if ((int)sym < 32 && (int)sym >= 0)
    {
        std::cout << "Служебный символ" << std::endl;
    }
    else if ((int)sym >= 48 && (int)sym < 58)
    {
        std::cout << "Цифра" << std::endl;
    }
    else if (((int)sym > 64 && (int)sym < 91) || ((int)sym > 96 && (int)sym < 123))
    {
        if ((int)sym > 64 && (int)sym < 91)
        {
            std::cout << "Заглавная буква" << std::endl;
        }
        else
        {
            std::cout << "Строчная буква" << std::endl;
        }
    }
    else if((int)sym == 44 || (int)sym == 46 || (int)sym == 33 || (int)sym == 58 || (int)sym == 59 || (int)sym == 63)
    {
        std::cout << "Знаки препинания" << std::endl;
    }
    else
    {
        std::cout << "Другие символы (скобки, арифметические операторы и тд.)" << std::endl;
    }
    //p.s. сделано для первых 128 символов стандартной таблицы ASCII, для расширенной с кирилицей просто добавляется диапазон симоволов для русских букв(стр. 61)
}

void h_w5_t2()
{
    /*
    Написать программу подсчета стоимости разговора для
разных мобильных операторов. Пользователь вводит дли-
тельность разговора и выбирает с какого на какой оператор
он звонит. Вывести стоимость на экран.
    */
    system("cls");

    int speek_time = 0;
    int to = 0;
    int from = 0;
    float money_per_seconds = 0;

    enum Service
    {
        BILINE,
        MTC,
        T2,
        MEGAFON
    };

    float price1;
    float price2;
    float price3;
    float price4;

    Service service1;
    Service service2;

    std::cout << "<-Подсчет стоимости->" << std::endl;
    std::cout << R"(Операторы:
0 BILINE
1 MTC
2 T2
3 MEGAFON)" << std::endl;
    std::cout << "Введите время разговора: "; std::cin >> speek_time;
    std::cout << "Выбирите оператора с которого производиться звонок: "; std::cin >> from;
    std::cout << "Выбирите оператора на которого производиться звонок: "; std::cin >> to;

    if (from == 0) service1 = Service::BILINE;
    else if (from == 1) service1 = Service::MTC;
    else if (from == 2) service1 = Service::T2;
    else service1 = Service::MEGAFON;

    if (to == 0) service2 = Service::BILINE;
    else if (to == 1) service2 = Service::MTC;
    else if (to == 2) service2 = Service::T2;
    else service2 = Service::MEGAFON;

    switch (service1)
    {
    case Service::BILINE:
        price1 = 0.01f;
        price2 = 0.5f;
        price3 = 1.0f;
        price4 = 1.5f;

        if (service2 == MTC) money_per_seconds = price1;
        else if (service2 == T2) money_per_seconds = price2;
        else if (service2 == MEGAFON) money_per_seconds = price3;
        else money_per_seconds = price1;

        break;

    case Service::MTC:
        price1 = 0.01f;
        price2 = 0.5f;
        price3 = 1.6f;
        price4 = 7.5f;

        if (service2 == MTC) money_per_seconds = price1;
        else if (service2 == T2) money_per_seconds = price2;
        else if (service2 == MEGAFON) money_per_seconds = price3;
        else money_per_seconds = price1;

        break;

    case Service::T2:
        price1 = 0.01f;
        price2 = 5.5f;
        price3 = 2.0f;
        price4 = 1.5f;

        if (service2 == MTC) money_per_seconds = price1;
        else if (service2 == T2) money_per_seconds = price2;
        else if (service2 == MEGAFON) money_per_seconds = price3;
        else money_per_seconds = price1;

        break;

    case Service::MEGAFON:
        price1 = 0.01f;
        price2 = 10.5f;
        price3 = 15.0f;
        price4 = 22.5f;

        if (service2 == MTC) money_per_seconds = price1;
        else if (service2 == T2) money_per_seconds = price2;
        else if (service2 == MEGAFON) money_per_seconds = price3;
        else money_per_seconds = price1;

        break;

    default: 
        std::cout << "Не верный оператор" << std::endl;
        break;
    }

    std::cout << "Цена разговора афро$" << speek_time * money_per_seconds << std::endl;
}

void state1();
void state2();
void state3();

const int income = 50;
const int penalty = 20;
const int row_to_income = 100;
const int skip_to_penalty = 3;

void h_w5_t3()
{
    /*
    Вася работает программистом и получает 50$ за каждые
100 строк кода. За каждое третье опоздание на работу Васю
штрафуют на 20$. Реализовать меню:
■■ пользователь вводит желаемый доход Васи и количество
опозданий, посчитать, сколько строк кода ему надо написать;
■■ пользователь вводит количество строк кода, написанное
Васей и желаемый объем зарплаты. Посчитать, сколько
раз Вася может опоздать;
■■ пользователь вводит количество строк кода и количество
опозданий, определить, сколько денег заплатят Васе и
заплатят ли вообще.
    */
    //start date 22.01.22 06:10
    int menu_state = 0;

    std::cout << "<-Василий работает->" << std::endl;
    std::cout << "Меню: \n\t0.Выход\n\t1.Строки\n\t2.Опоздания\n\t3.Зарплата\n";
    std::cin >> menu_state;
    
    switch (menu_state)
    {
    case 1:
        state1();
        break;
    case 2:
        state2();
        break;
    case 3: 
        state3();
        break;
    case 0:
    default:
        std::cout << "Команда ввыхода или неверная комманда" << std::endl;
        break;
    }
    //end date 22.01.2022 17:27
    system("pause");
}

void state1()
{
    /*■■ пользователь вводит желаемый доход Васи и количество
опозданий, посчитать, сколько строк кода ему надо написать;*/

    //*
    int _income_wish = 0;
    int _income_result = 0;
    int _income_count_add = 0;
    int _skiped = 0;
    int _row_need = 0;
    int _penalty_count = 0;
    float _penalty_sum = 0;

    std::cout << "желаемый доход Васи и количество опозданий, посчитать, сколько строк кода ему надо написать" << std::endl;
    std::cout << "\nВведите желаемый доход: "; std::cin >> _income_wish;
    std::cout << "\nВведите количество опозданий: "; std::cin >> _skiped;
    
    _row_need = _income_wish / income * row_to_income;
    _penalty_count = _skiped / skip_to_penalty;
    _penalty_sum = _penalty_count * penalty;
    _income_result = _income_wish - _penalty_sum;
    float tmp = _income_wish - _income_result;
    float tmp2 = tmp / income;
    if (tmp2 > 0)
    {
        _income_count_add = (int)tmp2 + 1;
        _row_need += _income_count_add * row_to_income;
    }
    _income_result += _income_count_add * income;

    std::cout << "\nСтрок необходимо: " << _row_need << std::endl;
    std::cout << "\nОплата: " << _income_result << std::endl;
}

void state2()
{
    /*■■ пользователь вводит количество строк кода, написанное
Васей и желаемый объем зарплаты. Посчитать, сколько
раз Вася может опоздать;*/
    int _income_wish = 0;
    int _income_potential_get = 0;
    int _skiped_allow = 0;
    int _row_writed = 0;
    int _penalty_count_allow = 0;
    int _penalty_sum_allow = 0;
    int _income_result = 0;

    std::cout << "количество строк кода, написанное Васей и желаемый объем зарплаты.Посчитать, сколько раз Вася может опоздать" << std::endl;
    
    std::cout << "Введите количество написанных строк: "; std::cin >> _row_writed;
    std::cout << "Введите желаемый доход: "; std::cin >> _income_wish;

    _income_potential_get = _row_writed / row_to_income * income;
    _penalty_sum_allow = _income_potential_get - _income_wish;
    _penalty_count_allow = _penalty_sum_allow / penalty;
    float tmp = (float)_penalty_sum_allow / penalty - _penalty_count_allow;
    int tmp2 = skip_to_penalty / tmp;
    if (_penalty_count_allow > 0)
    {
        _skiped_allow = skip_to_penalty * tmp + tmp2;
    }
    _income_result = _income_potential_get - _penalty_sum_allow;
    std::cout << "Можно опаздать (низя): " << _skiped_allow << std::endl;
    std::cout << "Доход: " << _income_result << std::endl;
}

void state3()
{
    /*■■ пользователь вводит количество строк кода и количество
опозданий, определить, сколько денег заплатят Васе и
заплатят ли вообще.*/

    int _income_get = 0;
    int _skiped_count = 0;
    int _row_writed = 0;
    int _penalty_count = 0;
    int _penalty_sum = 0;

    std::cout << "количество строк кода и количество опозданий, определить, сколько денег заплатят Васе и заплатят ли вообще" << std::endl;
    std::cout << "Введите количество строк: "; std::cin >> _row_writed;
    std::cout << "Введите количество опазданий: "; std::cin >> _skiped_count;

    _income_get = _row_writed / row_to_income * income;
    _penalty_count = _skiped_count / skip_to_penalty;
    _penalty_sum = _penalty_count * penalty;
    _income_get -= _penalty_sum;
    if (_income_get > 0)
        std::cout << "Доход: " << _income_get << std::endl;
    else
        std::cout << "Без дохода" << std::endl;
}

void l_w6_t1t2t3t4()
{
    /*
Задание 1. Вывести на экран все числа от нуля до вве-
денного пользователем числа.


Задание 2. Пользователь вводит две границы диапазона,
вывести на экран все числа из этого диапазона. Преду-
смотреть, чтобы пользователь мог вводить границы ди-
апазона в произвольном порядке.
■■ вывести все четные числа из диапазона.
■■ вывести все нечетные числа из диапазона.
■■ вывести все числа, кратные семи.


Задание 3. Пользователь вводит две границы диапазона.
Посчитать сумму всех чисел диапазона.


Задание 4. Пользователь с клавиатуры вводит числа.
Посчитать их сумму и вывести на экран, как только поль-
зователь введет ноль.
*/
    //t1
    int n = 0;
    std::cout << "--Вывод чисел от 0 до n--" << std::endl;
    std::cout << "Введите число: "; std::cin >> n;
    for (int i = 0; i < n + 1; i++)
        std::cout << i << std::endl;

    system("pause");
    system("cls");

    //t2
    int l = 0;
    int h = 0;
    std::cout << "--Вывод чисел в диапозоне--" << std::endl;
    std::cout << "Введите число: "; std::cin >> l;
    std::cout << "Введите число: "; std::cin >> h;

    int tmp = 0;
    if (l > h) { tmp = h; h = l; l = tmp; }
        
    //for (l+=1; l < h; l++) // без включений границ
    for (l; l<=h; l++)       // с включением границ
        std::cout << l << std::endl;

    system("pause");
    system("cls");

    //t3
    int a = 0;
    int b = 0;
    int sum = 0;
    std::cout << "--Вывод чисел в диапозоне--" << std::endl;
    std::cout << "Введите число: "; std::cin >> a;
    std::cout << "Введите число: "; std::cin >> b;

    tmp = 0;
    if (a > b) { tmp = b; b = a; a = tmp; }

    //for (a+=1; a < b; a++) // без включений границ
    for (a; a <= b; a++)       // с включением границ
        sum += a;
    std::cout << "Сумма диапозона: " << sum << std::endl;

    system("pause");
    system("cls");

    //t3
    int input = 0;
    sum = 0;

    do
    {
        system("cls");
        std::cout << "--Вывод чисел в диапозоне--" << std::endl;
        std::cout << "Сумма " << sum << std::endl;
        std::cout << "Введите число: "; std::cin >> input;

        sum += input;

    } while (input != 0);

    system("pause");
    system("cls");
}


void calc2()
{
    system("cls");
    std::cout << "---calc2 prog---" << std::endl;
    double a = 0;
    double b = 0;
    char op;
    std::cout << "enter number: "; std::cin >> a;

    bool _iswork = true; // булл для выхода из цикла;

    /*
    X - to stop cycle;

    суть данного решения в цикличности выполнения операций пока пользователь не завершит программу через операцию
    */

    while (_iswork) // вариант бесконечного цикла пока _iswork = true будет работать цикл
    {
        //system("cls");
        std::cout << "resault: " << a << std::endl;
        std::cout << R"(
'+' - Сложение
'-' - Вычитание
'*' - Умножение
'/' - Деление
'^' - Число А в степени В
'V' - Корень А-ой степени из В
'!' - Факториал числа А
'%' - остаток деления числа А на число B
)" << std::endl;
        std::cout << "enter operation: "; std::cin >> op; // при вводе +3 выполняется корректно

        switch (op)
        {
        case '+': //сложение b
            std::cout << "enter number: "; std::cin >> b;
            a += b;
            std::cout << a << std::endl;
            break;
        case '-': //вычитание b
            std::cout << "enter number: "; std::cin >> b;
            a -= b;
            std::cout << a << std::endl;
            break;
        case '*': //умножение на b
            std::cout << "enter number: "; std::cin >> b;
            a *= b;
            std::cout << a << std::endl;
            break;
        case '/': //деление на b
            std::cout << "enter number: "; std::cin >> b;
            if (b == 0) { std::cout << "error div 0 imposible" << std::endl; break; }
            a /= b;
            std::cout << a << std::endl;
            break;
        case '^': //возведение в степень b
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, b);
            std::cout << a << std::endl;
            break;
        case '%': //отстаток от деления на b
            std::cout << "enter number: "; std::cin >> b;
            a = int(a) % (int)b;
            std::cout << a << std::endl;
            break;
        case 'v':
        case'V': //корень степени b от числа
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, 1.0 / b);
            std::cout << a << std::endl;
            break;
            //*
        case'!': //факториал числа a
            //функция_рекурсии(a);
            a = mmath::factorial(a);
            std::cout << a << std::endl;
            break;
            //*/
        case 'x':
        case'X':
            _iswork = false; //условие выхода из цикла
            break;
        default:
            std::cout << "wrong operation!" << std::endl;
            break;
        }
    }
}