#include <iostream>
#include <cstdlib>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "������, ���!" << std::endl;

    char sym;
    std::cout << "������� ������: ";
    std::cin >> sym;

    std::cout << "������: " << sym << std::endl;

    return 0;
}
