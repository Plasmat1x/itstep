// Struct
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//����������� ���������, ���������� ����
struct Date //Date - ��� ������ ���� ������
{
    unsigned short Day;  //����
    char Month[12];      //�����
    int Year;            //���
}Today = { 22,"���",2022 }; //�������� ����������� ������� ���� Date
//������� ������ �� �����
void Show(Date D)
{
    //�������� .  - �������� ������� � ����� ���������
    cout << D.Day << "." << D.Month << "." << D.Year << endl;
}

Date My_Birthday; //���������� ������ ���������, ���������������� ���� �� ���������

//������� �������� ���������� �� ���
bool IsLeapYear(int CheckYear)
{
    //��� �� ���������� ����
    if (CheckYear % 4 != 0 || (CheckYear % 100 == 0 && CheckYear % 400 != 0))return false;
    //���� ������� ������ �� ��� �����������
    return true;
}

//������� ����� ���� � ����������, ��������� ����� ������� ���� ������ Date � �������� ��� � ��������� �� ��� ������ Date
void Input(Date* PTR)
{
    //cout << "������� ����:" << endl;
    cout << "������� ����: "; cin >> PTR->Day; //PTR->Day ��������� � ���� Day ����� ��������� PTR �� ��� ������ Date
    cout << "������� �����: "; cin >> PTR->Month; //-> �������� ������� � ���� ��������� �� ���������(��������)
    cout << "������� ���: "; cin >> PTR->Year;
}
//���������� ������� Input, ������������ ������ ���� ������ Date
Date Input()
{
    //��������� ��������� ������ ������
    Date Temp{};
    cout << "������� ���� ����� ������� ��� Enter: " << endl;
    //���� �������� � ������ ����� �������� .
    cin >> Temp.Day >> Temp.Month >> Temp.Year;
    return Temp; //���������� ������ ���� ������ Date

}

int main()
{
    system("chcp 1251");
    system("cls");
    //������� ������ ���� ������ Date(��������� ��������� Date)
    Date May9 = { 9,"���",1945 };; //�������������� ������������� ������� ���������
    //cout << May9 << endl;
    Date Yesterday{}; //������ ������ ���� Date
    Yesterday = { 21,"���",2022 }; //������������ ������ ��������
    cout << Yesterday.Day << "." << Yesterday.Month << "." << Yesterday.Year << endl;
    Yesterday.Year = 2020; //������ � ���� ��������� �� ����� ����
    system("cls");
    Show(May9); //����� ������� � ��������� ������� ���� ������ Date � �������� ���������
    Show(Yesterday);
    Show(My_Birthday);
    Show(Today);
    system("cls");
    if (IsLeapYear(Yesterday.Year))//����� ������� � ��������� ���� ���� ������� Date � �������� ���������
        cout << Yesterday.Year << " ��� - ����������!" << endl;
    else cout << Yesterday.Year << " ��� - ������������!" << endl;
    if (IsLeapYear(Today.Year))//����� ������� � ��������� ���� ���� ������� Date � �������� ���������
        cout << Today.Year << " ��� - ����������!" << endl;
    else cout << Today.Year << " ��� - ������������!" << endl;
    system("cls");
    //cout << &Today << endl; //������ ������ ������� ���� ������ Date
    cout << "������� ���� ��������: " << endl;
    Input(&My_Birthday); //����� ������� � ��������� ������ �������
    cout << "������� ������� ����: " << endl;
    Today = Input(); //����� ������� ������������ ������ � ���������� ����� ������
    //if(Today.Day==My_Birthday.Day&&Today.Year==My_Birthday.Year&&!strcmp(Today.Month,My_Birthday.Month)) //������ ��������� ����
    if (Today.Day == My_Birthday.Day && !_stricmp(Today.Month, My_Birthday.Month))
        cout << "����������� � ���� ��������!" << endl;
    else cout << "����� ����, �� ������� �� ��� ���� ��������!" << endl;

}