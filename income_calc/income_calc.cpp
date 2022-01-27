#include <iostream>

const int income = 50;
const int penalty = 20;
const int row_to_income = 100;
const int skip_to_penalty = 3;

void h_w5_t3();
void state1();
void state2();
void state3();

int main()
{
    h_w5_t3();
    return 0;
}

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

