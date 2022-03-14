#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char sym;
    std::cout << "Введит символ: ";
    std::cin >> sym;

    std::cout << sym << std::endl;
    std::cout << (int)sym << std::endl;

    return 0;
}