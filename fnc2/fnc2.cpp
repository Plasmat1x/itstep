// Functions2.0
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
//������� �������� �������� ���� ���������� �������
void Swap(int One, int Two)
{
	//One � Two - ����� ��������� � � �
	//int One=A, Two=B; 
	cout << "�������� ������� Swap!" << endl;
	cout << "������ �����: " << One << " ������ ����� " << Two << endl;
	//�������� ���������� ���������� �������
	int temp = One; //temp - ����� ��� ������ �������� �������
	One = Two;
	Two = temp;
	cout << "������ �����: " << One << " ������ ����� " << Two << endl;
	cout << "������� Swap ��������� ������!" << endl;
}
//������� �������� ���-�� ������ ��������� �������
int CountEvenElements(int Array[], int Size)  //int count_even_elements() //int Count_Even_Elements()
{
	int Count = 0; //���-�� ������ ���������
	for (int i = 0; i < Size; i++)
	{
		if (Array[i] % 2 == 0)
		{
			Count++;
			cout << Array[i] << " ";
		}
	}
	cout << endl;
	return Count; //���������� ���-�� ������ ���������
}
//�������� ������� ������ ������������� ���������
int NegativeElements(int Massive[], int Count);

//���������� ��������� ��� ������� ������� �������
const int Row = 10;
const int Col = 6;

//������� ���������� ����� ���� ��������� ���������� �������
//int SummaAllElements(int Array[][6],int Row,int Col) //����������� ����� ������� ���-�� ��������� � ������
//int SummaAllElements(int Array[][Col]) //��������� ��� ����� ���������� ���������, ����� ������� �� ���������� ��������
int SummaAllElements(int Array[Row][Col]) //�������� ���-�� ����� Row ����� �� ���������
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
	//cout << "����� �: " << A << " ����� �: " << B << endl;
	//cout << endl;
	//Swap(A, B); //��� ������ ������� � ������� ���������� ��������, � �� ���� ����������
	//cout << endl;
	//cout << "����� �: " << A << " ����� �: " << B << endl;

	//const int Size = 50;
	//int Array[Size]{};
	//int Result = 0; //������ ��������� ������ �������
	//for (int i = 0; i < Size; i++)
	//{
	//	//if(i%10==0&&i!=0)cout<<endl; //������� ������ ����� ������� �������� �������� (����� ��������� � �������� 10)
	//	Array[i]=rand()%(100-(-99))-99;
	//	if (Array[i] >= 0)cout << " ";
	//	if (Array[i] > -10 && Array[i] < 10)cout << " ";
	//	cout << Array[i] << " ";
	//	if ((i+1)%10==0)cout << endl; //������� ������ ����� ������� �������� �������� (����� �������� � �������� 9)
	//}
	//cout<<"\n"<<endl;
	//Result=CountEvenElements(Array, Size); //�������� ��������� ������ ������� � ����������
	//cout<<"���-�� ������ ��������� �����: "<<Result<<endl;
	//Result = NegativeElements(Array, Size); //�������� ��������� ������ ������� � ����������
	////��� ������ ������� � ������� � �������� ���������, ������ � ������� ���� � �������� ��������, �� ���� � ����� Array
	//cout << "���-�� ������������� ��������� �����: " << Result << endl;
	//for (int i = 0; i < Size; i++)
	//{		
	//	if (Array[i] >= 0)cout << " ";
	//	if (Array[i] > -10 && Array[i] < 10)cout << " ";
	//	cout << Array[i] << " ";
	//	if ((i + 1) % 10 == 0)cout << endl; //������� ������ ����� ������� �������� �������� (����� �������� � �������� 9)
	//}
	//cout << "\n" << endl;

	//const int Row = 10;
	//const int Col = 6;
	int Mass[Row][Col]{};
	//� ������ [] ����������� ���-�� �����, � �� ������ [] ���-�� ��������� � ������ ������
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
	cout << "����� ���� ��������� ������� �����: " << Summa << endl;
}

//���������� ������� ������ ������������� ���������
int NegativeElements(int Massive[], int Count)
{
	//Massive ��������� ��� "���������" ��� Array
	int CountNegative = 0; //���-�� ������������� ���������
	for (int i = 0; i < Count; i++)
	{
		if (Massive[i] < 0)
		{
			CountNegative++; //������� ����-� ������������� ���������
			//���� ������� ������, �� ������� ��� �� ����
			if (Massive[i] % 2 == 0)Massive[i] = 0;
			else Massive[i] = -Massive[i]; //����� ������� ���� � ������ �� ����
		}
	}
	return CountNegative; //���������� ���-�� ������������� ���������
}