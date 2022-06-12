// MassivePointersFunctions
#include <iostream>
#include <windows.h>
#include <stdlib.h>
/*
���. �������� � ��������� ������������ � ������� ������� 
���������� �� �������. ��� �������: ���������� � ������� � 
���������� ������
*/
using namespace std;
//������� ����������� ������ ���������(BackEnd)
float Summa(float A, float B);
float Raznost(float A, float B);
float Proizvedenie(float A, float B);
float Chastnoe(float A, float B);
float Stepen(float A, float B);
float Koren(float A, float B);

//����� �������� ������� �����
float Vyhod(float A, float B)
{
	cout << "�����..." << endl;
	Sleep(1500);
	return 0.0F;
}

//������� ����������� ������������� ���������� ������������ ���������
void Action1(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "1. �������� " << A << "+" << B << ":" << endl;
	cout << "����� �����: " << Summa(A, B) << endl;
}
void Action2(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "2. ���������: " << A << "-" << B << "=" << Raznost(A, B) << endl;
	//cout << "�������� �����: " << Raznost(A, B) << endl;
}
void Action3(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "3. ���������: " << A << "*" << B << "=" << Proizvedenie(A, B) << endl;
}
void Action4(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "4. �������: ";
	if (B == 0)
	{
		cout << "\n�� ���� ������ ������!!!" << endl;
		return;
	}
	cout << A << "/" << B << "=" << Chastnoe(A, B) << endl;
}
void Action5(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "5. �������: ";
	cout << A << "^" << B << "=" << Stepen(A, B) << endl;
}
void Action6(float A, float B) //����������������� �������� �������
{
	system("cls");
	cout << "6. ������: <�������� �� ��������>";
	cout << A << "V" << B << "=" << Koren(A, B) << endl;
}
void Action0(float A, float B) //����������������� �������� �������
{
	cout << "0. �����..." << endl;
	Sleep(1500);
}

int main()
{
	system("chcp 1251");
	system("cls");
	//����������� ����� ������ ���������� �� �������
	//������ ���� �������, ����� ������� ������������ ��� ������������� ��������� �������
	float A = 0.0F, B = 0.0F;
	int Select = 0; //������ �������� ������� �������(����� ������ ����)
	//const int CountFunctions =5;	

	//������� ������ ���������� �� ������� � �������������� ��� �������� �������
	//void (*Actions[CountFunctions])(float, float) = { Action0,Action1,Action2,Action3,Action4 };
	//void (*Actions[])(float, float) = { Action0,Action1,Action2,Action3,Action4};

	//������ ���������� �� �������� �������(BackEnd)
	//float(*Calculator[CountFunctions])(float, float) = { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe };
	//auto Calculator= { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe };

	int CountFunctions = 0;
	cout << "������� ���-�� ������� �� ������ 5: "; cin >> CountFunctions;

	typedef void(*PTRFunc)(float, float); //typedef - ��������������� ���� ������
	PTRFunc* Actions = new PTRFunc[CountFunctions]{ Action0,Action1,Action2,Action3,Action4,Action5,Action6 };

	/*auto Z=0;
	auto X = 0ULL;
	auto PTR = Action0;
	auto Pi = 3.14F;
	float PI = 3.14;
	int W = 3.14;*/
	//auto - �������������� ������������ ���� ������ �� ��������� ���� ������ �������������� ��������

	//���� ��������� ����������
	do
	{
		system("cls");
		cout << "---���������� � ���� �����������!!!---" << endl;
		//���� �������� ����������������� ������
		do
		{
			cout << R"(�������� ��������:
1. ��������
2. ���������
3. ���������
4. �������
5. �������
6. ������
0. �����
)";
			cin >> Select;
			if (Select<0 || Select>CountFunctions)cout << "������������ ����� ��������! ���������� ���!" << endl;
		} while (Select<0 || Select>CountFunctions);
		//���� �������� � � �. �������� ��������
		if (Select != 0)
		{
			system("cls");
			cout << "������� ����� �: "; cin >> A;
			cout << "������� ����� B: "; cin >> B;
		}
		//����� � ����� ������ ������� �� ������� �������� ������� ���������� �� �������
		Actions[Select](A, B);
		if (Select != 0)system("pause");
		//if (Select != 0) //���� ������� ��������
		//{
		//	cout << "��������� �����: " << Calculator[Select](A, B) << endl;
		//	system("pause");
		//}
		//else Calculator[Select](A, B); //���� ������ �����
	} while (Select != 0);
	delete[] Actions; //������������ ������
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
	//TODO �������� �������
	return 0.f;
}