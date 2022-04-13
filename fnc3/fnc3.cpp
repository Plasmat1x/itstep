// DefaultArguments
#include <iostream>
#include <locale.h>

using namespace std;

//прототип функции, которая вывод символы на экран
int Symbols(char Symbol, int Rows, int Columns);


int main()
{
	setlocale(LC_ALL, "rus");
	int rows = 3;
	int columns = 7;
	char symbol = '*';
	int count = 0;
	count = Symbols(symbol, rows, columns);
	cout << "\nКол-во вызовов функции: " << count << endl;
	count = Symbols(symbol, rows, columns);
	cout << "\nКол-во вызовов функции: " << count << endl;
	count = Symbols(symbol, rows, columns);
	cout << "\nКол-во вызовов функции: " << count << endl;
	count = Symbols(symbol, rows, columns);
	cout << "\nКол-во вызовов функции: " << count << endl;

}
//реализация функции, которая вывод символы на экран
int Symbols(char Symbol, int Rows, int Columns)
{
	int Call = 0; //локальная переменная, доступна только внутри функции и создаётся заново при каждом вызове функции
	Call++;
	if (Call < 7) //ограничение по кол-ву вызовов функции
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				cout << Symbol;
			}
			cout << endl;
		}
	else
		cout << "Превышено кол-во вызовво функции!" << endl;
	return Call; //возвращаем кол-во вызовов функции
}

// DefaultArguments
#include <iostream>
#include <locale.h>

using namespace std;

//прототип функции, которая вывод символы на экран
//int Symbols(char Symbol='%', int Rows=1, int Columns=10); //значения параметров поумолчанию
int Symbols(char = '%', int = 1, int = 10); //значения параметров поумолчанию
//при использовании прототипа функции  укзаываются только в нем, а имена параметров можно не указывать

//int Call = 0; //глобальная переменная для подсчета кол-ва вызовов функции

int main()
{
	setlocale(LC_ALL, "rus");
	int rows = 3;
	int columns = 7;
	char symbol = '*';
	int count = 0;
	//Call = 500; //изменение занчения глобальной переменной повлияет на все попытки её дольнейшего использования
	count = Symbols(symbol, rows, columns); //вызов функци с указание значений всех параметров
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols(symbol, rows); //вызов функции со значением последнего параметра взятым поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols(symbol); //вызов функции со значениями всех параметров, кроме первого взятыми поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols(); //вызов функции со значениями всех параметров взятыми поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols('&'); //вызов функции со значениями всех параметров, кроме первого взятыми поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols('$', 2); //вызов функции со значением последнего параметра взятым поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	//два лишних вызова функции
	count = Symbols(); //вызов функции со значениями всех параметров взятыми поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
	count = Symbols(); //вызов функции со значениями всех параметров взятыми поумолчанию
	cout << "Кол-во вызовов функции: " << count << endl;
}
//реализация функции, которая вывод символы на экран
int Symbols(char Symbol, int Rows, int Columns)//если есть прототип то в реализации занчения параметров поумолчанию не указываются
{
	//int Call = 0; //локальная переменная, доступна только внутри функции и создаётся заново при каждом вызове функции
	static int Call = 0; //статическая локальная переменная создается один раз при первом вызове функции, при повторных вызовах
	//заново не создается, а хранит предыдущее значение до конца работы программы. Статическая переменная созданная внутри функции
	//доступна только внутри функции
	Call++;
	if (Call < 7) //ограничение по кол-ву вызовов функции
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				cout << Symbol;
			}
			cout << endl;
		}
	else
		cout << "Превышено кол-во вызовов функции!" << endl;
	return Call; //возвращаем кол-во вызовов функции
}