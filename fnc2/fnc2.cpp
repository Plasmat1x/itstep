// Functions2.0
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
//функция меняющая значения двух переменных местами
void Swap(int One, int Two)
{
	//One и Two - копии переменых А и В
	//int One=A, Two=B; 
	cout << "Работает функция Swap!" << endl;
	cout << "Первое число: " << One << " Второе число " << Two << endl;
	//поменяем содержимое переменных местами
	int temp = One; //temp - буфер для обмена значений местами
	One = Two;
	Two = temp;
	cout << "Первое число: " << One << " Второе число " << Two << endl;
	cout << "Функция Swap завершила работу!" << endl;
}
//функция подсчета кол-ва четных элементов массива
int CountEvenElements(int Array[], int Size)  //int count_even_elements() //int Count_Even_Elements()
{
	int Count = 0; //кол-во четных элементов
	for (int i = 0; i < Size; i++)
	{
		if (Array[i] % 2 == 0)
		{
			Count++;
			cout << Array[i] << " ";
		}
	}
	cout << endl;
	return Count; //возвращаем кол-во четных элементов
}
//прототип функции замены отрицательных элементов
int NegativeElements(int Massive[], int Count);

//глобальные константы для задания размера массива
const int Row = 10;
const int Col = 6;

//функция вычисления суммы всех элементов двумерного массива
//int SummaAllElements(int Array[][6],int Row,int Col) //обязательно нужно указать кол-во элементов в строке
//int SummaAllElements(int Array[][Col]) //используя для этого глобальные константы, можно размеры не передавать отдельно
int SummaAllElements(int Array[Row][Col]) //значение кол-ва строк Row можно не указывать
{
	int Summa = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			Summa += Array[i][j];
		}
	}
	return Summa;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	//int A = -3, B = 15;
	//cout << "Число А: " << A << " Число В: " << B << endl;
	//cout << endl;
	//Swap(A, B); //при вызове функции в функцию передаются значения, а не сами переменные
	//cout << endl;
	//cout << "Число А: " << A << " Число В: " << B << endl;

	//const int Size = 50;
	//int Array[Size]{};
	//int Result = 0; //хранит результат работы функции
	//for (int i = 0; i < Size; i++)
	//{
	//	//if(i%10==0&&i!=0)cout<<endl; //перевод строки после каждого десятого элемента (перед элементом с индексом 10)
	//	Array[i]=rand()%(100-(-99))-99;
	//	if (Array[i] >= 0)cout << " ";
	//	if (Array[i] > -10 && Array[i] < 10)cout << " ";
	//	cout << Array[i] << " ";
	//	if ((i+1)%10==0)cout << endl; //перевод строки после каждого десятого элемента (после элемента с индексом 9)
	//}
	//cout<<"\n"<<endl;
	//Result=CountEvenElements(Array, Size); //помещаем результат работы функции в переменную
	//cout<<"Кол-во четных элементов равно: "<<Result<<endl;
	//Result = NegativeElements(Array, Size); //помещаем результат работы функции в переменную
	////при вызове функции с массиво в качестве аргумента, работа в функции идет с исходным массивом, то есть с самим Array
	//cout << "Кол-во отрицательных элементов равно: " << Result << endl;
	//for (int i = 0; i < Size; i++)
	//{		
	//	if (Array[i] >= 0)cout << " ";
	//	if (Array[i] > -10 && Array[i] < 10)cout << " ";
	//	cout << Array[i] << " ";
	//	if ((i + 1) % 10 == 0)cout << endl; //перевод строки после каждого десятого элемента (после элемента с индексом 9)
	//}
	//cout << "\n" << endl;

	//const int Row = 10;
	//const int Col = 6;
	int Mass[Row][Col]{};
	//в первых [] указывается кол-во строк, а во вторых [] кол-во элементов в каждой строке
	int Summa = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			Mass[i][j] = rand() % (100 - (-99)) - 99;
			cout << "Mass[" << i << "][" << j << "]=";
			if (Mass[i][j] >= 0)cout << " ";
			if (Mass[i][j] > -10 && Mass[i][j] < 10)cout << " ";
			cout << Mass[i][j] << " | ";
		}
		cout << endl;
	}
	//Summa = SummaAllElements(Mass, Row, Col);
	Summa = SummaAllElements(Mass);
	cout << "Сумма всех элементов массива равна: " << Summa << endl;
}

//реализация функции замены отрицательных элементов
int NegativeElements(int Massive[], int Count)
{
	//Massive выступает как "псевдоним" для Array
	int CountNegative = 0; //кол-во отрицательных элементов
	for (int i = 0; i < Count; i++)
	{
		if (Massive[i] < 0)
		{
			CountNegative++; //считаем колв-о отрицательных элементов
			//если элемент четный, то заменим его на ноль
			if (Massive[i] % 2 == 0)Massive[i] = 0;
			else Massive[i] = -Massive[i]; //иначе изменим знак с минуса на плюс
		}
	}
	return CountNegative; //возвращаем кол-во отрицательных элементов
}