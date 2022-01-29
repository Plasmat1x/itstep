#include <iostream>
#include <cstdlib>

#include "regioncode.h"
#include "loops.h"
#include "enum.h"

int main()
{
    system("chcp 1251");
    system("cls");

    // uncomment
    //enu::enu();
    //reg::regioncode(); 
    
    lps::loops();

    system("Pause");
    system("chcp 866");
    return 0;
}
