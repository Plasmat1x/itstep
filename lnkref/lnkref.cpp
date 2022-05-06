#include <iostream>

/*
ДЗ. Написать функцию, принимающую адреса трех переменных типа float 
и меняющую значения этих переменных(используя указатели) так, чтобы переменная чей 
адрес был передан первым получила минимальное значение, а переменная, 
чей адрес был передан последним получила максимальное значение
*/

void swap(float* a, float* b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(float* a, float* b, float* c)
{
    while (*a > *b || *b > *c || *c < *a)
    {
        if (*c < *b)
            swap(c, b);
        else
            swap(b, a);
    }
}

int main()
{
    //lab
    std::cout << "--lab--\n";
    int a = 15243;
    int* pa = &a;

    std::cout << (&a + 1) << std::endl;
    std::cout << *(&a + 1) << std::endl;
    std::cout << std::endl;
    std::cout << (&a) << std::endl;
    std::cout << *(&a) << std::endl;
    std::cout << "\n\n" << std::endl;

    //main
    float A = 12.31f, B = 1.12f, C = 5.21f;

    //different combos based on main;
    float A1 = A, B1 = B, C1 = C;
    float A2 = B, B2 = A, C2 = C;
    float A3 = C, B3 = A, C3 = B;

    //test float
    A = 0.31f, B = 0.12f, C = 0.21f;

    std::cout << "--sort func(a = min, b = avg, c = max)--\n";
    std::cout << "input data: ";
    std::cout << "\tA = " << A << "\tB = " << B << "\tC = " << C << "\n";
    sort(&A, &B, &C);
    std::cout << "output data: ";
    std::cout << "\tA = " << A << "\tB = " << B << "\tC = " << C << "\n" << std::endl;

    //tests
    std::cout << "\n\n--test--\n";
    std::cout << "A1 = " << A1 << "\tB1 = " << B1 << "\tC1 = " << C1 << "\n";
    sort(&A1, &B1, &C1);
    std::cout << "A1 = " << A1 << "\tB1 = " << B1 << "\tC1 = " << C1 << "\n\n";

    std::cout << "A2 = " << A2 << "\tB2 = " << B2 << "\tC2 = " << C2 << "\n";
    sort(&A2, &B2, &C2);
    std::cout << "A2 = " << A2 << "\tB2 = " << B2 << "\tC2 = " << C2 << "\n\n";

    std::cout << "A3 = " << A3 << "\tB3 = " << B3 << "\tC3 = " << C3 << "\n";
    sort(&A3, &B3, &C3);
    std::cout << "A3 = " << A3 << "\tB3 = " << B3 << "\tC3 = " << C3 << std::endl;



    return 0;
}

