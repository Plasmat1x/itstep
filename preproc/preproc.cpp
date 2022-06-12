// Preprocessor
#include <iostream>
#include <locale.h>
#include "Header.h"

#ifndef Variant
#error "Variant �� ��������! ��������� ����������� ����� Header.h!"
#endif


#ifndef PI //���� ����� �� ���� �� ���� #define PI
#define PI 3.14159  //����������� - ���������� ��������
#endif

#define Mult(a,b)  ((a)*(b)) //����������� � �����������(������)

#define STR(s)  #s //������ �������� ���������� s � ������
// \��������� ������ �� ��������� �����
#define HELLO "������,"\
                    " ���!"

#ifdef Size         //���� ����� �� ���� ��� #define Size
#undef Size         //��������� ������� #define Size
#define Size 10    //����������� �������, ������� ����� ������������ ��� ������� ������� ������������ �������
#else       //�����, ���� �� ���� ���������� #define Size
#define Size 10    //����������� �������, ������� ����� ������������ ��� ������� ������� ������������ �������
#endif

#ifdef var //���� ���� �� ���� ��� #define
const int Var = var;  //������� ���������� ��������� �� ��������� var
#else
const int Var = 0;  //����� ��������� ������� ���������� ����������
#endif

using namespace std;



#if Variant==1
int main()
{
    //1 ������� ���������
    setlocale(LC_ALL, "rus");
    cout << PI << endl;  //cout << 3.14159 << endl; 
    int A = 10;
    cout << Mult(-3, 2) << endl;
    //cout << Mult(A* -3, 2.0+PI) << endl;
    cout << STR(������ ���!) << endl;
    cout << HELLO << endl;

    int Array[Size]{};
#undef Size  //�������� ����������� Size
    const int Size = 15;
    float B[Size]{};

    if (Var != 0)cout << "�������� Var: " << Var << endl;
    else
    {
        cout << STR(Define var �� �����������!����� ������������ �������� 0) << endl;
        //Var = 5;
    }
}
#elif Variant==2    //#else#if
int main()
{
    //2 ������� ���������
    setlocale(LC_ALL, "rus");
    if (Var != 0)cout << "�������� Var: " << Var << endl;
    else
    {
        cout << STR(Define var �� �����������!����� ������������ �������� 0) << endl;
    }
}
#elif Variant ==3
int main()
{
    //3 ������� ���������
    setlocale(LC_ALL, "rus");
    cout << "������� � 3!" << endl;
}
#else
int main()
{
    //����� ������� ���������
    setlocale(LC_ALL, "rus");
    cout << "������ �� ������!" << endl;
}
#endif