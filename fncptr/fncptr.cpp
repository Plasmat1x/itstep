/*
// PointerFunction
#include <iostream>
#include <stdlib.h>

using namespace std;

void F1()
{
	int A = 15;
	cout << "����� ���������� �: " << &A << endl;
	cout << "����������� ������� F1()" << endl;
}
void F2(int X)
{
	X *= 2;
	cout << "����� ��������� ������� X: " << &X << endl;
	cout << "����������� ������� F2() " << X << endl;
}
void F3(int Y)
{
	Y += 10;
	cout << "����������� ������� F3() " << Y << endl;
}
int F4(double Z)
{
	cout << "����������� ������� F4() " << Z << endl;
	return (int)Z; //����� �������� �������������� �������� ������� �����
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

	//������ ���������� �� �������
	F1(); //����� ������� �� �����

	//��������� ������ ������� ����� �������� ������ ������
	cout << "����� ������� F1: " << &F1 << endl;
	cout << "����� ������� F2: " << &F2 << endl;
	cout << "����� ������� F3: " << &F3 << endl;
	cout << "����� ������� F4: " << &F4 << endl;

	//��������� ������ ������� �� � �����(��� ������� - ���������, �������� ����� ������� � ������)
	cout << "\n����� ������� F1: " << F1 << endl;
	cout << "����� ������� F2: " << F2 << endl;
	cout << "����� ������� F3: " << F3 << endl;
	cout << "����� ������� F4: " << F4 << endl;

	F2(5);

	int B = 10;
	cout << "����� ���������� B: " << &B << endl;
	cout << "����� ���������� C: " << &C << endl;

	system("cls");
	int* ptrB = &B; //��������� �� ���������� ���� int
	//��������� �� ������� ��� ���������� � ��� ������������� ��������
	void (*ptrF1)() = nullptr; //������� ��������� �� ������� ��� ���������� � ��� ������������� ��������
	ptrF1 = &F1; //�������� ����� �������, ���������� ����� ������ ������ � ��������� �� �������
	//ptrF1 = &F2; //���������(���������) ������� � ��������������� ���������
	F1(); //����� ������� �� �����
	*ptrF1; //������ �� �����, ����� ������� ����� �������, ���������� � ���������
	//*ptrF1(); //��� �� ��������!
	(*ptrF1)(); //����� ������� F1 ����� � �����, ���������� � ��������� ptrF1, ����� ��� �������������
	ptrF1(); //����� ������� �� ��������� �� ��

	//��������� �� ������� � ���������� ���� ������ double � ������������ �������� ���� int
	int (*ptrF4)(double) = F4; //������������� ��������� �� �������, ��������� ��� �������
	cout << ptrF4(3.14) << endl; //����� ������� � ���������� � ������������ ��������� ����� ���������

	system("cls");

	void(*Pointer)(int) = F2;
	Pointer(5);
	Pointer = F3;  //� ��������� �� ������� ����� ��������� ����� ����� �������, ��� ���������(���������) ��� �������������
	Pointer(5);

	void(*ptrF2)(int) = F2;
	Pointer = ptrF2;  //� ��������� �� ������� ����� ��������� ���������� ������� ��������� �� �������(����� �������)
	//���� �� ��������� ���������
	Pointer(5);

	float A = 0.0F, B = 0.0F;
	char Key = '+';
	//������� ��������� �� �������
	float (*calc)(float, float) = nullptr;
	do
	{
		system("cls");
		cout << "---����� ������ � ���� �����������!---" << endl;
		cout << R"(
����������� �������� �� �������:
��������:                   A+B
���������:                  �-�
���������:                  �*�
�������:                    �/�
)";
		cin >> A >> Key >> B;
		switch (Key)
		{
		case '+':
			calc = Summa; //����������� ��������� ����� ������� �����
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
			Key = '0'; //���� ����� ������������
			break;
		}
		if (Key != '0')cout << "��������� �����: " << calc(A, B) << endl;
		cout << "��������� ����������(Y/N)? "; cin >> Key;
	} while (Key == 'Y' || Key == 'y');
}
*/

// MassivePointersFunctions
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;
//������� ����������� ������ ���������(BackEnd)
float Summa(float A, float B);
float Raznost(float A, float B);
float Proizvedenie(float A, float B);
float Chastnoe(float A, float B);

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
void Action0(float A, float B) //����������������� �������� �������
{
	cout << "0. �����..." << endl;
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