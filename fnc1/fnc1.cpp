#include <iostream>
#include <stdlib.h>
#include <Windows.h>

void fnc()
{
    std::cout << "hello world\n";
}

void fnc1(const char* str)
{
    std::cout << str << std::endl;
}

int fnc2(int a, int b)
{
    return a + b;

    //int result = a + b;
    //return a + b;

}

void fnc3(int& a, int b)
{
    a += b;
}

void printLine(char ch, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int myPow(int a, int b)
{
    int resault = 1;

    for (int i = 0; i < b; i++)
    {
        resault *= a;
    }

    return resault;
}

int main(int argc, char* argv[])
{
    /*
    fnc();
    fnc1("Mike");
    std::cout << fnc2(2, 5) << std::endl; // or int resault = fnc(2,5) -> resault = 2 + 5;
    int a = 2;
    int b = 10;
    std::cout << a << std::endl;
    fnc3(a, b);
    std::cout << a << std::endl;
    printLine('@', 10);
    */
    int res = 0;
    res = myPow(5, 3);
    std::cout << res << std::endl;

    return 0; // 0 - succefull exit, != 0 error
}

/* //test console ru input
int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char input;
    std::cin >> input;

    if (input == 'Х') //-43 символ в 1251, в вводе в консоле 0
    {
        std::cout << input << std::endl;
        std::cout << (int)input << std::endl;
    }
    else
    {
        std::cout << "Другая кодовая страница" << std::endl;
        std::cout << (int)input << std::endl;
    }
    
    return 0;
}
*/

/*
// Functions
#include <iostream>
#include <locale.h>

using namespace std;

//объявление и реализация функции
void Hello() //функция не принемает параметров и не возвращает результат
{
	//тело функции (реализация)
	cout << "Привет, Мир!" << endl;
}
//Функция принемает кол-во зведочек в качестве параметра
//и выводит на экран заданное кол-во зведочек
void Stars(int Count) //функция принимает 1 параметр, но не возвращает результат
{
	//int Count=5; //5 это значение полученное функцией при её вызове
	for (int i = 0; i < Count; i++)
	{
		cout << "*";
	}
	cout<<endl;
}
//функция вывода на экран линии заданных символов в заданном кол-ве
//функция принемает 2 параеметра но не возвращает результат
void PrintLine(char Symbol, int Count) //void print_line(char Symbol, int Count) //void Print_Line(char Symbol, int Count)
{
	if (Count <= 0)
	{
		cout << "Кол-во должно быть больше нуля!" << endl;
		return;  //прерывает работу функции
	}
	for (int i = 0; i < Count; i++)
	{
		cout << Symbol;
	}
	cout << endl;
}
//функция возведения целого числа Digit в целую степень Pow
int MyPow(int Digit, int Pow) //функция принемает 2 параметра типа int и возвращает результат типа int
{
	int Result = 1; //промежуточный и конечный результат
	for (int i = 0; i < Pow; i++)
	{
		Result *= Digit; //Result=Result*Digit;
	}
	return Result; //прерывает работу функции и возвращает указанное значение на место вызова функции
	cout << "Ура!" << endl; //эта строчка не будет выполнена
}


int main()
{
	setlocale(LC_ALL, "rus"); //вызов функции с двумя параметрами

	//Hello(); //вызов функции без праметров
	//Hello();
	//Hello();
	//Hello();
	//Hello();
	//Stars(5); //вызов функции с одним параметром
	//int Count = 10;
	//Stars(Count); //вызов функции со значением переменной в качестве параметра
	//cout << "Введите кол-во звездочек: "; cin >> Count;
	//Stars(Count);

	//PrintLine('%', 10); //вызов функции с двумя параметрами. Порядок параметров при вызове должен соответсвовать порядку в объявлении функции
	//char Symbol = ' ';
	//int Count = 0;
	//cout << "Введите символ: "; cin >> Symbol;
	//cout << "Введите кол-во символов: "; cin >> Count;
	//PrintLine(Symbol, Count);

	MyPow(5, 3); //на место вызова функции будет возвращен результат
	cout << "Число 5 в степени 3: " << MyPow(5, 3) << endl;
	int Result = MyPow(5, 3); //инициализация переменной результатом работы функции
	cout << "Результат: " << Result << endl;
	//int A = rand();

	PrintLine('&', -3);
	int Count = 0;
	cout << "Введите кол-во: "; cin >> Count;
	PrintLine('$', Count);

}

*/

/*
// Visible
#include <iostream>
#include <locale.h>

using namespace std;
//первая функция
void First()
{
    cout<<"Сейчас работает первая функция!"<<endl;
}
//вторая функция
void Second()
{
    cout << "Начало работы второй функции!" << endl;
    First();  //вызов первой функции во время работы второй функции, первая функция должна быть объявлена перед второй
    cout << "Конец работы второй функции!" << endl;
    //Global = 1; //переменная недоступна, так как объявлена после функции
}
//прототип функции определения максимума из двух чисел
//int Max(int A, int B);  //; в прототипе обязательна
int Max(int, int); //имана параметров в прототипе можно не писать, а кол-во, типы данных
//и порядок параметров должны быть

//глобальные переменные
int Global; //по умолчанию глобальные переменные инициализируются 0
const double PI = 3.14; //константы обязательно нужно инициализировать

int main()
{
    setlocale(LC_ALL, "rus");
    //First();
    //Second();
    int A = 10, B = 5; //локлаьныя переменные функции main
    cout << "Глобальная переменная: " << Global << endl;
    cout<<"Максимум между А и В: "<<Max(A, B) << endl;
    cout<<"Глобальная переменная: "<<Global<<endl;
    int Local = 555; //локальная переменная доступна только внутри main
    cout << "Глобальная константа PI: " << PI << endl;
    float PI = 3.14159; //локальная переменная PI подменит собой глобальную константу PI
    cout << "Локальная переменная PI: " << PI << endl;
    cout << "Глобальная константа PI: " << ::PI << endl;
    std::cout << endl;
    //int PI = 3.5; //внутри одной области видимости нельзя использовать одинаковые имена
    //блок кода, определяет область видимости
    {
        cout << "Начало области видимости!" << endl;
        int PI = 4; //локальная переменная для блока кода
        cout << "Локальная переменная PI: " << PI << endl;
        cout << "Глобальная константа PI: " << ::PI << endl;
        //int PI; //внутри одной области видимости нельзя использовать одинаковые имена
        double g = 9.8;
        cout << "Переменная g: " << g << endl;
        cout << "Конец области видимости!" << endl;
    }
    //cout << "Переменная g: " << g << endl; //g доступна только в блоке кода
    cout << "Локальная переменная PI: " << PI << endl;

}
//реализация функции определения максимума из двух чисел
int Max(int A, int B) //в реализауии имена параметров должны быть в любом случае
{
    Global = 100; //глобальная переменная доступна
    //Local = 1; //локальная переменная доступна только внутри main
    if (A > B)return A; //когда А>B
    else
        if (A == B)
        {
            cout << "Значения равны!" << endl;
            return A; //когда A==B
        }
        else return B; //когда B>A
}

*/