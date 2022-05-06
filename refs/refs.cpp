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
	//������ �� �������� ���������� �
	int& ref_X = X; //������������� ������ ���������� �
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	X += 15;
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	ref_X += 15; //��� �������� ��� ������� ����������� ��� ����� ����������
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	int Y = 17;
	ref_X = Y; //������������ �������� ��������� Y ���������� X, �� ������ �� �� (ref_X)
	cout << "X= " << X << endl;
	cout << "ref_X= " << ref_X << endl;
	int& ref_Y = Y;
	ref_Y = 100;
	cout << "Y= " << Y << endl;
	ref_X = ref_Y; //X=Y; ������������ �������� ���������� Y, ������� �� ������ �� ��(ref_Y)
	//���������� �, �� ������ �� ��(ref_X)
	cout << "X= " << X << endl;
	ref_Y = 200;
	cout << "Y= " << Y << endl;
	cout << "X= " << X << endl;
	//������ ������ ��������� �� ���� � ��� �� ������
	//int& const cRefX = X; //������ ������ �������� ����������� ������
	const int& cRefX = X; //����������� ������ (������ �� ���������)
	//cRefX = -555;  //������, �� ������� ������ �������� �������� �������
	cout << "cRefX= " << cRefX << endl;
	X = 200;
	cout << "cRefX= " << cRefX << endl;
	system("cls");
	int Z = 150; //���������� Z
	int* ptr_Z = &Z; //��������� �� ���������� Z(������ ����� ���������� Z)
	int& ref_Z = Z;  //������ �� ��������� Z(���������) (��������� �� ��������)
	cout << "�������� ������� Z �� �����: " << Z << endl;
	cout << "�������� ������� Z ����� ���������: " << *ptr_Z << endl;
	cout << "�������� ������� Z �� ������: " << ref_Z << endl;
	system("cls");

	float* ptr = nullptr; //������� ���������, ����� ���� ������ �� �������� �������
	//���� ���� - ������������ ������� ���������(��������� ���� ����� ��������, �������� ������ ����)
	{
		float PI = 3.14F; //��������� ���������� ����� ����
		float& refPI = PI; //��������� ������ �� ���������� PI, ����� ���� ��������� ������ ����� �������� �������
		float* ptrPI = &PI; //��������� ��������� �� ���������� PI
		cout << "�������� ���������� PI �� �����: " << PI << endl;
		cout << "�������� ���������� PI ����� ���������: " << *ptrPI << endl;
		cout << "�������� ���������� PI �� ������: " << refPI << endl;
		ptr = &PI; //"�������" ������� ��������� �� ���������� PI
		cout << "�������� ���������� PI ����� ��������� ptr: " << *ptr << endl;
		cout << "����� ���������� PI ����� ��������� ptr: " << ptr << endl;
	}
	//cout << "�������� ���������� PI �� �����: " << PI << endl;
	//cout << "�������� ���������� PI ����� ���������: " << *ptrPI << endl;
	//cout << "�������� ���������� PI �� ������: " << refPI << endl;
	cout << endl;
	cout << "�������� ���������� PI ����� ��������� ptr: " << *ptr << endl;
	cout << "����� ���������� PI ����� ��������� ptr: " << ptr << endl;
	//��������� ptr ���������� ������� �����, ����� ����������� ������ �������
	//���� ������ ���������, �� ��������� ����� ��� "������������" �� ������ ������ ��� ��������
	ptr = nullptr;
	//������ ������������ ������� ���������!!!
	//if(ptr!=nullptr) // ���� ��������� �� �������
	if (ptr)cout << "�������� ���������� PI ����� ��������� ptr: " << *ptr << endl;
	cout << "����� ���������� PI ����� ��������� ptr: " << ptr << endl;
	system("cls");

	int M = 70;
	int* ptr_M = &M;
	int& ref_M = M;
	cout << ptr_M << endl;
	cout << &ref_M << endl;
	int* ptr_ref_M = &ref_M; //� ��������� ����� ������� ����� ���������� �, ������ �� ������
	cout << ptr_ref_M << endl;

	//������ �� ���������
	int*& ref_ptr_M = ptr_M; //������ �� int*

	cout << ref_ptr_M << endl; //������ ��� ��������� - ������ ��� ��������� ptr_M
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

//������� ���������� �������� ������������� �������� �������
int Max_Elem(int Array[], int Size)
{
	int index_max = 0; //������ ������������� ��������
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //������� ������ ������������� ��������
	}
	cout << "\n������������ ������� ������� �[" << index_max << "]=" << Array[index_max] << endl;
	return Array[index_max]; //���������� �������� ������������� �������� �������
}
//������� ���������� ����� ������������� �������� �������
int* Ptr_Max_Elem(int Array[], int Size)
{
	int index_max = 0; //������ ������������� ��������
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //������� ������ ������������� ��������
	}
	cout << "\n������������ ������� ������� �[" << index_max << "]=" << Array[index_max] << endl;
	//return &Array[index_max]; //���������� ����� ������������� �������� �������, � ������� ������ ������
	return Array + index_max; //���������� ����� ������������� �������� �������, � ������� ��������
	//������ (�� ��������� Array) �� ������ ������� �� ������ ������������� ��������
}

//������� ���������� ������ �� ������������ ������� �������
int& Ref_Max_Elem(int Array[], int Size)
{
	int index_max = 0; //������ ������������� ��������
	for (int i = 1; i < Size; i++)
	{
		index_max = Array[i] > Array[index_max] ? i : index_max; //������� ������ ������������� ��������
	}
	cout << "\n������������ ������� ������� �[" << index_max << "]=" << Array[index_max] << endl;
	return Array[index_max]; //���������� ������ �� ������������ ������� �������
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
	int Max = Max_Elem(Array, Size); //�������� � ���������� ��������� ������ �������
	cout << "�������� ����. ��������: " << Max << endl;

	Max = *Ptr_Max_Elem(Array, Size); //�������� ��������� ������ ������� � ����������, ����������� ���������, ������������ ��������
	cout << "�������� ����. ��������: " << Max << endl;

	//*Ptr_Max_Elem(Array, Size) = -1000; //�������� �� ������(���������� ������ �������) ����� ��������,
	//����������� ���������, ������������ �������� / �� �������� �������� ������������� �������� �� -1000

	Max = Ref_Max_Elem(Array, Size); //�������� � ���������� ��������, ������ �� ������, ������� ���������� �������
	cout << "�������� ����. ��������: " << Max << endl;
	Ref_Max_Elem(Array, Size) = -1000; //�������� ����� �������� � ������������ ������� �� ������ �� ����, ������� ���������� �������


	for (int i = 0; i < Size; i++)
	{
		cout << "A[" << i << "]=" << Array[i] << "; ";
	}

}

*/
}

