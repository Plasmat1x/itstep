// TicTacToe
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h> //���������� ��� ������ � ������ �������
#define SPACE ' '

using namespace std;
//������� �������� ���� 3�3 ��� ���� X/O - ���������� ��������� ������ ��������
char Matrix[3][3] =
{
	SPACE,SPACE,SPACE,
	SPACE,SPACE,SPACE,
	SPACE,SPACE,SPACE
}; //���������� ������� �������

//�������� ������� ������ �������� ���� �� �����
void Display();
//�������� ������� ���� ������ X/O
void Player_Move(char);
//�������� ������� ���� ����������
void PC_Move();
//�������� ������� ����������� ����������
char Check();

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));
	int Game = 0;		//����� �������� ����
	int Count = 0;		//������ �����
	char Winner = SPACE;	//��� ����������� ����������
	char Answer = SPACE;	//����� �� ������ � ����������� ����
	do //���� ��������� ����
	{
		//��������� ����
		cout << "---���� � ��������-������!---" << endl;
		//���� ����
		cout << R"(�������� ��� ����:
1 - ��������� ����(������ ����������)
2 - �����������(���� ������ ������)
0 - ����� �� ����
)";
		do //���� �������� ����� ���� ����
		{
			cin >> Game;
			if (Game < 0 || Game>2)cout << "������� ������ ��� ����! ��������� ����!" << endl;
		} while (Game < 0 || Game>2);
		if (Game == 0)break; //����� �� ����(����� �� ����� ��������� ����)
		system("cls");
		if (Game == 1)cout << "��������� ����!" << endl;
		else cout << "�����������!" << endl;
		do //���� �����
		{
			//�������� ��� �
			Display();					//����� �������� ���� ����� ����� ������ �
			Player_Move('X');			//��� ������ �
			Count++;					//����������� ������� �����
			if (Count >= 5)Winner = Check();	//�������� ������ �
			if (Winner != SPACE)break;		//���� ���� ����������� ������� ��������, �� ����� �� ����� �����
			if (Count == 9)break;			//���� ���� ����������� �� �����(�����)
			//�������� ��� O
			if (Game == 1)PC_Move();	//���� ��������� ����, �� ��� ����������
			else
			{
				Display();				//����� �������� ���� ����� ����� ������ O
				Player_Move('O');		//��� ������ O
			}
			Count++;					//����������� ������� �����
			if (Count >= 6)Winner = Check();	//�������� ������ O
		} while (Winner == SPACE); //����� ���� �� ������ ����������
		Display();				//����� �������� ���� �� ��������� ����
		//����������� ���������� ����
		if (Winner != SPACE)cout << Winner << " �������!!!" << endl;
		else cout << "�����!!!" << endl;
		//������ � ��������� ����
		cout << "������� ��� ���(Y/N)? "; cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			//���������� � ��������� ����
			//������� �������� ����
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Matrix[i][j] = SPACE;
				}
			}
			//����� ����������
			Winner = SPACE;
			//�������� ������� �����
			Count = 0;
			//������� ������
			system("cls");
		}
		else Game = 0;//����� ����� �� ����
	} while (Game != 0);
	cout << "��� ������ ������� ����� �������..." << endl;
	//cin >> Answer;
	_getch(); //������ ����� ������ �������	
}
//���������� ������� ������ �������� ���� �� �����
void Display()
{
	for (int i = 0; i < 3; i++)
	{
		cout << " " << Matrix[i][0] << " | " << Matrix[i][1] << " | " << Matrix[i][2] << endl;
		if (i != 2)cout << "---|---|---" << endl; //����� ������ ������ ����� ���������
	}
}
//���������� ������� ���� ������ X/O
void Player_Move(char Symbol) //Symbol - ������ ������ ������ ��������� ���(X/O)
{
	int x = 0, y = 0; //���������� ������ ����
	do //���� ����������������� �����
	{
		cout << "���� ��������� " << Symbol << " ?" << endl;
		cout << "������  �����: "; cin >> x;
		cout << "������� �����: "; cin >> y;
		x--; y--; //������������� ����������������� ����� ��� ������ � ���������� ������� �� ��������
		if (x < 0 || x>2 || y < 0 || y>2)cout << "������ ���� �� ����������! ��������� ����!" << endl;
		else
			if (Matrix[x][y] != SPACE)cout << "���� ��� ������! �������� ������ � ��������� ����!" << endl;
	} while (x < 0 || x>2 || y < 0 || y>2 || Matrix[x][y] != SPACE);
	Matrix[x][y] = Symbol; //� ��������� ������ �������� ������ ������, ��� ���(��� ���� ������� ��������)
}
//���������� ������� ���� ����������
void PC_Move()
//void PC_Move(char Symbol)
{
	int i = 0, j = 0; //������� ������� �������
	do //���� �������� ���� ����������
	{
		//����� �������� "������������ ���������"
		i = rand() % 3; //��������� ������� �� 0 �� 2
		j = rand() % 3; //��������� ������� �� 0 �� 2		
	} while (Matrix[i][j] != SPACE);
	cout << "��� ����������: " << i + 1 << ";" << j + 1 << endl;
	Matrix[i][j] = 'O'; //�������� � ������ ������ 0
	//Matrix[i][j]=Symbol;
}
//���������� ������� ����������� ����������
char Check()
{
	//�������� �� �������
	for (int i = 0; i < 3; i++)
	{
		//���� ��� ��� ������ ����� ������ ����� ���������� ���������� � ��� �� ������, �� ������� ��� ���������� ��� ����������
		if (Matrix[i][0] == Matrix[i][1] && Matrix[i][1] == Matrix[i][2] && Matrix[i][0] != SPACE)return Matrix[i][0];
	}
	//�������� �� ��������
	for (int j = 0; j < 3; j++)
	{
		//���� ��� ��� ������ ������ ������� ����� ���������� ���������� � ��� �� ������, �� ������� ��� ���������� ��� ����������
		if (Matrix[0][j] == Matrix[1][j] && Matrix[1][j] == Matrix[2][j] && Matrix[0][j] != SPACE)return Matrix[0][j];
	}
	//�������� �� ������� ���������
	if (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])return Matrix[1][1];
	//�������� �� �������� ���������
	if (Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])return Matrix[1][1];
	//���� ���������� �� ������, �� ������ ������
	return SPACE;
}