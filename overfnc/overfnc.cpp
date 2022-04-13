// OverLoadFunctions
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//перегрузка функции по типу данных аргументов:
int Find_Max_Element(int Array[], int Size) //для массива типа даннхы int
{
    int Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных int: " << endl;
    return Max_Element;
}
//типы данных возращаемого значения могут совпадать в пергруженных функциях
double Find_Max_Element(double Array[], int Size) //для массива типа даннхы double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных double: " << endl;
    return Max_Element;
}
char Find_Max_Element(char Array[], int Size) //для массива типа даннхы char
{
    char Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных char: " << endl;
    return Max_Element;
}
//эта функция отличается от double Find_Max_Element(double Array[], int Size) только порядком аргументов  и является самостоятельной перегрузкой
double Find_Max_Element(int Size, double Array[]) //для массива типа даннхы double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i] > Max_Element) Max_Element = Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных double: " << endl;
    return Max_Element;
}

//пергрузка функций по кол-ву аргументов
double Multy(double X = 3.0) //1 аргумент //Multy(3.0); Multy();
{
    return X * X;
}
double Multy(double X, double Y) //2 аргумента
{
    return X * Y;
}
double Multy(double X, double Y, double Z) //3 аргумента
{
    return (X * Y * Z);
}
double Multy(double X, double Y, double Z, double W) //4 аргумента
//double Multy(double X, double Y, double Z, double W=3.14) //перегрузка функции с 4мя аргументами
//один из которых имеет значение по умолчанию. Такая ситуация будет не однозначной, так как компилятор
//Не будет знать какую из функций ему вызвать
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
