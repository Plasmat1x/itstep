// def.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <math.h>
#include <iostream>
#include <stdlib.h>

#define HELLO "Hello, World!"
#define SQR(X) ((X)*(X))
#define CUBE(X) (SQR(X)*(X))
#define ABS(X) (((X)<0)?-(X):(X))

inline float HYP(float, float);

int main()
{
    system("chcp 1251");
    system("cls");

    /*
    std::cout << HELLO << std::endl;
    std::cout << HELLO << std::endl;
    std::cout << HELLO << std::endl;
    std::cout << HELLO << std::endl;
    std::cout << HELLO << std::endl;

    std::cout << HYP(3,4) << std::endl;
    */

    int A = 3;
    int B = 4;

    //std::cout << (A + B) * (A + B) << std::endl;
    //std::cout << pow(A+B, 2) << std::endl;
    std::cout << SQR(A+B) << std::endl;

    //((a+b)^2 * (a-b)^2)^2
    //std::cout << pow((pow(A + B, 2) * pow(A - B, 2)),2) << std::endl;
    std::cout << SQR(SQR(A + B) * SQR(A - B));

    //|(A-(A*B)^2)^3|
    std::cout << ABS(CUBE(A - SQR(A + B))) << std::endl;

    return 0;
}

inline float HYP(float a = .0f, float b = .0f)
{
    return sqrtf(SQR(a) + SQR(b));
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
