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
	//����������� ������ ����� - ��������� ������ ��������
	const int Rows = 10;
	const int col = 255;
	char Spisok[Rows][col]{}; //������ �� 10 ����� �� 255 �������� � ������
	//I ��� � ���������� �������� �� 10 �����
	for (int i = 0; i < Rows; i++)
	{
		gets_s(Spisok[i]); //Spisok[i] - ������(�������� ������ ��������)
	}
	//for (int i = 0; i < Rows; i++)
	//{
	//	//puts(Spisok[i]); //puts ������� ������ � ��������� ������
	//	cout<<Spisok[i]<<" - "<<strlen(Spisok[i])<<endl;
	//}
	//II ������� ��������� ����� i - ������ j - ������ � ������
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

	/*cout << "��� ������ ������� ����� �������..." <<endl;
	_getch();*/

	//������������ ������ �����
	//_MAX_PATH - ������������ ����� ������� ����� �����(� ������ ���� � ����������)
	char* Buffer = new char[_MAX_PATH]; //����� ��� ����������� �������� ������ ������
	int FileCount = 0; //���-�� ������
	cout << "������� ���-�� ������ � ����������: ";
	cin >> FileCount;
	cin.ignore(); //���������� 1 ������, ����������� � ������ cin � �������� �����

	char** ListFiles = new char* [FileCount] {}; //������������ ������ �����(������������ ������ ���������� char*)
	//����������� �������� ��������� ������
	for (int i = 0; i < FileCount; i++)
	{
		cout << "������� ��� " << i + 1 << "-�� �����: ";
		gets_s(Buffer, _MAX_PATH); //��������� ��� �����
		ListFiles[i] = new char[strlen(Buffer) + 1]{}; //��������� ������ ������� ������ ��� ��� �����
		strcpy_s(ListFiles[i], strlen(Buffer) + 1, Buffer); //�������� ��������� ������ � ������
	}
	delete[] Buffer;  //������������ ������ ��� �����
	Buffer = nullptr; //����������� ��������
	system("cls");

	int CountTXT = 0; //���-�� ������ � ����������� .txt
	//������ � ������������ �������� �����
	for (int i = 0; i < FileCount; i++)
	{
		if (strstr(ListFiles[i], ".txt"))
		{
			CountTXT++; //������� ���-�� txt ������
			puts(ListFiles[i]);
			//cout<< ListFiles[i]<<endl;
		}
		else
		{
			if (!strchr(ListFiles[i], '.')) //���� �� ������ ������ '.'
			{
				int Size = strlen(ListFiles[i]) + strlen(".txt") + 1; //����� ������ � ����������� ����������� � �������� ����� ������ '\0'
				Buffer = new char[Size] {}; //�������� ������ ��� ������ ������ �������
				strcpy_s(Buffer, strlen(ListFiles[i]) + 1, ListFiles[i]); //�������� ��� ����� � ����� ������
				strcat_s(Buffer, Size, ".txt"); //��������� ��������� .txt
				delete ListFiles[i]; //����������� ������ �� ��� ������ ������
				ListFiles[i] = Buffer; //����������� ����� ����� ������ ��������� �� ������ ������(��� �����)
				Buffer = nullptr;
			}
		}
	}
	cout << "���������� ���� " << CountTXT << " ��������� ������!" << endl;
	cout << "����� ������ ������: " << endl;
	CountTXT = 0;
	for (int i = 0; i < FileCount; i++)
	{
		if (strstr(ListFiles[i], ".txt"))
		{
			CountTXT++; //������� ���-�� txt ������
		}
		puts(ListFiles[i]);
	}
	cout << "������ " << CountTXT << " ��������� ������!" << endl;

	//������������ ������ ��� ������ ������
	for (int i = 0; i < FileCount; i++)
	{
		//�������� ��������
		delete[] ListFiles[i];
		ListFiles[i] = nullptr;
	}
	//����������� ������ ��� ��������� �� ������ �����
	delete[] ListFiles;
	ListFiles = nullptr;
}
