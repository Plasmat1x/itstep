// union.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

struct vec
{
    int x;
    int y;
};

union Geometrix
{
    int rad;
    int ab[2];
    int abc[3];
};

union ASCII
{
    unsigned int num;
    char sym;
};

int main()
{
    vec test{100, 100};

    vec* ptr = &test;

    std::cout << sizeof(test) << std::endl;
    std::cout << sizeof(vec) << std::endl;
    std::cout <<"* " << sizeof(ptr) << std::endl;

    Geometrix tri;
    tri.ab[0] = 40;
    tri.ab[1] = 10;

    tri.rad = 9;

    tri.abc[0] = 10;
    tri.abc[1] = 2;
    tri.abc[2] = 5;

    std::cout << sizeof(tri) << std::endl;
    std::cout << sizeof(Geometrix) << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
