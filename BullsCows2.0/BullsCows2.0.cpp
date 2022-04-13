// BullsAndCows
/*
Добавить в игру Быки и Коровы возможность
повторной игры(поместить код в цикл),
а так же подсчет ходов, за которые игрок угадал
число.
Под* добавить ограничение кол-ва ходов
и любой функционал по своему усмотрению
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
const int Size = 3;
int Number[Size];
int Value[Size];
void SetNumber();
void Slice(int);
int Result();

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    cout << "---Игра Быки и Коровы!---" << endl;
    int Win = 0, Digit = 0, Attempts = 10, count = 0;
    bool play = true;
    bool game = true;

    while (play)
    {
        SetNumber();
        for (int i = 0; i < Size; i++)
        {
            cout << Number[i];
        }
        cout << endl;

        while (game)
        {
            do
            {
                cout << "Введите " << Size << "-значное число, состоящее из разных цифр: ";
                cin >> Digit;
                if (Digit < pow(10, Size - 1) || Digit >= pow(10, Size))
                    cout << "Некорректный ввод! Проверьте кол-во знаков!" << endl;
            } while (Digit < pow(10, Size - 1) || Digit >= pow(10, Size));


            Slice(Digit);
            Win = Result();

            if (Win == Size)
            {
                game = false;
                cout << "Вы угадали! Загаданное число: " << Digit << " за "<< count <<" попыток\n" <<
                    "Хотите повторить? 0/1: ";
                cin >> Digit;
                cout << endl;
                if (Digit == 0)
                {
                    play == false;
                }

            }
            if (Attempts == 0)
            {
                game = false;
                cout << "Вы проиграли!\n" <<
                "Хотите повторить? 0/1: ";
                cin >> Digit;
                cout << endl;

                if (Digit == 0)
                {
                    play == false;
                }
            }

            Attempts--;
            count++;
        };



        play = false;
        system("pause");
    }
}

void SetNumber()
{
    Number[0] = rand() % 9 + 1;
    for (int i = 1; i < Size; i++)
    {
        Number[i] = rand() % 10;
        for (int j = 0; j < i; j++)
        {
            if (Number[i] == Number[j])
            {
                i--;
                break;
            }
        }
    }
}
void Slice(int Digit)
{
    for (int i = Size - 1; i >= 0; i--)
    {
        Value[i] = Digit % 10;
        Digit /= 10;
    }
}
int Result()
{
    int Bulls = 0, Cows = 0;
    for (int i = 0; i < Size; i++)
    {
        if (Number[i] == Value[i])
        {
            Bulls++;
            continue;
        }
        for (int j = 0; j < Size; j++)
        {
            if (Number[i] == Value[j])
            {
                Cows++;
                break;
            }
        }
    }
    cout << "Быки: " << Bulls << " Коровы: " << Cows << endl;
    return Bulls;
}
