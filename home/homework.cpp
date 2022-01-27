#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>

void discount();
void h_w4_t1();
void h_w4_t2();

int main()
{
    system("chcp 1251");
    system("cls");
    
    //discount();
    //h_w4_t1();
    h_w4_t2();

    system("chcp 866");
    return EXIT_SUCCESS;
}

void discount()
{
    /*
    if (true) { ; }
    else if (false) { ; }
    else { ; }
    */

    float sum = 0.0f;
    float discount = 0.0f;
    float to_disc = 0.0f;

    std::cout << "discount " << std::endl;
    std::cout << "sum "; std::cin >> sum;

    if (sum <= 0)
    {
        std::cout << "wrong sum" << std::endl;
        return;
    }

    /*
    if (sum < 1000) { discount = 0.00f;     to_disc = 1000 - sum; }
    else if (sum >= 1000 && sum < 2000) { discount = 0.05f;     to_disc = 2000 - sum; }
    else if (sum >= 2000 && sum < 3000) { discount = 0.10f;     to_disc = 3000 - sum; }
    else if (sum >= 3000 && sum < 4000) { discount = 0.15f;     to_disc = 4000 - sum; }
    else if (sum >= 4000 && sum < 5000) { discount = 0.20f;     to_disc = 5000 - sum; }
    else if (sum >= 5000 && sum < 6000) { discount = 0.25f;     to_disc = 6000 - sum; }
    else if (sum >= 6000 && sum < 7000) { discount = 0.30f;     to_disc = 7000 - sum; }
    //*/

    if(sum > 7000)      { discount = 0.30f;     to_disc = -1; }
    else if(sum > 6000) { discount = 0.25f;     to_disc = 6000 - sum; }
    else if(sum > 5000) { discount = 0.20f;     to_disc = 5000 - sum; }
    else if(sum > 4000) { discount = 0.15f;     to_disc = 4000 - sum; }
    else if(sum > 3000) { discount = 0.20f;     to_disc = 5000 - sum; }
    else if(sum > 2000) { discount = 0.10f;     to_disc = 3000 - sum; }
    else if(sum > 1000) { discount = 0.05f;     to_disc = 2000 - sum; }
    else                { discount = 0.00f;     to_disc = 1000 - sum; }

    if (to_disc == -1)
    {
        std::cout << "discount " << discount * 100.0f << "% max discount obtained, to pay: " << sum * (1.0f - discount) << std::endl;
    }
    else
    {
        std::cout << "discount " << discount * 100.0f << "% to next discount " << to_disc << ", to pay: " << sum * (1.0f - discount) << std::endl;
    }
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
            os <<"\nПеперрони:\t\t$4.49\n"
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

/*
вывод всего чека
<-Пиццерия->
Меню:
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

Введите номер пиццы: 1
Введите количество продукта: 4
Введите номер пиццы: 2
Введите количество продукта: 8
Введите номер пиццы: 3
Введите количество продукта: 12
Введите номер пиццы: 4
Введите количество продукта: 3
Введите номер пиццы: 0
Введите количество продукта: 0
Введите номер напитка: 1
Введите количество продукта: 10
Введите номер напитка: 2
Введите количество продукта: 15
Введите номер напитка: 3
Введите количество продукта: 10
Введите номер напитка: 0
Введите количество продукта: 0

Пеперрони:              $4.49
                        x4
                        $17.96
free pizza              x0

Гавайская:              $3.45
                        x8
                        $11.06
free pizza              x2

Четыре сыра:            $2.86
                        x12
                        $5.34
free pizza              x2

Маргарита:              $4.45
                        x3
                        $9.79
free pizza              x-1         -> проблемное место в расчете (стр. 450)

Сумма пицц:             $23.14

Кола:                   $0.99
                        x10
                        $9.9

Сок:                    $2.35
                        x15
                        $35.25

Чай:                    $0.4
                        x10
                        $4
Скидка на напитки 15%
Сумма напитков:         $41.7775    -> проблемма форматирования
Скидка на весь чек 20%
ИТОГ:                   51.934      -> аналогично


Резюмируя данную программу стоит разделить на фуркции каждая из которых занимается свой деятельностью (вычисление каждй 5, скидки и тд.)
так же стоит добавить структуры и массивы,
структуры на подобии

struct pizza
{
    int id;
    pizza_type name;
    float price;
}

и массив для хранения позиций (или же map). Пользователь вводит i позицию n количество, 
после он может ввести туже позицю с другим количеством продукта, в чеке это отразится как разные позиции.

p.s.
проблема в расчете

input       total        add     free obtained
12      ->  12      ->   2   ->  2               //Первый ввод данных
8       ->  20      ->   2   ->  6               //Второй ввод               free obtained внезапно дает осечку вместо 4 высчитывает 6
5       ->  25      ->  -1   ->  11              //Третий ввод

p.p.s
Решено ошибка была в 5 строке относительно кейса с пиццами, 
старый вариант free_obtained += pizza_count / 5;
новый вариант free_obtained = pizza_count / 5;

так же испрален ввод, при вводе 0 для окончания выбора не нужно вводить количество продукта.

--------------------------------------------------------------------------------------------
Финальный вывод
<-Пиццерия->
Меню:
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

Введите номер пиццы: 1
Введите количество продукта: 2
Введите номер пиццы: 2
Введите количество продукта: 1
Введите номер пиццы: 3
Введите количество продукта: 2
Введите номер пиццы: 4
Введите количество продукта: 1
Введите номер пиццы: 0
Введите номер напитка: 1
Введите количество продукта: 2
Введите номер напитка: 2
Введите количество продукта: 3
Введите номер напитка: 0

Пеперрони:              $4.49
                        x2
                        $8.98
free pizza              x0

Гавайская:              $3.45
                        x1
                        $3.45
free pizza              x0

Четыре сыра:            $2.86
                        x2
                        $2.86
free pizza              x1

Маргарита:              $4.45
                        x1
                        $4.45
free pizza              x0

Сумма пицц:             $19.74

Кола:                   $0.99
                        x2
                        $1.98

Сок:                    $2.35
                        x3
                        $7.05
Скидка на напитки 15%
Сумма напитков:         $7.6755
ИТОГ:                   27.4155
*/


struct manager
{
    int id;
    float sells;
    float add_payment = 0.0f;
    float payment = 200.0f;
};

void add_payment_calc(manager& m)
{
    if (m.sells > 1000.0f) m.payment += m.sells * 1.08f;
    else if (m.sells > 500.0f) m.payment += m.sells * 1.05f;
    else m.payment += m.sells * 1.03f;
}

void h_w4_t2()
{
    manager m1;
    m1.id = 1;
    manager m2;
    m2.id = 2;
    manager m3;
    m3.id = 3;

    float max = 0.0f;
    manager* prem = nullptr;

    std::cout << "<-Премиальные для менеджера->" << std::endl;
    std::cout <<
        R"(Зарплата == 200$ + % с продаж
%:
при продаже до 500 = 3%
при продаже от 500 до 1000 = 5%
при продаже от 1000 = 8%

)";

    std::cout << "Введите продажи для " << m1.id << " менеджера: 1553.53\n"; m1.sells = 1553.53f; //немного автоматизации ввода
    //system("pause");  //иллюзия ввода
    std::cout << "Введите продажи для " << m2.id << " менеджера: 936.78\n"; m2.sells = 936.78f;
    //system("pause");
    std::cout << "Введите продажи для " << m3.id << " менеджера: 425.25\n"; m3.sells = 425.25f;
    //system("pause");
    add_payment_calc(m1);
    add_payment_calc(m2);
    add_payment_calc(m3);

    std::cout << std::endl <<
        "Оплата + % с продаж первого менеджера = " << m1.payment << std::endl;
    std::cout << std::endl <<
        "Оплата + % с продаж второго менеджера = " << m2.payment << std::endl;
    std::cout << std::endl <<
        "Оплата + % с продаж третьего менеджера = " << m3.payment << std::endl;

    manager arr[3] = { m1, m2, m3 };

    for (manager& m : arr)
    {
        if (max < m.payment)
        {
            max = m.payment;
            prem = &m;
        }           
    }

    prem->payment += 200.0f;

    std::cout << "Пермия выдается менеджеру с id " << prem->id << " в размере 200$" << std::endl;
    std::cout << "Итого зарплата лучшего состовляет" << prem->payment << "$" << std::endl;
}