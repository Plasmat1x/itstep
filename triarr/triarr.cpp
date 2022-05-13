/*
Реализовать работу с "треугольным" динамическим массивом(Урок 15, стр. 10) 
Пользователь задет размер максимальной строки, способ создания(в 0-й строке заданное кол-во элементов, 
в последней 1 элемент или наоборот) и способ вывода на экран (прямоугольный треугольник или равносторонний). 
Вывести массив на экран и найти в нем элемент с максимальным значением
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int size = 0;
    int** arr = nullptr;
    bool drawVar = true;
    std::cout << "--triangle array--" << std::endl;
    std::cout << "enter arr max size: ";
    std::cin >> size;

    //init array
    int dsize = size;
    arr = new int* [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[dsize--];
    }

    //fill array
    dsize = size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < dsize; j++)
        {
            arr[i][j] = rand() % 90 + 10;
        }
        dsize--;
    }

    //work with array
    int max = 0, imax = 0, jmax = 0;
    dsize = size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < dsize; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
                imax = i;
                jmax = j;
            }        
        }
        dsize--;
    }

    //draw array
    std::cout << "enter variation drawing 1 'r' or 0 'v': ";
    std::cin >> drawVar;
    if (drawVar)
    {
        //draw array as 'r' angle
        dsize = size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < dsize; j++)
            {
                std::cout << arr[i][j] << "  ";
            }
            std::cout << "\n";
            dsize--;
        }
        std::cout << std::endl;
    }
    else
    {
        //draw array as 'v' angle
        dsize = size;
        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k <= i; k++) // add space evry string render
            {
                    std::cout << "  ";
            }
            for (int j = 0; j < dsize; j++)
            {
                std::cout << arr[i][j] << "  ";
            }
            std::cout << "\n";
            dsize--;
        } 
        std::cout << std::endl;
    }

    std::cout << "arr[" << imax << "][" << jmax << "] = " << max << " is max value in triangle array" << std::endl;
    
    //free mem
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
