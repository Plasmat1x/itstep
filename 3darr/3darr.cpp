#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{

    srand(time(NULL));

    //int size = 9;
    int sizep = 3; //pages
    int sizer = 4; //rows
    int sizec = 5; //columns

    //init 3d arr
    int*** arr = new int**[sizep];
    for (int i = 0; i < sizep; i++)
    {
        arr[i] = new int*[sizer];
        for (int j = 0; j < sizer; j++)
        {
            arr[i][j] = new int[sizec];
        }
    }

    //access 3d arr
    int max = 0;
    int maxi = 0;
    int maxj = 0;
    int maxk = 0;

    for (int i = 0; i < sizep; i++)
    {
        for (int j = 0; j < sizer; j++)
        {
            for (int k = 0; k < sizec; k++)
            {
                arr[i][j][k] = rand() % 90 + 10;
                
                if (max < arr[i][j][k])
                {
                    max = arr[i][j][k];
                    maxi = i;
                    maxj = j;
                    maxk = k;
                }
            }
        }
    }

    //var 1
    //draw 3d arr
    //*
    for (int i = 0; i < sizep; i++)
    {
        std::cout << "arr " << i << "\n";
        for (int j = 0; j < sizer; j++)
        {
            for (int k = 0; k < sizec; k++)
            {
                std::cout << arr[i][j][k] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

    //var 3
    //draw 3d arr
    /*
    for (int k = 0; k < sizec; k++) // k
    {
        std::cout << "arr " << 0 << "\n";
        for (int j = 0; j < sizer; j++) // j
        {
            for (int i = 0; i < sizep; i++) // i
            {
                std::cout << arr[i][j][k] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    //*/

    //var 3
    //draw 3d arr
    /*
    for (int j = 0; j < sizer; j++) // j
    {
        std::cout << "arr " << 0 << "\n";
        for (int i = 0; i < sizep; i++) // i
        {

            for (int k = 0; k < sizec; k++) // k
            {
                std::cout << arr[i][j][k] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    //*/

    //var 3
    //draw 3d arr
    /*
    for (int k = 0; k < sizec; k++) // k
    {
        for (int i = 0; i < sizep; i++) // i
        {
            for (int j = 0; j < sizer; j++) // j
            {
                std::cout << arr[i][j][k] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    //*/

    std::cout << "max in arr " << maxi << " row " << maxj << " col " << maxk << " with value " << max << std::endl;

    //free mem
    for (int i = 0; i < sizep; i++)
    {
        for (int j = 0; j < sizer; j++)
        {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}
