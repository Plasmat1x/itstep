#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>

void h_w4_t1();

int main()
{
    h_w4_t1();
    return 0;
}

void h_w4_t1()
{
    /*
    Написать программу, реализующую процедуры заказа и
расчета его суммы в мини — пиццерии. В меню пиццерии
предусмотрено 4 вида пиццы и три вида напитков.
Пользователю выводится меню (вначале пиццы, потом
напитки), содержащее код и название. Пользователь вводит
код желаемого продукта, после чего вводит количество единиц
данного продукта.
В пиццерии предусмотрены два вида скидок:
■■если общая сумма заказа более 50$, то размер скидки со-
ставляет 20% от суммы заказа;
■■каждая пятая пицца — в подарок;
■■для напитков с ценой более 2$, если количество в зака-
зе более трех, то скидка 15% (только на напитки, а не на
весь заказ).
Вывести пользователю «чек» для оплаты в виде: название —
количество — цена. Итого к оплате.
    */

    std::stringstream os;   // поток для сбора чека для вывода единым целым

    bool isDone = false;    // условие выхода из цикла

    enum class Pizza : int  // перечисление вид пицц   
    {
        _NULL,
        PEPERRONI,
        HAWAI,
        CHEESE,
        MARGARITA
    };
    /*
    Присутсвует проблема, при обычном перечислении, выдает ошибку компиляции redifinition enumerator
    c enum class данной проблемы нету, но из-за этого приходится в вводе дополнительно проводить проверку if
    на прямую сравнивать не дают, ошибка типов.
    */

    enum class Drink : int
    {
        _NULL,
        COLA,
        JUICE,
        TEA
    };

    Pizza pizza = Pizza::_NULL; //переменная хранит одно из значений перечислений 
    int pizza_type = 0;         //переменная "интерфейс" вводимая с клавиатуры в условии взаимодействует с enum class объектом стр.166

    Drink drink = Drink::_NULL; //аналогично
    int drink_type = 0;

    int drink_count = 0;            //переменная подсчета всех напитков
    float drink_sum = 0;            //переменная подсчета всей суммы напитков
    float drink_discount = 0.15f;   //скидка на напитки

    int pizza_count = 0;            //переменная подсчета всех пицц
    int free_obtained = 0;          //переменная подсчета уже полученных бесплатных пицц
    float pizza_sum = 0;            //сумма пицц

    float total_discount = 0.20f;   //скидка на весь чек

    int add = 0;                    //переменная для подсчета добавочной пиццы
    float _pizza_sum = 0;           //переменная для подсчета суммы внутри одной позиции
    float _drink_sum = 0;           //аналогично
    float total_sum = 0;            //общая сумма
    int _count = 0;                 //вводимое кол-во продукта

    std::cout << "<-Пиццерия->" << std::endl;
    std::cout <<
        R"(Меню:
    Пицца:
        1. Пеперрони 4.99$
        2. Гавайская 3.45$
        3. Четыре сыра 2.86$
        4. Маргарита 4.45$
        0. Выйти
    Напитки:
        1. Кола 0.99$
        2. Сок 2.35$
        3. Чай 0.4$
        0. Выйти
)" << std::endl;

    while (!isDone)
    {
        add = 0;
        _count = 0;

        std::cout << "Введите номер пиццы: "; std::cin >> pizza_type;

        if (pizza_type == 0) { pizza = Pizza::_NULL; }
        else if (pizza_type == 1) { pizza = Pizza::PEPERRONI; }
        else if (pizza_type == 2) { pizza = Pizza::HAWAI; }
        else if (pizza_type == 3) { pizza = Pizza::CHEESE; }
        else if (pizza_type == 4) { pizza = Pizza::MARGARITA; }

        switch (pizza)
        {
            //данный фрагмент кода лучше было написать в качестве функции, ибо повторение одного и того же
        case Pizza::PEPERRONI:  //4.99
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            pizza_count += _count;
            _pizza_sum = 4.49 * _count;
            os << "\nПеперрони:\t\t$4.49\n"
                << "\t\t\tx" << _count << std::endl;
            add = pizza_count / 5 - free_obtained;
            free_obtained = pizza_count / 5;
            _pizza_sum -= add * 4.49;
            os << "\t\t\t$" << _pizza_sum << std::endl;
            os << "free pizza\t\tx" << add << std::endl;
            pizza_sum += _pizza_sum;
            break;
        }
        case Pizza::HAWAI:  //3.45
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            pizza_count += _count;
            _pizza_sum = 3.45 * _count;
            os << "\nГавайская:\t\t$3.45\n"
                << "\t\t\tx" << _count << std::endl;
            add = pizza_count / 5 - free_obtained;
            free_obtained = pizza_count / 5;
            _pizza_sum -= add * 3.45;
            os << "\t\t\t$" << _pizza_sum << std::endl;
            os << "free pizza\t\tx" << add << std::endl;
            pizza_sum += _pizza_sum;
            break;
        }
        case Pizza::CHEESE: //2.86
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            pizza_count += _count;
            _pizza_sum = 2.86 * _count;
            os << "\nЧетыре сыра:\t\t$2.86\n"
                << "\t\t\tx" << _count << std::endl;
            add = pizza_count / 5 - free_obtained;
            free_obtained = pizza_count / 5;
            _pizza_sum -= add * 2.86;
            os << "\t\t\t$" << _pizza_sum << std::endl;
            os << "free pizza\t\tx" << add << std::endl;
            pizza_sum += _pizza_sum;
            break;
        }
        case Pizza::MARGARITA:  //4.45
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            pizza_count += _count;
            _pizza_sum = 4.45 * _count;
            os << "\nМаргарита:\t\t$4.45\n"
                << "\t\t\tx" << _count << std::endl;
            add = pizza_count / 5 - free_obtained;
            free_obtained = pizza_count / 5;
            _pizza_sum -= add * 4.45;
            os << "\t\t\t$" << _pizza_sum << std::endl;
            os << "free pizza\t\tx" << add << std::endl;
            pizza_sum += _pizza_sum;
            break;
        }
        case  Pizza::_NULL: //exit from loop
            isDone = !isDone;
            break;
        default:
            std::cout << "Не правильная позиция" << std::endl;
            break;
        }
    }
    os << "\nСумма пицц:\t\t$" << pizza_sum << std::endl;

    isDone = false;

    //такойже цикл для напитков
    while (!isDone)
    {
        add = 0;
        _count = 0;
        std::cout << "Введите номер напитка: "; std::cin >> drink_type;

        if (drink_type == 0) { drink = Drink::_NULL; }
        else if (drink_type == 1) { drink = Drink::COLA; }
        else if (drink_type == 2) { drink = Drink::JUICE; }
        else if (drink_type == 3) { drink = Drink::TEA; }

        switch (drink)
        {
        case Drink::COLA:   //0.99
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            drink_count += _count;
            _drink_sum = 0.99 * _count;
            os << "\nКола:\t\t\t$0.99\n"
                << "\t\t\tx" << _count << std::endl;
            os << "\t\t\t$" << _drink_sum << std::endl;
            drink_sum += _drink_sum;
            break;
        }
        case Drink::JUICE:  //2.35
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            drink_count += _count;
            _drink_sum = 2.35 * _count;
            os << "\nСок:\t\t\t$2.35\n"
                << "\t\t\tx" << _count << std::endl;
            os << "\t\t\t$" << _drink_sum << std::endl;
            drink_sum += _drink_sum;
            break;
        }

        case Drink::TEA:    //0.4
        {
            std::cout << "Введите количество продукта: "; std::cin >> _count;
            drink_count += _count;
            _drink_sum = 0.4 * _count;
            os << "\nЧай:\t\t\t$0.4\n"
                << "\t\t\tx" << _count << std::endl;
            os << "\t\t\t$" << _drink_sum << std::endl;
            drink_sum += _drink_sum;
            break;
        }
        case  Drink::_NULL:
            isDone = !isDone;
            break;
        default:
            std::cout << "Не правильная позиция" << std::endl;
            break;
        }
    }

    //проверка на скидку для напитков + вычисление суммы напитков с учетом скидки
    if (drink_count > 3 && drink_sum > 2.0)
    {
        drink_sum *= (1.0f - drink_discount);
        os << "Скидка на напитки 15%" << std::endl;
    }
    os << "Сумма напитков:\t\t$" << drink_sum << std::endl;

    //вычесленние суммы чека и также применение скидки при условии
    total_sum = drink_sum + pizza_sum;
    if (total_sum > 50)
    {
        total_sum *= (1.0f - total_discount);
        os << "Скидка на весь чек 20%" << std::endl;
    }
    os << "ИТОГ:\t\t\t" << total_sum << std::endl;

    std::cout << os.str(); //вывод сформированного потока в виде чека

    system("pause");
}
