#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <utility>
#include <map>

/*
Реализовать программу расчета заказа в кафетерии
при условии, что заказ может быть на несколько человек и
каждый клиент формирует свою часть заказа. Необходимо
спросить у пользователя на сколько человек заказ. Далее
каждому человеку выводиться меню (названия напитков,
кондитерских изделий и их цена) и он выбирает. Предусмот-
реть возможность выбора нескольких элементов меню для
клиента, если он желает добавить еще что-то в свой заказ.
Результат работы программы — итоговая сумма общего
заказа всей компании.

    "Предусмотреть возможность выбора нескольких элементов меню для клиента, если он желает добавить еще что-то в свой заказ." //??? Шта?

    1 ввод количество клиентов
    2 вывод меню нескольким клиентам //??? (в консоли реализация циклом for? на каждой итерации цикла обрабатываем одного клиента)
    3 ввод позиций
    4 расчет итогов
    5 вывод расчетов
*/

struct position
{
    int id;
    std::string name;
    float price;
};

void pos_print(position pos)
{
    std::cout << pos.id << " - " << pos.name << " " << pos.price << std::endl;
}

int main()
{
    system("cls");
    std::cout << "<--Coffee shop-->" << std::endl;

    /* //очередь в топку
    position pos1 = { 1, "Cacke 1", 2.5f };
    position pos2 = { 2, "Cacke 2", 3.5f };
    position pos3 = { 3, "Drink 1", 0.5f };
    position pos4 = { 4, "Drink 2", 1.1f };
    int persons = 0;
    int command = 0;
    std::map<std::pair<int, position>, int> cart;
    //cart.insert(std::make_pair(pos1, 0));
    //cart.insert(std::make_pair(pos2, 0));
    //cart.insert(std::make_pair(pos3, 0));
    //cart.insert(std::make_pair(pos4, 0));
    cart.insert(std::make_pair(std::make_pair(1, pos1), 0));

    std::cout << "Enter number of persons "; 
    std::cin >> persons;

    for (int i = 0; i < persons; i++)
    {
        while (true)
        {
            system("cls");

            std::cout << "Menu: " << std::endl;
            pos_print(pos1);
            pos_print(pos2);
            pos_print(pos3);
            pos_print(pos4);

            std::cout << "enter number of position for add in cart ";
            std::cin >> command;

            [&command, &cart]()->void
            {
                int count = 0;
                std::cout << "Enter number of position ";
                std::cin >> count;

                switch (command)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:break;
                }
                
            };
        }  
    }
    */
    Sleep(1500);
}


