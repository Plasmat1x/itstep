// Algorithm1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double fact(int N)
{
    if (N <= 1)
    {
        return 1;
    }

    double resault = N * fact(N - 1);

    return resault;
}

int NOD(int a, int b)
{
    int min = 0;
    int nod = 0;

    if (a == b) return a;
    
    min = (a > b ? b : a);
    for (int i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0) nod = i;
    }
    if (nod == 1)
        return 0;

    return nod;
}

int rNOD(int a, int b)
{
    if (a == b) return a;
    else if (a>b) return rNOD(a-b, b);
    else if (a<b) return rNOD(b-a, a);
}

int iNOD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int main()
{
    std::cout << fact(6) << std::endl;

    std::cout << NOD(96, 16) << std::endl;
    std::cout << rNOD(96, 16) << std::endl;
    std::cout << iNOD(96, 16) << std::endl;

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
