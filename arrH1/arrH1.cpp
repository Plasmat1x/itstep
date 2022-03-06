// Matrix
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    /*
    “Создать матрицу 11 на 11 элементов. Заполнить её двузначными значениями от -99 до 99. Реализовать меню с двумя вариантами: Вариант а: оставить в матрице (вывести на экран) только элементы с четным значением, 
    остальные элементы заменить пробелами Вариант б:  оставить в матрице (вывести на экран) только элементы с нечетным значением, остальные элементы заменить пробелами. 
    После чего найти среди оставшихся элементов минимальный и максимальный и вывести их на экран. Под * мин. и макс. элементы нужно найти в каждой строке и в каждом столбе среди оставшихся элементов”
    */
    system("chcp 65002");
    system("cls");
    srand(time(NULL));
    const int N = 11;
    int Matrix[N][N]{};
    int Max = -100;
    int Min = 100;
    char dark_side = '0';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            do
            {
                Matrix[i][j] = rand() % (100 - (-99)) - 99;
            } while (Matrix[i][j] > -10 && Matrix[i][j] < 10);
            //условие повторной генерации при выпадении чисел от -9 до 9 включительно
            //оставляем только двузначные числа
        }
    }

    do
    {
        system("cls");
        cout << "---Программа для работы с квадратной матрицей!---" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Matrix[i][j] > 0)cout << " ";
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << R"(
Выберите вариант матрицы:
a - Чет
b - Нечет

0 - Выход
)";
        cin >> dark_side;
        cout << endl << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                switch (dark_side)
                {
                case 'A':
                case 'a':
                    if (Matrix[i][j] % 2 == 0) //условие варианта а
                    {
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        if (Matrix[i][j] > 0) cout << " ";
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case 'B':
                case 'b':
                    if (Matrix[i][j] % 2 != 0) //условие варианта б
                    {
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        if (Matrix[i][j] > 0) cout << " ";
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                default:
                    cout << "Неправильно выбран вариант! Проверьте раскладку клавиатуры!" << endl;
                    dark_side = 'N';
                    break;
                case '0':
                    cout << "До новых встреч!" << endl;
                    break;
                }
                if (dark_side == '0' || dark_side == 'N')break;
            }
            if (dark_side == '0' || dark_side == 'N')break;
            cout << endl;
        }


        cout << endl;
        if (dark_side == 'a' || dark_side == 'A')
        {
            int Max_ = -100;
            int Min_ = 100;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (Matrix[i][j] % 2 == 0)
                    {
                        if (Matrix[i][j] > Max_)Max_ = Matrix[i][j];
                        if (Matrix[i][j] < Min_)Min_ = Matrix[i][j];
                    }
                    if (j == N - 1)
                    {
                        std::cout << "i = \t" << i << " \tmin = \t" << (Min_ > 0 ? " " : "") << Min_ << " \tmax = \t" << (Max_ > 0 ? " " : "") << Max_ << endl;
                    }
                }
                Min_ = 100;
                Max_ = -100;
            }

            cout << endl;

            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if (Matrix[i][j] % 2 == 0)
                    {
                        if (Matrix[i][j] > Max_)Max_ = Matrix[i][j];
                        if (Matrix[i][j] < Min_)Min_ = Matrix[i][j];
                    }
                    if (i == N - 1)
                    {
                        std::cout << "j = \t" << j << " \tmin = \t" << (Min_ > 0 ? " " : "") << Min_ << " \tmax = \t" << (Max_ > 0 ? " " : "") << Max_ << endl;
                    }
                }
                Min_ = 100;
                Max_ = -100;
            }
        }
        else if (dark_side == 'b' || dark_side == 'B')
        {
            int Max_ = -100;
            int Min_ = 100;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (Matrix[i][j] % 2 != 0)
                    {
                        if (Matrix[i][j] > Max_)Max_ = Matrix[i][j];
                        if (Matrix[i][j] < Min_)Min_ = Matrix[i][j];
                    }
                    if (j == N - 1)
                    {
                        std::cout << "i = \t" << i << " \tmin = \t" << (Min_ > 0 ? " " : "") << Min_ << " \tmax = \t" << (Max_ > 0 ? " " : "") << Max_ << endl;
                    }
                }
                Min_ = 100;
                Max_ = -100;
            }

            cout << endl;

            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if (Matrix[i][j] % 2 != 0)
                    {
                        if (Matrix[i][j] > Max_)Max_ = Matrix[i][j];
                        if (Matrix[i][j] < Min_)Min_ = Matrix[i][j];
                    }
                    if (i == N - 1)
                    {
                        std::cout << "j = \t" << j << " \tmin = \t" << (Min_ > 0 ? " " : "") << Min_ << " \tmax = \t" << (Max_ > 0 ? " " : "") << Max_ << endl;
                    }
                }
                Min_ = 100;
                Max_ = -100;
            }
        }


        if (dark_side == '0')break;
        else
            if (dark_side != 'N')
            {
                cout << endl << endl;
                cout << "Максимальный элемент варианта " << dark_side << " равен:  " << Max << endl;
                cout << "Минимальный  элемент варианта " << dark_side << " равен: " << Min << endl;
                Max = -100;
                Min = 100;
            }
        system("pause");
    } while (dark_side != '0');
}
