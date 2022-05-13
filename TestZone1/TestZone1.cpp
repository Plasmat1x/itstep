#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

int main()
{
    system("chcp 1251");

    for (char i = 'à'; i <= 'ÿ'; i++)
    {
        std::cout << i << " " << (int)i << std::endl;
    }
    std::cout << "\n" << std::endl;

    for (char i = 'À'; i <= 'ß'; i++)
    {
        std::cout << i << " = " << (int)i << std::endl;
    }
    std::cout << "\n" << std::endl;
    
    for (int i = 0; i < 256; i++)
    {
        std::cout << i << " = " << (char)i << std::endl;
    }

}