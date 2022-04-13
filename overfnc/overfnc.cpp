// OverLoadFunctions
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//���������� ������� �� ���� ������ ����������:
int Find_Max_Element(int Array[], int Size) //��� ������� ���� ������ int
{
    int Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "��� ���� ������ int: " << endl;
    return Max_Element;
}
//���� ������ ������������ �������� ����� ��������� � ������������ ��������
double Find_Max_Element(double Array[], int Size) //��� ������� ���� ������ double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "��� ���� ������ double: " << endl;
    return Max_Element;
}
char Find_Max_Element(char Array[], int Size) //��� ������� ���� ������ char
{
    char Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "��� ���� ������ char: " << endl;
    return Max_Element;
}
//��� ������� ���������� �� double Find_Max_Element(double Array[], int Size) ������ �������� ����������  � �������� ��������������� �����������
double Find_Max_Element(int Size, double Array[]) //��� ������� ���� ������ double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "��� ���� ������ double: " << endl;
    return Max_Element;
}

//��������� ������� �� ���-�� ����������
double Multy(double X = 3.0) //1 �������� //Multy(3.0); Multy();
{
    return X * X;
}
double Multy(double X, double Y) //2 ���������
{
    return X * Y;
}
double Multy(double X, double Y, double Z) //3 ���������
{
    return (X * Y * Z);
}
double Multy(double X, double Y, double Z, double W) //4 ���������
//double Multy(double X, double Y, double Z, double W=3.14) //���������� ������� � 4�� �����������
//���� �� ������� ����� �������� �� ���������. ����� �������� ����� �� �����������, ��� ��� ����������
//�� ����� ����� ����� �� ������� ��� �������
{
    return X * Y * Z * W;
}

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    const int Size = 10;
    int A[Size]{};
    double B[Size]{};
    char C[Size]{};  //-128...127   //0...255
    for (int i = 0; i < Size; i++)
    {
        A[i] = rand() % 100;
        B[i] = (rand() % 100) * 1.1;
        C[i] = rand() % 256;
        cout << A[i] << "\t" << B[i] << "\t" << C[i] << endl;
    }
    cout << Find_Max_Element(A, Size) << endl;
    cout << Find_Max_Element(B, Size) << endl;
    cout << Find_Max_Element(C, Size) << endl;
    cout << Find_Max_Element(Size, B) << endl;
    //cout << Find_Max_Element(Size, A) << endl;

    system("cls");
    cout << Multy() << endl;
    cout << Multy(3.14) << endl;
    cout << Multy(3.14, 2.5) << endl;
    cout << Multy(3.14, 2.5, 0.4) << endl;
    cout << Multy(3.14, 2.5, 0.4, 0.2) << endl;
}
