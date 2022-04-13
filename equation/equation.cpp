// Equation
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

using namespace std;
//������� ������� ����������� ��������� � ��������� ���������, ���
//�������� ������ ����������� ���������, ���������� ���-�� ������
//int Uravnenie(double a, double b, double c) //������ �������
int Uravnenie(double b, double c, double a = 0.0) //������ ������� � ���������� �� ���������
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    if (a == 0.0) //���� ��������� ��������
    {
        //bx+c=0
        x1 = -c / b;
        cout << "x1= " << x1 << endl;
        return 1; //���������� ���-�� ������
    }
    else //����� ��������� ����������
    {
        D = (b * b) - 4 * a * c;
        if (D < 0) //���� ��� �������������� ������
        {
            cout << "��� �������������� ������!" << endl;
            return 0;
        }
        else
            if (D == 0) //��� ���������� �����
            {
                x1 = (-b) / (2 * a);
                //x2=x1;
                cout << "x1=x2= " << x1 << endl;
                return 20;
            }
            else //��� ������ �����
            {
                x1 = ((-b) - sqrt(D)) / (2 * a);
                x2 = ((-b) + sqrt(D)) / (2 * a);
                cout << "x1= " << x1 << "\nx2= " << x2 << endl;
                return 2;
            }
    }
}
//������� ������� ��������� ���������
inline double Equation(double k, double b) //����� ������� ������� ����� ������� ������������
{
    //kx+b=0
    cout << "x= " << -b / k << endl;
    return -b / k;
}
//���������� ������� ��� ������� ���������� ���������
int Equation(double a, double b, double c)
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    D = (b * b) - 4 * a * c;
    if (a == 0)Equation(b, c);
    else
        if (D < 0) //���� ��� �������������� ������
        {
            cout << "��� �������������� ������!" << endl;
            return 0;
        }
        else
            if (D == 0) //��� ���������� �����
            {
                x1 = (-b) / (2 * a);
                //x2=x1;
                cout << "x1=x2= " << x1 << endl;
                return 1; //��� ���������� �����
            }
            else //��� ������ �����
            {
                x1 = ((-b) - sqrt(D)) / (2 * a);
                x2 = ((-b) + sqrt(D)) / (2 * a);
                cout << "x1= " << x1 << "\nx2= " << x2 << endl;
                return 2; //��� ������ �����
            }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choise = 0;
    double a = 0.0, b = 0.0, c = 0.0;
    do //���� ��������� ����������
    {
        cout << R"(---��������� ��� ������� ���������!---
1 - �������� ��������� (kx+b=0)
2 - ���������� ��������� (ax^2+bx+c=0)
0 - ����� �� ���������
)";
        do //���� ����������������� �����
        {
            cout << "�������� ��� ���������: "; cin >> choise;
            if (choise < 0 || choise>2)cout << "������� ������ ��� ���������! ���������� ��� ���!" << endl;
        } while (choise < 0 || choise>2);
        if (choise == 0)break; //����� �� ���������(�� ����� ��������� ����������)
        switch (choise)
        {
        case 1:
            //a = 0.0; //�������� �, ���� ����� ���� ������ ���������� ���������, ��� ������� ��������
            cout << "������� ����������� k: "; cin >> b;
            cout << "������� ����������� b: "; cin >> c;
            //Uravnenie(a, b, c);//Uravnenie(0.0, b, c); //������ �������
            //Uravnenie(b, c); //������ ������� � ���������� �� ���������
            Equation(b, c);
            break;
        case 2:
            cout << "������� ����������� a: "; cin >> a;
            cout << "������� ����������� b: "; cin >> b;
            cout << "������� ����������� c: "; cin >> c;
            //Uravnenie(a, b, c); //������ �������
            //Uravnenie(b, c, a); //������ ������� � ���������� �� ���������
            Equation(a, b, c);
            break;
        }
        system("pause");
        system("cls");
    } while (choise != 0);
    cout << "�����..." << endl;
    Sleep(1500);
}
