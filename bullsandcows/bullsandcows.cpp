// BullsAndCows
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
//?????????? ????????? - ?????? ???????
const int Size = 3;
//?????????? ??????, ???????? ?????????? ?????
int Number[Size];
//?????????? ??????, ???????? ???????? ??????? ????? 
int Value[Size];
//???????? ??????? ???????????(?????????) ?????
void SetNumber();
//???????? ??????? ??????????????(???????) ????? ?????????? ??????? ? ?????? ????
void Slice(int);
//???????? ??????? ????????? ? ??????????? ??????????(?????????? ???-?? ?????)
int Result();

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    cout << "---???? ???? ? ??????!---" << endl;
    int Win = 0, Digit = 0;
    SetNumber();
    //???????? ????? ????? ????????? ?????
    for (int i = 0; i < Size; i++)
    {
        cout << Number[i];
    }
    cout << endl;
    do //???? ???? ?? ??????
    {
        do  //???? ????? ?????
        {
            cout << "??????? " << Size << "-??????? ?????, ????????? ?? ?????? ????: ";
            cin >> Digit;
            if (Digit < pow(10, Size - 1) || Digit >= pow(10, Size))
                cout << "???????????? ????! ????????? ???-?? ??????!" << endl;
        } while (Digit < pow(10, Size - 1) || Digit >= pow(10, Size)); //???? ????? ????? ?????? 1000 ? ?????? ????? 10000 
        Slice(Digit); //???????? ?????
        Win = Result(); //??????? ???-?? ????? ? ????? ? ???????? ???-?? ????? ? ?????????? Win
    } while (Win != Size);//?????? ???? ???-?? ????? ?? ????? ???-?? ???? ? ?????????? ?????
    cout << "?? ???????! ?????????? ?????: " << Digit << endl;
    system("pause");
}
//?????????? ??????? ???????????(?????????) ?????
void SetNumber()
{
    //????????? ?????? ????? ? ?????
    Number[0] = rand() % 9 + 1; //?? 1 ?? 9 ????????????
    for (int i = 1; i < Size; i++) //???? ????????? ?????????? ???? ? ?????
    {
        Number[i] = rand() % 10; //?? 0 ?? 9 ????????????
        for (int j = 0; j < i; j++) //???? ???????? ?????????? ????? ????? ? ???????????
        {
            if (Number[i] == Number[j])//???? ????? ????? ??????? ? ????? ?? ??????????
            //?????? ??????????? ?????? ?? 
            {
                i--; //???????? ??? ????? ??????? i
                break; //??????? ?? ????? ???????? ??????????
            }
        }
    }
}
//?????????? ??????? ??????????????(???????) ????? ?????????? ??????? ? ?????? ????
void Slice(int Digit)
{
    //???? ??????????? ????? ?? ?????
    for (int i = Size - 1; i >= 0; i--)
    {
        Value[i] = Digit % 10; //?????????? ????? ? ??????
        Digit /= 10; //"????????" ?????????? ????? ?? ?????
    }
}
//?????????? ??????? ????????? ? ??????????? ??????????(?????????? ???-?? ?????)
int Result()
{
    int Bulls = 0, Cows = 0; //???? ? ??????
    //????????? ??????? ???? ?? ??????????? ????? ? ????? ??????
    for (int i = 0; i < Size; i++) //???? ??????? ?? ??????????? ?????
    {
        if (Number[i] == Value[i]) //???? ??????? ????? ?? ????? ????? ? ????? ??????(???)
        {
            Bulls++; //??????????? ???-?? ?????
            continue; //????????? ? ????????? ?????
        }
        for (int j = 0; j < Size; j++) //???? ?????? ????? ?? ??????????? ????? ? ?????, ????????? ???????(??????)
        {
            if (Number[i] == Value[j]) //???? ??????? ?????? ?? ??????????? ????? ???? ? ?????, ????????? ???????
            {
                Cows++; //??????????? ???-?? ?????
                break; //????????? ? ????????? ????? ??????????? ?????
            }
        }
    }
    cout << "????: " << Bulls << " ??????: " << Cows << endl;
    return Bulls;
}
