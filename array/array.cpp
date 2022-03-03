#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{
    const int size = 10;
    int arr[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 256;
        if (arr[i] % 2 == 0)
        {
            std::cout << std::hex << arr[i] << "\t";
        }   
    }
    std::cout << std::dec << std::endl;

    return 0;
}