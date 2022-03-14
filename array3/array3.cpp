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
      * * *         *             * * *                       * * *
a() -   * *   b() - * *     c() -   *     d() -   *     e() -   *
          *         * * *                       * * *         * * *

      *   *         *                 *         * * *             *
f() - * * *   g() - * *     h() -   * *   i() - * *     j() -   * *
      *   *         *                 *         *             * * *

0 - Выход
)";
        cin >> dark_side;
        //работа с матрицей в зависимости от вариантов
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                switch (dark_side)
                {
                case 'A':
                case 'a':
                {
                    if (i <= j) //условие варианта а
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'B':
                case 'b':
                {
                    if (i >= j) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'C':
                case 'c':
                {
                    if (i <= j && i +j <= N-1) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'D':
                case 'd':
                {
                    if (i >= j && i + j >= N - 1) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'E':
                case 'e':
                {
                    if ((i >= j && i + j >= N - 1) || (i <= j && i + j <= N - 1)) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'F':
                case 'f':
                {
                    if ((i <= j && i + j >= N - 1) || (i >= j && i + j <= N - 1)) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'G':
                case 'g':
                {
                    if ((i >= j && i + j <= N - 1)) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'H':
                case 'h':
                {
                    if ((i <= j && i + j >= N - 1)) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'I':
                case 'i':
                {
                    if (i + j <= N - 1) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                case 'J':
                case 'j':
                {
                    if (i + j >= N - 1) //условие варианта б
                    {
                        //сравниваем текущий элемент с максимальным
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //сравниваем текущий элемент с минимальным
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //вывод нужного элемента на экран
                        if (Matrix[i][j] > 0)cout << " "; //добавим пробел перед числом, если оно положительное
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                }
                default:
                    cout << "Неправильно выбран вариант! Проверьте раскладку клавиатуры!" << endl;
                    dark_side = 'N'; //'N' - некорректный вариант
                    break;
                case '0':
                    cout << "До новых встреч!" << endl;
                    break;
                }
                if (dark_side == '0' || dark_side == 'N')break; //выход из цикла по счетчику j(внутреннего)
            }
            if (dark_side == '0' || dark_side == 'N')break; //выход из цикла по счетчику i(внешнего)
            cout << endl;
        }
        if (dark_side == '0')break;  //выход из цикла do{}while() из всей программы
        else
            if (dark_side != 'N') //если был выбран правильный вариант
            {
                cout << "Максимальный элемент варианта " << dark_side << " равен:  " << Max << endl;
                cout << "Минимальный  элемент варианта " << dark_side << " равен: " << Min << endl;
                //возвращаем переменные в исходное состояние для повторной работы с матрицей
                Max = -100;
                Min = 100;
            }
        system("pause");
    } while (dark_side != '0');
}
