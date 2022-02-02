#include "calc.h"

#include <iostream>
#include <cstdlib>

// namespace ��� ����������
int i = 1;
unsigned long int result = 0;

unsigned long int mmath::factorial(unsigned long int x)
{
    if (x == 1 || x == 0)   // ������� ���������� ��������
        return 1;           // ����� ���������� ������� ��� ���� �� ����������� -> �������� �����������
    else
    {
        i++;
        result = x * factorial(x - 1);
    }
    return result;
}

void m_calc::calc20()
{
    system("cls");
    std::cout << "---calc2 prog---" << std::endl;
    double a = 0;
    double b = 0;
    char op;
    std::cout << "enter number: "; std::cin >> a;

    bool _iswork = true; // ���� ��� ������ �� �����;

    /*
    X - to stop cycle;

    ���� ������� ������� � ����������� ���������� �������� ���� ������������ �� �������� ��������� ����� ��������
    */

    while (_iswork) // ������� ������������ ����� ���� _iswork = true ����� �������� ����
    {
        //system("cls");
        std::cout << "resault: " << a << std::endl;
        std::cout << R"(
'+' - ��������
'-' - ���������
'*' - ���������
'/' - �������
'^' - ����� � � ������� �
'V' - ������ �-�� ������� �� �
'!' - ��������� ����� �
'%' - ������� ������� ����� � �� ����� B
)" << std::endl;
        std::cout << "enter operation: "; std::cin >> op; // ��� ����� +3 ����������� ���������

        switch (op)
        {
        case '+': //�������� b
            std::cout << "enter number: "; std::cin >> b;
            a += b;
            std::cout << a << std::endl;
            break;
        case '-': //��������� b
            std::cout << "enter number: "; std::cin >> b;
            a -= b;
            std::cout << a << std::endl;
            break;
        case '*': //��������� �� b
            std::cout << "enter number: "; std::cin >> b;
            a *= b;
            std::cout << a << std::endl;
            break;
        case '/': //������� �� b
            std::cout << "enter number: "; std::cin >> b;
            if (b == 0) { std::cout << "error div 0 imposible" << std::endl; break; }
            a /= b;
            std::cout << a << std::endl;
            break;
        case '^': //���������� � ������� b
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, b);
            std::cout << a << std::endl;
            break;
        case '%': //�������� �� ������� �� b
            std::cout << "enter number: "; std::cin >> b;
            a = int(a) % (int)b;
            std::cout << a << std::endl;
            break;
        case 'v':
        case'V': //������ ������� b �� �����
            std::cout << "enter number: "; std::cin >> b;
            a = std::pow(a, 1.0 / b);
            std::cout << a << std::endl;
            break;
            //*
        case'!': //��������� ����� a
            //�������_��������(a);
            a = mmath::factorial(a);
            std::cout << a << std::endl;
            break;
            //*/
        case 'x':
        case'X':
            _iswork = false; //������� ������ �� �����
            break;
        default:
            std::cout << "wrong operation!" << std::endl;
            break;
        }
    }
}