// Inline.

#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

inline float HYP(float a = 0.0f, float b = 0.0f) //inline = ������� ���������� �������� �������
{
    return sqrtf(powf(a, 2) + powf(b, 2));//�������� �� ����� ������������ 
    return sqrtf(a * a + b * b);
}

int main()
{
    setlocale(LC_ALL, "rus");
    float A = 3.0, B = 4.0;
    cout << "���������� �����: " << HYP(A, B) << endl;
    // cout << "���������� �����: " << sqrtf(powf(a, 2) + powf(b, 2))<< endl;
    cout << "���������� �����: " << sqrtf(3.0 * 3.0 + 4.0 * 4.0) << endl;

}