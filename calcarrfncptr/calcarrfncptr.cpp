// MassivePointersFunctions
#include <iostream>
#include <windows.h>
#include <stdlib.h>
/*
“ДЗ. Добавить в программу калькулятора с помощью массива 
указателей на функции. Две функции: возведения в степень и 
вычисление корня”
*/
using namespace std;
//функции реализующие работу программы(BackEnd)
float Summa(float A, float B);
float Raznost(float A, float B);
float Proizvedenie(float A, float B);
float Chastnoe(float A, float B);
float Stepen(float A, float B);
float Koren(float A, float B);

//можно добавить функцию выход
float Vyhod(float A, float B)
{
	cout << "Выход..." << endl;
	Sleep(1500);
	return 0.0F;
}

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
void Action5(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "5. Степень: ";
	cout << A << "^" << B << "=" << Stepen(A, B) << endl;
}
void Action6(float A, float B) //стандантартизация сигнатур функции
{
	system("cls");
	cout << "6. Корень: <Временно не работает>";
	cout << A << "V" << B << "=" << Koren(A, B) << endl;
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
	//Калькулятор через массив указателей на функции
	//массив имен функций, имена функции используются для инициализации элементов массива
	float A = 0.0F, B = 0.0F;
	int Select = 0; //индекс элемента массива функций(номер пункту меню)
	//const int CountFunctions =5;	

	//создаем массив указателей на функции и инициализируем его адресами функции
	//void (*Actions[CountFunctions])(float, float) = { Action0,Action1,Action2,Action3,Action4 };
	//void (*Actions[])(float, float) = { Action0,Action1,Action2,Action3,Action4};

	//массив указателей на исходные функции(BackEnd)
	//float(*Calculator[CountFunctions])(float, float) = { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe };
	//auto Calculator= { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe };

	int CountFunctions = 0;
	cout << "Введите кол-во функции не меньше 5: "; cin >> CountFunctions;

	typedef void(*PTRFunc)(float, float); //typedef - переопределение типа данных
	PTRFunc* Actions = new PTRFunc[CountFunctions]{ Action0,Action1,Action2,Action3,Action4,Action5,Action6 };

	/*auto Z=0;
	auto X = 0ULL;
	auto PTR = Action0;
	auto Pi = 3.14F;
	float PI = 3.14;
	int W = 3.14;*/
	//auto - автоматическое опреджеление типа данных на основании типа данных присваиваемого значения

	//цикл повторных вычислений
	do
	{
		system("cls");
		cout << "---Величайший в мире калькулятор!!!---" << endl;
		//цикл проверки пользовательского вводда
		do
		{
			cout << R"(Выберите действие:
1. Сложение
2. Вычитание
3. Умножение
4. Деление
5. Степень
6. Корень
0. Выход
)";
			cin >> Select;
			if (Select<0 || Select>CountFunctions)cout << "Некорректный выбор действия! Попробуйте ещё!" << endl;
		} while (Select<0 || Select>CountFunctions);
		//ввод значений А и В. Добавить проверку
		if (Select != 0)
		{
			system("cls");
			cout << "Введиет число А: "; cin >> A;
			cout << "Введиет число B: "; cin >> B;
		}
		//выбор и вызов нужной функции по индексу элемента массива указателей на функции
		Actions[Select](A, B);
		if (Select != 0)system("pause");
		//if (Select != 0) //если выбрано действие
		//{
		//	cout << "Результат равен: " << Calculator[Select](A, B) << endl;
		//	system("pause");
		//}
		//else Calculator[Select](A, B); //если выбран выход
	} while (Select != 0);
	delete[] Actions; //освобождение памяти
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

float Stepen(float A, float B)
{
	if (B < 1) return 1.f;
	return A * Stepen(A, B-1);
}

#include <math.h>
float Koren(float A, float B)
{
	//TODO алгоритм ньютона
	return 0.f;
}