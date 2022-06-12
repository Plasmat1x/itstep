/*
// PointerFunction
#include <iostream>
#include <stdlib.h>

using namespace std;

void F1()
{
	int A = 15;
	cout << "Адрес переменной А: " << &A << endl;
	cout << "Выполняется функция F1()" << endl;
}
void F2(int X)
{
	X *= 2;
	cout << "Адрес параметра функции X: " << &X << endl;
	cout << "Выполняется функция F2() " << X << endl;
}
void F3(int Y)
{
	Y += 10;
	cout << "Выполняется функция F3() " << Y << endl;
}
int F4(double Z)
{
	cout << "Выполняется функция F4() " << Z << endl;
	return (int)Z; //явное сужающее преобразование отбросит дробную часть
}

int C = 100;

float Summa(float A, float B)
{
	return A + B;
}
float Raznost(float A, float B)
{
	return A - B;
}
float Proizvedenie(float A, float B)
{
	return A * B;
}
float Chastnoe(float A, float B)
{
	return A / B;
}

int main()
{
	system("chcp 1251");
	system("cls");

	//теория указателей на функции
	F1(); //вызов функции по имени

	//получение адреса функции через операцию взятие адреса
	cout << "Адрес функции F1: " << &F1 << endl;
	cout << "Адрес функции F2: " << &F2 << endl;
	cout << "Адрес функции F3: " << &F3 << endl;
	cout << "Адрес функции F4: " << &F4 << endl;

	//получение адреса функции по её имени(имя функции - указатель, хранящий адрес функции в памяти)
	cout << "\nАдрес функции F1: " << F1 << endl;
	cout << "Адрес функции F2: " << F2 << endl;
	cout << "Адрес функции F3: " << F3 << endl;
	cout << "Адрес функции F4: " << F4 << endl;

	F2(5);

	int B = 10;
	cout << "Адрес переменной B: " << &B << endl;
	cout << "Адрес переменной C: " << &C << endl;

	system("cls");
	int* ptrB = &B; //указатель на переменную типа int
	//указатель на функцию без параметров и без возвращаемого значения
	void (*ptrF1)() = nullptr; //нулевой указатель на функцию без параметров и без возвращаемого значения
	ptrF1 = &F1; //передаем адрес функции, полученный через взятие адреса в указатель на функцию
	//ptrF1 = &F2; //сигнатура(заголовок) функции и указателядолжны совпадать
	F1(); //вызов функции по имени
	*ptrF1; //вызова не будет, будет получен адрес функции, хранящийся в указателе
	//*ptrF1(); //так не работает!
	(*ptrF1)(); //вызов функции F1 через её адрес, хранящийся в указателе ptrF1, путем его разыменования
	ptrF1(); //вызов функции по указателю на неё

	//указатель на функцию с параметром типа данных double и возвращающую значение типа int
	int (*ptrF4)(double) = F4; //инициализация указателя на функцию, используя имя функции
	cout << ptrF4(3.14) << endl; //вызов функции с параметром и возвращаемым занчением через указатель

	system("cls");

	void(*Pointer)(int) = F2;
	Pointer(5);
	Pointer = F3;  //в указатель на функцию можно поместить адрес любой функции, чья сигнатура(заголовок) ему соответствует
	Pointer(5);

	void(*ptrF2)(int) = F2;
	Pointer = ptrF2;  //в указатель на функцию можно поместить содержимео другого указателя на функцию(адрес функции)
	//если их сигнатуры совпадают
	Pointer(5);

	float A = 0.0F, B = 0.0F;
	char Key = '+';
	//нулевой указатель на функции
	float (*calc)(float, float) = nullptr;
	do
	{
		system("cls");
		cout << "---Самый лучший в мире калькулятор!---" << endl;
		cout << R"(
Используйте действия по образцу:
Сложение:                   A+B
Вычитание:                  А-В
Умножение:                  А*В
Деление:                    А/В
)";
		cin >> A >> Key >> B;
		switch (Key)
		{
		case '+':
			calc = Summa; //присваиваем указателю адрес функции сумма
			break;
		case '*':
			calc = Proizvedenie;
			break;
		case '/':
			calc = Chastnoe;
			break;
		case '-':
			calc = Raznost;
			break;
		default:
			Key = '0'; //если выбор некорректный
			break;
		}
		if (Key != '0')cout << "Результат равен: " << calc(A, B) << endl;
		cout << "Продолжим выичсления(Y/N)? "; cin >> Key;
	} while (Key == 'Y' || Key == 'y');
}
*/

// MassivePointersFunctions
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;
//функции реализующие работу программы(BackEnd)
float Summa(float A, float B);
float Raznost(float A, float B);
float Proizvedenie(float A, float B);
float Chastnoe(float A, float B);

//функции реализующие единообразную визуальную составляющую программы
void Action1(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "1. Сложение " << A << "+" << B << ":" << endl;
	cout << "Сумма равна: " << Summa(A, B) << endl;
}
void Action2(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "2. Вычитание: " << A << "-" << B << "=" << Raznost(A, B) << endl;
	//cout << "Разность равна: " << Raznost(A, B) << endl;
}
void Action3(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "3. Умножение: " << A << "*" << B << "=" << Proizvedenie(A, B) << endl;
}
void Action4(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "4. Деление: ";
	if (B == 0)
	{
		cout << "\nНа ноль делить нельзя!!!" << endl;
		return;
	}
	cout << A << "/" << B << "=" << Chastnoe(A, B) << endl;
}
void Action0(float A, float B) //стандантартизация сигнатур функции
{
	cout << "0. Выход..." << endl;
	Sleep(1500);
}

int main()
{
	system("chcp 1251");
	system("cls");




}
float Summa(float A, float B)
{
	return A + B;
}
float Raznost(float A, float B)
{
	return A - B;
}
float Proizvedenie(float A, float B)
{
	return A * B;
}
float Chastnoe(float A, float B)
{
	return A / B;
}