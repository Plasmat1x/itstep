// Matrix
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");
    srand(time(NULL));
    const int N = 11; //размер массива(кол-во строк и столбцов)

    //создаем квадратную матрицу
    int Matrix[N][N]{};
    int Max = -100; //задаем начальное значение заведомо меньше, чем у любого элемента
    int Min = 100;	//задаем начальное значение заведомо больше, чем у любого элемента
    char dark_side = '0'; //хранит выбор набора элементов
    //заполнение матрицы значениями
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            do
            {
                Matrix[i][j] = rand() % (100 - (-99)) - 99;  //от -99 до 99 включительно
            } while (Matrix[i][j] > -10 && Matrix[i][j] < 10);
            //условие повторной генерации при выпадении чисел от -9 до 9 включительно
            //оставляем только двузначные числа
        }
    }
    //цикл работы с матрицей
    do
    {
        system("cls");
        cout << "---Программа для работы с квадратной матрицей!---" << endl;
        //вывод полной матрицы на экран
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
        //вывод меню на экран
        cout << R"(
Выберите вариант матрицы:
    * * *       *           * * *                   * * *
а -   * *   б - * *     в -   *     г -   *     д -   *
        *       * * *                   * * *       * * *

    *   *       *               *       * * *           *
е - * * *   ж - * *     з -   * *   и - * *     к -   * *
    *   *       *               *       *           * * *

0 - Выход
)";


        cin >> dark_side;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                switch (dark_side)
                {
                case 'A':
                case 'a':
                    if (i <= j)
                    {
                        if (Matrix[i][j] > Max) Max = Matrix[i][j];
                        if (Matrix[i][j] < Min) Min = Matrix[i][j];
                        if (Matrix[i][j] > 0) cout << " ";
                        cout << Matrix[i][j] << " ";
                    }
                    else
                    {
                        cout << "    ";
                    }
                    break;
                }
            }
            cout << endl;
        }
        system("pause");
    } while (dark_side != '0');
}


