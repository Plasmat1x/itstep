// bitfield.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bit>

/*
struct Date
{
    unsigned short week     : 3;  // 1...7      (3 bits)
    unsigned short day      : 5;  // 1...31     (5 bits)
    unsigned short month    : 4;  // 1...12     (4 bits)
    unsigned short age      : 12; // 0...4096   (12 bits)
};
*/
/*
struct Date
{
    unsigned int week   : 3;  // 1...7      (3 bits)
    unsigned int day    : 5;  // 1...31     (5 bits)
    unsigned int month  : 4;  // 1...12     (4 bits)
    unsigned int age    : 12; // 0...4096   (12 bits)
};
*/

/*
struct Date
{
    unsigned char week   : 3;  // 1...7      (3 bits)
    unsigned char day    : 5;  // 1...31     (5 bits)
    unsigned char month  : 4;  // 1...12     (4 bits)
    unsigned char age    : 7;  // 0...99     (7 bits)
};
*/

struct Date
{
    unsigned int week      : 3;  // 1...7      (3 bits)
    unsigned int day       : 5;  // 1...31     (5 bits)
    unsigned int month     : 4;  // 1...12     (4 bits)
    unsigned int age       : 7;  // 0...99     (7 bits)
    unsigned int hour      : 5;  // 0...32     (5 bits)
    unsigned int minute    : 6;  // 0...64     (6 bits)
};

int main()
{



    Date d;

    d.week = 5;
    d.day = 27;
    d.month = 05;
    d.age = 22;
    d.hour = 21;
    d.minute = 04;

    std::cout << sizeof(Date) << std::endl;
    std::cout << sizeof(d) << std::endl;

    std::wcout << d.hour << ":"<< d.minute << " " << d.day << "." << d.month << "." << d.age << " " << d.week << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/*
// BitsFields
#include <iostream>
#include <locale.h>

using namespace std;

struct Date
{
	//битовые пол€, группировка под размер типа short по 2 байта
	//unsigned short nDayOfWeek : 3;			//1...7  (3bits)
	//unsigned short nDayOfMonth : 5;			//1...31 (5bits)
	//unsigned short nMonth : 4;				//1...12 (4bits)
	//unsigned short nYear : 12;				//0...4096(12bits)

	//битовые пол€, группировка под размер типа int по 4 байта
	//unsigned int nDayOfWeek : 3;			//1...7  (3bits)
	//unsigned int nDayOfMonth : 5;			//1...31 (5bits)
	//unsigned int nMonth : 4;				//1...12 (4bits)
	//int nYear : 12;							//0...4096(12bits)

	//битовые пол€, группировка под размер типа char по 1 байту
	//но значени€ от 0 до 255 и представлены в символах(потребуетс€ преобразование
	//unsigned char nDayOfWeek : 3;			//1...7  (3bits)
	//unsigned char nDayOfMonth : 5;			//1...31 (5bits)
	//unsigned char nMonth : 4;				//1...12 (4bits)
	//unsigned char nYear : 7;			    //0...99(7bits)

	unsigned int nDayOfWeek : 3;			//1...7  (3bits)
	unsigned int nDayOfMonth : 5;			//1...31 (5bits)
	unsigned int nMonth : 4;				//1...12 (4bits)
	unsigned int nYear : 7;					//0...99(7bits)
	unsigned int nHour : 5;					//0...24(5bits)
	unsigned int nMinute : 6;				//0...60(6bits)
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "–азмер даты: " << sizeof(Date) <<" байт(а)!"<< endl;
	Date Today{ 5,27,05, 22 };
	//cout << Today.nDayOfMonth << "." << Today.nMonth << "." << Today.nYear << " - "; //дл€ числовых типов данных
	//cout << (int)Today.nDayOfMonth << "." << (int)Today.nMonth << "." << (int)Today.nYear << " - ";
	//switch ((int)Today.nDayOfWeek)
	//switch (Today.nDayOfWeek)

	Date Now{ 5,27,05,22,19,04 };
	cout << "¬рем€: "<<Now.nHour<<":"<<Now.nMinute<<" ƒата: "<< Now.nDayOfMonth << "." << Now.nMonth << "." << Now.nYear << " - "; //дл€ числовых типов данных
	switch (Now.nDayOfWeek)
	{
	case 5:
		cout << "ѕ€тница!" << endl;
		break;
	}
}
*/