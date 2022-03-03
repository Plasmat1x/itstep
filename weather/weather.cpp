#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    std::cout << "<--Weather-->" << std::endl;
    const int Size = 31;
    int August[Size]{};
    int Count = 0;
    int Weather = 0;

    for (int i = 0; i < Size; i++)
    {
        August[i] = rand() % 25 - 5;
        std::cout << "Weather " << i + 1 << " day " << August[i] << " C " << std::endl;
        Count += August[i];
    }
    std::cout << "\nAverger temp mouth: " << (float)Count / Size << " C " << std::endl;
    system("pause");
    system("cls");
    std::cout << "Enter temp "; std::cin >> Weather;
    for (int i = 0; i < Size; i++)
    {
        if (Weather > August[i])
            std::cout << "August " << i + 1 << " day " << August[i] << " C " << std::endl;
    }

}