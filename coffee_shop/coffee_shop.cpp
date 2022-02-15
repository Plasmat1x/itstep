#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#include "Cart.h"
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

    Резюмируя сделанное:
    Не хватает интерфейса с корзиной для каждого клиента для отслеживания что было выбрано и сколько. Сложность данного действия заключается в создания массива для клиента с его личной корзиной покупок, а потом данные каждого клиента переносить в итоговую корзину.
    Класс был явно лишним (в данной урезанной реализации), подумывал об реализации перегрузки методов добавления/удаления позиций меню по названию позиции (В данной реализации по ID товара).
    Возможно излишние действие с массивом(вектором) меню, а потом копирования позиций в отдельный массив. Есть свое преймущество, при добавлении новых позиций "не нужно лезть в корзину".
    Еще стоило бы добавить отображение текущего клиента в обработке в меню например.
    
*/

static Cart cart;

std::vector<Cart_position> menu_positions = {
    {1, "name1", 0.01f, 0},
    {2, "name2", 0.02f, 0},
    {3, "name3", 0.03f, 0},
    {4, "name4", 0.04f, 0},
    {5, "name5", 0.05f, 0}
};

void client_menu();
void menu();

int main()
{
    system("cls");

    for (int i = 0; i < menu_positions.size(); i++)
    {
        cart.cart.push_back(menu_positions[i]);
    }

    std::cout << "<--Coffee shop-->" << std::endl;

    int client_count;
    std::cout << "Enter number of persons > ";
    std::cin >> client_count;

    //clients process loop
    for (int i = 0; i < client_count; i++)
    {
        client_menu(); // client process loop
    }

    std::cout << std::endl << std::endl;
    float total = 0;
    for (auto& pos : cart.cart)
    {
        if (pos.count > 0)
        {
            std::cout << pos.name << std::setw(24) << std::setfill('.') << pos.count << " x $" << pos.price << std::setfill(' ') << std::endl;
            std::cout << std::setw(24) << " = $" << pos.count * pos.price << std::endl;
            total += pos.count * pos.price;
        }
    }
    std::cout << "TOTAL " << std::setw(24) << "= $" << total << std::endl;

}

void client_menu()
{
    bool client_proc = true;
    while (client_proc)
    {
        int command, id_sel, count;

        system("cls");
        menu();
        //
        // add cout current client cart
        //
        std::cout << "Command menu:" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - Add position" << std::endl;
        std::cout << "2 - Remove position" << std::endl;
        std::cout << "> ";
        std::cin >> command;

        switch (command)
        {
        case 0: //exit case
            client_proc = false; 
            break;
        case 1: //add case
        {
            std::cout << "Enter number of position > ";
            std::cin >> id_sel;
            std::cout << "Enter count of position > ";
            std::cin >> count;
            cart.add(id_sel, count);
            break;
        }
        case 2: //remove case
        {
            std::cout << "Enter number of position > ";
            std::cin >> id_sel;
            std::cout << "Enter count of position > ";
            std::cin >> count;
            cart.remove(id_sel, count);
            break;
        }
        default:
            std::cout << "ERR::WRONG_COMMAND" << std::endl;
            break;
        }
    }
}

void menu()
{
    std::cout << "Menu: " << std::endl;
    for (int i = 0; i < menu_positions.size(); i++)
    {
        std::cout << menu_positions[i].id << " - " << menu_positions[i].name << " ........ $" << menu_positions[i].price << std::endl;
    }

    std::cout << std::setw(40) << std::setfill('_') << "_" << std::setfill(' ') << std::endl;
}