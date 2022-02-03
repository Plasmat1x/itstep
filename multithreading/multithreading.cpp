#include<iostream>
#include<cstdlib>

#include"Core.h"

int main()
{
    system("chcp1251");
    system("cls");

    Core core;

    core.run();

    system("chcp 866");
    return EXIT_SUCCESS;
}