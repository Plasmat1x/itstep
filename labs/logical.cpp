#include <iostream>
#include <cstdlib>
#include <cmath>

void radius()
{
    system("cls");
    std::cout << "---��������� ����������� �������������� ����� ������!---" << std::endl;
    float R1 = 0.0F, R2 = 0.0F, X0 = 0.0F, Y0 = 0.0F, x = 0.0F, y = 0.0F, L = 0.0F, a = 0.0F, b = 0.0F;

    //�,� - ���������� �����
    //X0,Y0 - ���������� ������ ������
    //R1 - ���������� ������ ������
    //R2 - ������� ������ ������
    //L - ��������� �� ����� �� ������ ������
    //a,b - ���������� ����� �� ������ �� ���� X � Y
    std::cout << "������� ���������� ������ ������: " << std::endl;
    std::cout << "X0: "; std::cin >> X0;
    std::cout << "Y0: "; std::cin >> Y0;
    std::cout << "Radius's: " << std::endl;
    std::cout << "inner: "; std::cin >> R1;
    std::cout << "outer: "; std::cin >> R2;

    if ((R1 < 0) && (R2 < 0) && (R2 < R1)) // ������� �������� �� ����������� �������� ������ ���� ���������� ������ ������
    {
        std::cout << "Error:: R1 or R2 less than zero, or R2 less than R1" << std::endl;
        return;
    }

    std::cout << "������� ���������� �����: " << std::endl;
    std::cout << "x: "; std::cin >> x;
    std::cout << "y: "; std::cin >> y;
    a = x - X0;
    b = y - Y0;
    L = sqrtf(powf(a, 2) + powf(b, 2));

    if ((R1 <= L) && (L <= R2))
        std::cout << "Coords (" << x << "; " << y << ") included into ring" << std::endl;
    else 
        std::cout << "Coords (" << x << "; " << y << ") not included into ring" << std::endl;

    system("pause");
    return;
}

void _transport()
{
    system("cls");
    int cash = 0;

    std::cout << "<-��������� ������ ����������->" << std::endl;
    std::cout << "\n������� ����� ����� � �������: " << std::endl; std::cin >> cash;

    //��� ������ ���� ��������� ���������� ��� ����������� (���������� ��� ������� ����������� ��������� ��� �� �� ����� � ������� ����)

    if (cash == 0)
    {
        std::cout << "�������� ����" << std::endl;
    }
    else if (cash >= 25 && cash < 35)
    {
        std::cout << "�������� �������" << std::endl;
    }
    else if (cash >= 35 && cash < 125)
    {
        std::cout << "�������� �������" << std::endl;
    }
    else if (cash >= 125)
    {
        std::cout << "�������� �����" << std::endl;
    }
    else
    {
        std::cout << "������ ����� ������ 0" << std::endl;
        system("pause");
        return;
    }

    system("pause");
    return;
}

int main(int argc, char* argv[])
{
    system("chcp 1251");
    //---------------------------------

    // < > >= <= == != - ��������� ��������� � ���������

    // &&(and) ||(or) !(not) - ��������� ����������� � ��������

    // if() ������� 
    
    bool result = false;
    result = 10 > 11;
    std::cout << result << std::endl; // output 0

    bool bA, bB, bC;
    bA = bB = bC = false;
    
    //...
    //process var bA bB bC
    //...

    if (!bA != (bB && bC)) // ������� � ����������� ���������� �����������
    {
        //if do
    }
    else
    {
        //else do
    }

    system("pause");
    _transport();
    radius();

    //---------------------------------
    system("chcp 866");
    return 0;
}