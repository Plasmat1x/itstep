// Reference
#include <iostream>
#include <stdlib.h>

using namespace std;

void part1();
void part2();

int main()
{
	//part1();
}


void part1()
{

	system("chcp 1251");
	system("cls");
	int X = 15;
	//ссылка на значение переменной Х
	int& ref_X = X; //инициализация ссылки переменной Х
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	X += 15;
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	ref_X += 15; //все действия над ссылкой выполняются над самой переменной
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	int Y = 17;
	ref_X = Y; //присваивание значения перменной Y переменной X, по ссылке на неё (ref_X)
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	int& ref_Y = Y;
	ref_Y = 100;
	cout << "Y= " << Y << endl;
	ref_X = ref_Y; //X=Y; присваивание значения переменной Y, взятого по ссылке на неё(ref_Y)
	//переменной Х, по ссылке на неё(ref_X)
	cout << "X= " << X << endl;
	ref_Y = 200;
	cout << "Y= " << Y << endl;
	cout << "X= " << X << endl;
	//ссылка всегда ссылается на один и тот же объект
	//int& const cRefX = X; //старый способ создания константных ссылок
	const int& cRefX = X; //констнатная ссылка (ссылка на константу)
	//cRefX = -555;  //ссылка, по которой нельзя изменить значение объекта
	cout << "cRefX= " << cRefX << endl;
	X = 200;
	cout << "cRefX= " << cRefX << endl;
	system("cls");
	int Z = 150; //переменная Z
	int* ptr_Z = &Z; //указатель на переменную Z(хранит адрес переменной Z)
	int& ref_Z = Z;  //ссылка на переменню Z(псевдоним) (ссылается на значение)
	cout << "Значение объекта Z по имени: " << Z << endl;
	cout << "Значение объекта Z через указатель: " << *ptr_Z << endl;
	cout << "Значение объекта Z по ссылке: " << ref_Z << endl;
	system("cls");

	float* ptr = nullptr; //нулевой указатель, может быть создан до создания объекта
	//блок кода - ограничивает область видимости(определяе срок жизни объектов, созданых внутри него)
	{
		float PI = 3.14F; //локальная переменная блока кода
		float& refPI = PI; //локальная ссылка на переменную PI, может быть объявлена только после создания объекта
		float* ptrPI = &PI; //локальный указатель на переменную PI
		cout << "Значение переменной PI по имени: " << PI << endl;
		cout << "Значение переменной PI через указатель: " << *ptrPI << endl;
		cout << "Значение переменной PI по ссылке: " << refPI << endl;
		ptr = &PI; //"нацелим" внешний указатель на переменную PI
		cout << "Значение переменной PI через указатель ptr: " << *ptr << endl;
		cout << "Адрес переменной PI через указатель ptr: " << ptr << endl;
	}
	//cout << "Значение переменной PI по имени: " << PI << endl;
	//cout << "Значение переменной PI через указатель: " << *ptrPI << endl;
	//cout << "Значение переменной PI по ссылке: " << refPI << endl;
	cout << endl;
	cout << "Значение переменной PI через указатель ptr: " << *ptr << endl;
	cout << "Адрес переменной PI через указатель ptr: " << ptr << endl;
	//указатель ptr продолжает хранить адрес, после уничтожения самого объекта
	//если объект уничтожен, то указатель нужно или "перенацелить" на другой объект или обнулить
	ptr = nullptr;
	//НЕЛЬЗЯ РАЗЫМЕНОВАТЬ НУЛЕВОЙ УКАЗАТЕЛЬ!!!
	//if(ptr!=nullptr) // если указатель не нулевой
	if (ptr)cout << "Значение переменной PI через указатель ptr: " << *ptr << endl;
	cout << "Адрес переменной PI через указатель ptr: " << ptr << endl;
	system("cls");

	int M = 70;
	int* ptr_M = &M;
	int& ref_M = M;
	cout << ptr_M << endl;
	cout << &ref_M << endl;
	int* ptr_ref_M = &ref_M; //в указатель будет помещен адрес переменной М, взятый по ссылке
	cout << ptr_ref_M << endl;

	//ссылка на указатель
	int*& ref_ptr_M = ptr_M; //ссылка на int*

	cout << ref_ptr_M << endl; //ссылка жто псевдоним - второе имя укзаателя ptr_M
	cout << ptr_M << endl;
}

/*
swap ptrs

tmp = *ptr1
*ptr1 = *ptr2
*ptr2 = temp

*/

void swapRef(int& rone, int& rtwo)
{
	int tmp = rone;
	rone = rtwo;
	rtwo = tmp;
}

void part2()
{
	/*

// RefFunctions
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//функция возвращает ЗНАЧЕНИЕ максимального элемента массива
int Max_Elem(int Array[], int Size)
{
	int index_max = 0; //индекс максимального элемента
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //находим индекс максимального элемента
	}
	cout << "\nМаксимальный элемент массива А[" << index_max << "]=" << Array[index_max] << endl;
	return Array[index_max]; //возвращаем ЗНАЧЕНИЕ максимального элемента массива
}
//функция возвращает АДРЕС максимального элемента массива
int* Ptr_Max_Elem(int Array[], int Size)
{
	int index_max = 0; //индекс максимального элемента
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //находим индекс максимального элемента
	}
	cout << "\nМаксимальный элемент массива А[" << index_max << "]=" << Array[index_max] << endl;
	//return &Array[index_max]; //возвращаем АДРЕС максимального элемента массива, с помощью взятия адреса
	return Array + index_max; //возвращаем АДРЕС максимального элемента массива, с помощью смещения
	//адреса (из указателя Array) от начала массива на индекс максимального элемента
}

//функция возвращает ССЫЛКУ на максимальный элемент массива
int& Ref_Max_Elem(int Array[], int Size)
{
	int index_max = 0; //индекс максимального элемента
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //находим индекс максимального элемента
	}
	cout << "\nМаксимальный элемент массива А[" << index_max << "]=" << Array[index_max] << endl;
	return Array[index_max]; //возвращаем ССЫЛКУ на максимальный элемент массива
}

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	const int Size = 15;
	int Array[Size]{};
	for (int i = 0; i < Size; i++)
	{
		Array[i]=rand()%(100-(-99))-99;
		cout<<"A["<<i<<"]="<<Array[i]<<"; ";
	}
	cout << endl;
	int Max = Max_Elem(Array, Size); //помещаем в переменную результат работы функции
	cout << "Значение макс. элемента: " << Max << endl;

	Max = *Ptr_Max_Elem(Array, Size); //помещаем результат работы функции в переменную, разыменовав указатель, возвращаемый функцией
	cout << "Значение макс. элемента: " << Max << endl;

	//*Ptr_Max_Elem(Array, Size) = -1000; //помещаем по адресу(результату работы функции) новое значение,
	//разыменовав указатель, возвращаемый функцией / мы заменили значение максимального элемента на -1000

	Max = Ref_Max_Elem(Array, Size); //помещаем в переменную значение, взятое по ссылке, которую возвращает функция
	cout << "Значение макс. элемента: " << Max << endl;
	Ref_Max_Elem(Array, Size) = -1000; //помещаем новое значение в максимальный элемент по ссылке на него, которую возвращает функция


	for (int i = 0; i < Size; i++)
	{
		cout << "A[" << i << "]=" << Array[i] << "; ";
	}

}

*/
}

