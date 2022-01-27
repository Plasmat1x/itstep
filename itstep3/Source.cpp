#include<iostream>
#include<cstdlib>
#include<cmath>

void calc();
void calc2();

int main() 
{
    system("chcp 1251");
    //�������?��������1:��������2
    //(A>B)?A:B

    /*
    int min = 0, max = 0, A = 0, B = 0;
    std::cout << "---min max---" << std::endl;
    
    std::cout << "enter A: "; std::cin >> A;
    std::cout << "enter B: "; std::cin >> B;

    max = (A > B) ? A : B;
    min = (A < B) ? A : B;

    std::cout << "min " << min << std::endl;
    std::cout << "max " << max << std::endl;

    if (A > B)
    {
        max = A;
        min = B;
    }
    else
    {
        max = B;
        min = A;
    }

    std::cout << "max " << max << " min " << min << std::endl;

    (A > B) ? std::cout << A << B << std::endl :
        std::cout << B << A << std::endl;

    switch (A)
    {
    case 1: std::cout << "1" << std::endl; break;
    case 2: std::cout << "2" << std::endl; break;
    case 3: std::cout << "3" << std::endl; break;
    case 4: std::cout << "4" << std::endl; break;
    }

    calc();
    */
    calc2();

    system("chcp 866");
    return 0;
}

void calc()
{
    system("cls");
    std::cout << "---calc prog---" << std::endl;
    double a = 0;
    double b = 0;

    char op;
    std::cout << "enter A: "; std::cin >> a;
    std::cout << "enter operation: "; std::cin >> op;
    std::cout << "enter B: "; std::cin >> b;
    switch (op)
    {
    case '+':
        std::cout << a + b << std::endl;
        break;
    case '-':
        std::cout << a - b << std::endl;
        break;
    case '*':
        std::cout << a * b << std::endl;
        break;
    case '/':
        std::cout << a / b << std::endl;
        break;
    case '^':
        std::cout << std::pow(a, b) << std::endl;
        break;
    case'V':
        std::cout << pow(a, 1/b) << std::endl;
    default: break;
    }

}

namespace mmath // minus global scope
{
    // namespace ��� ����������
    int i = 1;
    unsigned long int result;

    unsigned long int factorial(unsigned long int x)
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
}

void calc2()
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

    while(_iswork) // ������� ������������ ����� ���� _iswork = true ����� �������� ����
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
