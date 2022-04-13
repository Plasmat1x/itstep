// Equation
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

using namespace std;
//функция решения квадратного уравнения и линейного уравнения, как
//частного случая квадратного уравнения, возвращает кол-во корней
//int Uravnenie(double a, double b, double c) //первый вариант
int Uravnenie(double b, double c, double a = 0.0) //второй вариант с параметром по умолчанию
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    if (a == 0.0) //если уравнение линейное
    {
        //bx+c=0
        x1 = -c / b;
        cout << "x1= " << x1 << endl;
        return 1; //возвращаем кол-во корней
    }
    else //иначе уравнение квадратное
    {
        D = (b * b) - 4 * a * c;
        if (D < 0) //если нет действительных корней
        {
            cout << "Нет действительных корней!" << endl;
            return 0;
        }
        else
            if (D == 0) //два одинаковых корня
            {
                x1 = (-b) / (2 * a);
                //x2=x1;
                cout << "x1=x2= " << x1 << endl;
                return 20;
            }
            else //два разных корня
            {
                x1 = ((-b) - sqrt(D)) / (2 * a);
                x2 = ((-b) + sqrt(D)) / (2 * a);
                cout << "x1= " << x1 << "\nx2= " << x2 << endl;
                return 2;
            }
    }
}
//функция решения линейного уравнения
inline double Equation(double k, double b) //такой вариант функции можно сделать встраиваемой
{
    //kx+b=0
    cout << "x= " << -b / k << endl;
    return -b / k;
}
//перегрузка функции для решения квадратных уравнений
int Equation(double a, double b, double c)
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    D = (b * b) - 4 * a * c;
    if (a == 0)Equation(b, c);
    else
        if (D < 0) //если нет действительных корней
        {
            cout << "Нет действительных корней!" << endl;
            return 0;
        }
        else
            if (D == 0) //два одинаковых корня
            {
                x1 = (-b) / (2 * a);
                //x2=x1;
                cout << "x1=x2= " << x1 << endl;
                return 1; //два одинаковых корня
            }
            else //два разных корня
            {
                x1 = ((-b) - sqrt(D)) / (2 * a);
                x2 = ((-b) + sqrt(D)) / (2 * a);
                cout << "x1= " << x1 << "\nx2= " << x2 << endl;
                return 2; //два разных корня
            }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choise = 0;
    double a = 0.0, b = 0.0, c = 0.0;
    do //цикл повторных вычислений
    {
        cout << R"(---Программа для решения уравнений!---
1 - Линейное уравнение (kx+b=0)
2 - Квадратное уравнение (ax^2+bx+c=0)
0 - Выход из программы
)";
        do //цикл пользовательского ввода
        {
            cout << "Выберите тип уравнения: "; cin >> choise;
            if (choise < 0 || choise>2)cout << "Неверно выбран тип уравнения! Попробуйте ещё раз!" << endl;
        } while (choise < 0 || choise>2);
        if (choise == 0)break; //выход из программы(из цикла повторных вычислений)
        switch (choise)
        {
        case 1:
            //a = 0.0; //обнуляем а, если перед этим решали квадратное уравнение, для первого варианта
            cout << "Введите коэффициент k: "; cin >> b;
            cout << "Введите коэффициент b: "; cin >> c;
            //Uravnenie(a, b, c);//Uravnenie(0.0, b, c); //первый вариант
            //Uravnenie(b, c); //второй вариант с параметром по умолчанию
            Equation(b, c);
            break;
        case 2:
            cout << "Введите коэффициент a: "; cin >> a;
            cout << "Введите коэффициент b: "; cin >> b;
            cout << "Введите коэффициент c: "; cin >> c;
            //Uravnenie(a, b, c); //первый вариант
            //Uravnenie(b, c, a); //второй вариант с параметром по умолчанию
            Equation(a, b, c);
            break;
        }
        system("pause");
        system("cls");
    } while (choise != 0);
    cout << "Выход..." << endl;
    Sleep(1500);
}
