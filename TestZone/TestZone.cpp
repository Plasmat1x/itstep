#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "t1.h"

//using namespace std;

namespace myMath
{
    int i = 1;
    unsigned long int result;

    unsigned long int factorial(unsigned long int x)
    {
        if (x == 1 || x == 0)
            return 1;

        i++;
        result = x * factorial(x - 1);

        return result;
    }
}

void t0()
{
    /*
    //полезная вещица
    std::string something, something2;

    cout << "                 Please Login With Admin Credentials!" << endl;
    cout << "                  ===================================" << endl;
    cout << "                  +   [=] Enter Username:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something;

    cout << "                  +   [=] Enter Password:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something2;

    cout << "                  ===================================" << endl;
    */
    myMath::factorial(6);

    std::cout << myMath::result << std::endl;




}

using namespace std;
int main()
{
    int a = 10;
    if (a = 5)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}