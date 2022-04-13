// Inline.

#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

inline float HYP(float a = 0.0f, float b = 0.0f) //inline = просьба компилятор встроить функцию
{
    return sqrtf(powf(a, 2) + powf(b, 2));//вероятно не будет встраиваемой 
    return sqrtf(a * a + b * b);
}

int main()
{
    setlocale(LC_ALL, "rus");
    float A = 3.0, B = 4.0;
    cout << "Гипотенуза равна: " << HYP(A, B) << endl;
    // cout << "Гипотенуза равна: " << sqrtf(powf(a, 2) + powf(b, 2))<< endl;
    cout << "Гипотенуза равна: " << sqrtf(3.0 * 3.0 + 4.0 * 4.0) << endl;

}