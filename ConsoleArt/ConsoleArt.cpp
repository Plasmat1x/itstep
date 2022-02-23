#include <iostream>
#include <stdlib.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "<-- Art -->" << std::endl;

    int N = 0;
    bool var = false; //переменная для варианта вывод

    std::cout << "Enter size > ";
    std::cin >> N;

    if (var) // с смещением
    {
        for (int i = 0; i < N; i++) // line
        {
            for (int j = 0; j < N; j++) // column
            {
                // i == j
                // i+j == N-1
                // i = N / 2
                // j = N / 2

                if (N % 2)
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (j == N / 2))
                    {
                        std::cout << "* ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }

                }
                else
                {
                    if ((i == j) ||
                        (i + j == N - 2) ||
                        (i == N / 2 - 1) ||
                        (j == N / 2 - 1))
                    {
                        std::cout << "* ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }

            }
            std::cout << std::endl;
        }
    }
    else // с добавлением
    {
        for (int i = 0; i < N; i++) // line
        {
            for (int j = 0; j < N; j++) // column
            {
                // i == j
                // i+j == N-1
                // i = N / 2
                // j = N / 2

                if (N % 2)
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (j == N / 2))
                    {
                        std::cout << "* ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }

                }
                else
                {
                    if ((i == j) ||
                        (i + j == N - 1) ||
                        (i == N / 2) ||
                        (i == N / 2 - 1) ||
                        (j == N / 2) ||
                        (j == N / 2 - 1))
                    {
                        std::cout << "* ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }

            }
            std::cout << std::endl;
        }
    }

    return 0;
}