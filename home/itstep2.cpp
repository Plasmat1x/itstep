#define _USE_MATH_DEFINES

#include <iostream>
#include <locale>
#include <cstdlib>


//using namespace std;

int main(int argc, char* argv[])
{
    //setlocale(LC_ALL, "rus");
    system("chcp 1251"); //������ setlocale (�� ����� ������ ��� ������ ��������)
    system("cls");

    const double PI = 3.1415926535; //��������� ���� double
    const float sPI = 3.14;
    double weght_atom = 2.5194e-17; // 0.000000000000000025194
    float somef = 2.25e+2;

    int _a; //���������� ��������� _a ���� int 
    /*
    int _b = 0; �������������
    int _b(0);
    int _b = {0};
    int _b{0};

    int _b; //����������
    _b = 0; //������������
    */

    std::cout << "����� ��: \t" << PI << std::endl;
    std::cout << "����� �����: " << weght_atom << std::endl;
    std::cout << "���������� somef = " << somef << std::endl;

    system("pause");
    system("cls");
    
    //� ��������� �����(���)
    {
        int A;
        int B;
        int S;

        A = 0;
        B = 0;
        S = 0;

        std::cout << "--��������� ��� ���������� ������� ��������������--" << std::endl;
        std::cout << "������� ����� ������� A: "; std::cin >> A;
        std::cout << "������� ����� ������� B: "; std::cin >> B;

        //S = A * B ������� ��������������
        S = A * B;

        std::cout << "���������, ������� ��������������: S = " << S << std::endl;
        system("pause");
        system("cls");
    };

    /*
    //������ ����� 
    //����� �� ������� �������� ������� ����� ������ ����� ���������������(�����������������)
    //
    //             Please Login With Admin Credentials!
    //              ===================================
    //              +   [=] Enter Username:1          +   ����� ��������� ���� ������
    //              +   [=] Enter Password:2          +
    //              ===================================
    //
    //���:
    //-----------------------------------------------------------------------------
    #include <string>
    std::string something, something2;

    std::cout << "                 Please Login With Admin Credentials!" << std::endl;
    std::cout << "                  ===================================" << std::endl;
    std::cout << "                  +   [=] Enter Username:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something;

    std::cout << "                  +   [=] Enter Password:           +";

    for (int i = 1; i <= 12; i++) {
        std::cout << '\b'; // ---------- backspace 12 times
    }
    std::cin >> something2;

    std::cout << "                  ===================================" << std::endl;

    //-----------------------------------------------------------------------------

    //���������� ������� ����� � escape-������������������� �������/backspace
    //*/

    system("chcp 866"); // �� ����� ������������ ��� ������ �������������
    system("cls");
    //week 2.1 task 3
    {
        /* //����� �������� � ���������
        for (int i = 179; i < 219; i++)
        {
            std::cout << i << "\t:\t" << char(i) << std::endl;
        }
        */

        //����� ������� � ��������� ������������� (�� �������� ��� ������������� setlocale(LC_ALL, "rus"))
        std::cout << char(201); for (int i = 0; i < 95; i++) { std::cout << char(205); }; std::cout << char(187) << std::endl;
        std::cout << char(186) << "\t\t\t\t\t\tSeasons\t\t\t\t\t\t" << char(186) << std::endl;
        std::cout << char(204);
        for (int i = 1; i < 96; ++i)
        {
            if (i % 24)
            {
                std::cout << char(205);

                continue;
            }
            std::cout << char(203);
        };
        std::cout << char(185) << std::endl;

        std::cout << char(186) << "\tautumn\t\t" << char(186) << "\twinter\t\t" << char(186) << "\tspring\t\t" << char(186) << "\tsummer\t\t" << char(186) << std::endl;

        std::cout << char(200);
        for (int i = 1; i < 96; ++i)
        {
            if (i % 24)
            {
                std::cout << char(205);

                continue;
            }
            std::cout << char(202);
        };
        std::cout << char(188) << std::endl;

        system("pause");
        system("cls");
    };

    system("chcp 1251");
    system("cls");
    //week 2.2 task 1
    {

        std::cout << "--��������� ����������� ���������� �����--" << std::endl;
        std::cout << "������� ���: ";
        int* a = new int(0); // year 
        std::cin >> *a;
        /*
        ��� �������� ���������� � ���� �������:
        ���� �� ������ 4, �� ��� ���� �� ������ 100,
        ���� ������ 400
        */
        std::cout << "In " << *a << " year" << " = " << 365 + (int)((*a % 4 == 0 && *a % 100 != 0) || (*a % 400 == 0)) << " days" << std::endl;
        
        delete a;

        system("pause");
        system("cls");
    };

    //week 2.2 task 2
    {
        int rub; // �����
        int cent; // �������

        std::cout << "--��������� ��������� ����� ������--" << std::endl;
        std::cout << "������� �����: "; std::cin >> rub;
        std::cout << "������� �������: "; std::cin >> cent;

        if (cent >= 100)
        {
            rub += int(cent / 100);
            cent %= 100;
        }

        std::cout << "���������: " << rub << " ���. " << cent << " ���. " << std::endl;

        system("pause");
        system("cls");
    };
    
    //week 2.2 task 3
    {
        std::cout << "--��������� ���������� ������ ��������������--" << std::endl;
        float* a = new float(0.f);//�����
        float* b = new float(0.f);//������
        float* h = new float(0.f);//������
        float* v = new float(0.f);//�����

        std::cout << "����� (��) -> "; std::cin >> *a;
        std::cout << "������ (��) -> "; std::cin >> *b;
        std::cout << "������ (��) -> "; std::cin >> *h;

        //V = a*b*h
        *v = (*a) * (*b) * (*h);

        std::cout << "�����: " << *v << " ���. ��." << std::endl;

        delete a;
        delete b;
        delete h;
        delete v;

        system("pause");
        system("cls");
    };

    //week 2.2 task 4
    {
        std::cout << "--��������� ���������� ��������� ����� ����� ��������� �� �����--" << std::endl;
        float* a = new float(0.f);//�������
        float* b = new float(0.f);//���������� ����� ������� �� �����
        float* c = new float(0.f);//���������� ����� ���������

        std::cout << "������� �������� ������:" << std::endl;
        std::cout << "\t������� ����� (���������� ���������� � ����� ����������) -> "; std::cin >> (*a);
        std::cout << "\t��������� ����� ������� �� ����� (��) -> "; std::cin >> (*b);
        //��������� = ������� * ��������� �� �����(��)
        (*c) = (*a) * (*b);
        std::cout << "\t��������� ����� ��������� " << (*c) << " ��." << std::endl;


        delete a;
        delete b;
        delete c;
        system("pause");
        system("cls");
    };

    //week 2.2 task 5
    {
        #include <cmath>
        std::cout << "--��������� ���������� ������ ����--" << std::endl;
        float r = 0.f;
        std::cout << "������� ������ -> "; std::cin >> r;
        //V = (3/4) * (PI * r * r * r))
        std::cout << "����� ����: " << double((4.f / 3.f) * (M_PI * r * r * r)) << " ���. ��." << std::endl;

        system("pause");
        system("cls");
    };

    system("chcp 866");
    system("cls");
    system("pause");

    return EXIT_SUCCESS;
}