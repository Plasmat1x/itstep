// Preprocessor
#include <iostream>
#include <locale.h>
#include "Header.h"

#ifndef Variant
#error "Variant не объявлен! Проверьте подключение файла Header.h!"
#endif


#ifndef PI //если ранее по коду не было #define PI
#define PI 3.14159  //подстановка - именование литерала
#endif

#define Mult(a,b)  ((a)*(b)) //подстановка с параметрами(макрос)

#define STR(s)  #s //макрос заключит содержимое s в кавычк
// \разделяет макрос на несколько строк
#define HELLO "Привет,"\
                    " Мир!"

#ifdef Size         //если ранее по коду был #define Size
#undef Size         //отключаем прежний #define Size
#define Size 10    //именованный литерал, который можно использовать для задания размера статического массива
#else       //иначе, если не было объявления #define Size
#define Size 10    //именованный литерал, который можно использовать для задания размера статического массива
#endif

#ifdef var //если выше по коду был #define
const int Var = var;  //создаем глобальную константу со значением var
#else
const int Var = 0;  //иначе объявляем нулевую глобальную переменную
#endif

using namespace std;



#if Variant==1
int main()
{
    //1 вариант программы
    setlocale(LC_ALL, "rus");
    cout << PI << endl;  //cout << 3.14159 << endl; 
    int A = 10;
    cout << Mult(-3, 2) << endl;
    //cout << Mult(A* -3, 2.0+PI) << endl;
    cout << STR(Привет Мир!) << endl;
    cout << HELLO << endl;

    int Array[Size]{};
#undef Size  //отменяет подстановку Size
    const int Size = 15;
    float B[Size]{};

    if (Var != 0)cout << "Значение Var: " << Var << endl;
    else
    {
        cout << STR(Define var не сущеуствует!Будет использовано значение 0) << endl;
        //Var = 5;
    }
}
#elif Variant==2    //#else#if
int main()
{
    //2 вариант программы
    setlocale(LC_ALL, "rus");
    if (Var != 0)cout << "Значение Var: " << Var << endl;
    else
    {
        cout << STR(Define var не сущеуствует!Будет использовано значение 0) << endl;
    }
}
#elif Variant ==3
int main()
{
    //3 вариант программы
    setlocale(LC_ALL, "rus");
    cout << "Вариант № 3!" << endl;
}
#else
int main()
{
    //Иначе вариант программы
    setlocale(LC_ALL, "rus");
    cout << "Ничего не делаем!" << endl;
}
#endif