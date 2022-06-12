// MassiveStroki
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //_getch()

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	/*
	//статический массив строк - двумерный массив символов
	const int Rows = 10;
	const int col = 255;
	char Spisok[Rows][col]{}; //массив из 10 строк по 255 символов в каждой
	//I как с одномерным массивом из 10 строк
	for (int i = 0; i < Rows; i++)
	{
		gets_s(Spisok[i]); //Spisok[i] - строка(одмерный массив символов)
	}
	//for (int i = 0; i < Rows; i++)
	//{
	//	//puts(Spisok[i]); //puts выводит строку и переводит курсор
	//	cout<<Spisok[i]<<" - "<<strlen(Spisok[i])<<endl;
	//}
	//II вариант вложенные циклы i - строка j - символ в строке
	for (int i = 0; i < Rows; i++)
	{
		//for (int j = 0; j < col; j++)
		//for (int j = 0; j!='\0'; j++)
		for (int j = 0; j<strlen(Spisok[i]); j++)
		{
			cout << Spisok[i][j];
			//putchar(Spisok[i][j]);
		}
		cout<< " - " << strlen(Spisok[i]) << endl;
	}
	*/

	/*cout << "Для выхода нажмите любую клавишу..." <<endl;
	_getch();*/

	//динамический массив строк
	//_MAX_PATH - максимальная длина полного имени файла(с учетом пути и расширения)
	char* Buffer = new char[_MAX_PATH]; //буфер для определения размеров каждой строки
	int FileCount = 0; //кол-во файлов
	cout << "Введите кол-во файлов в директории: ";
	cin >> FileCount;
	cin.ignore(); //пропускаем 1 символ, овставшийся в потоке cin с прошлого ввода

	char** ListFiles = new char* [FileCount] {}; //динамический массив строк(динамический массив указателей char*)
	//Обязательно проверку выделения памяти
	for (int i = 0; i < FileCount; i++)
	{
		cout << "Введите имя " << i + 1 << "-го файла: ";
		gets_s(Buffer, _MAX_PATH); //считываем имя файла
		ListFiles[i] = new char[strlen(Buffer) + 1]{}; //выделение памяти нужного объема под имя файла
		strcpy_s(ListFiles[i], strlen(Buffer) + 1, Buffer); //копируем введенную строку в массив
	}
	delete[] Buffer;  //освобожденеи памяти под буфер
	Buffer = nullptr; //обязательна проверка
	system("cls");

	int CountTXT = 0; //кол-во файлов с расширением .txt
	//работа с динамическим массивом строк
	for (int i = 0; i < FileCount; i++)
	{
		if (strstr(ListFiles[i], ".txt"))
		{
			CountTXT++; //считаем кол-во txt файлов
			puts(ListFiles[i]);
			//cout<< ListFiles[i]<<endl;
		}
		else
		{
			if (!strchr(ListFiles[i], '.')) //если не найден символ '.'
			{
				int Size = strlen(ListFiles[i]) + strlen(".txt") + 1; //общий размер с добавленным расширением и символом конца строки '\0'
				Buffer = new char[Size] {}; //выделяем память под строку нвоого размера
				strcpy_s(Buffer, strlen(ListFiles[i]) + 1, ListFiles[i]); //копируем имя файла в новую строку
				strcat_s(Buffer, Size, ".txt"); //добавляем рсширение .txt
				delete ListFiles[i]; //освобождаем память из под старой строки
				ListFiles[i] = Buffer; //присваиваем адрес новой строки указателю на старую строку(имя файла)
				Buffer = nullptr;
			}
		}
	}
	cout << "Изначально было " << CountTXT << " текстовых файлов!" << endl;
	cout << "Новый список файлов: " << endl;
	CountTXT = 0;
	for (int i = 0; i < FileCount; i++)
	{
		if (strstr(ListFiles[i], ".txt"))
		{
			CountTXT++; //считаем кол-во txt файлов
		}
		puts(ListFiles[i]);
	}
	cout << "Теперь " << CountTXT << " текстовых файлов!" << endl;

	//освобождение памяти под каждую строку
	for (int i = 0; i < FileCount; i++)
	{
		//добавить проверку
		delete[] ListFiles[i];
		ListFiles[i] = nullptr;
	}
	//освобождаем память под указатель на массив строк
	delete[] ListFiles;
	ListFiles = nullptr;
}
