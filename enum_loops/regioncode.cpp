#include "regioncode.h"

#include <iostream>

void reg::regioncode()
{
    std::cout << "---prog region code---" << std::endl;

    int code = 0;
    std::cout << "enter code "; std::cin >> code;

    enum Regions
    {
        Chel = 74,
        Chel1 = 174,
        Chel2 = 774,

        Ekb = 66,
        Ekb1 = 96,
        Ekb2 = 166,
        Ekb3 = 196,

        Tom = 70,
        Alt = 22,
        Dag = 05,
        Kem = 42,
        Ksn = 124,
        Tyv = 17,

        Vld = 25,
        Vld1 = 125


        //home
        //msk reg
        //msk obl reg
        //spb reg
    };

    switch (code)
    {
        //�� ����� 
    case Regions::Ekb:
    case Regions::Ekb1:
    case Regions::Ekb2:
    case Regions::Ekb3:
        std::cout << "������������ �������!" << std::endl;
        break;

    case Regions::Chel:
    case Regions::Chel1:
    case Regions::Chel2:
        std::cout << "����������� �������!" << std::endl;
        break;

    case Regions::Vld:
    case Regions::Vld1:
        std::cout << "���������� ����!" << std::endl;
        break;

    case Regions::Tom:
        std::cout << "������� �������!" << std::endl;
        break;
    case Regions::Alt:
        std::cout << "��������� ����!" << std::endl;
        break;
    case Regions::Dag:
        std::cout << "���������� ��������!" << std::endl;
        break;
    case Regions::Kem:
        std::cout << "����������� �������!" << std::endl;
        break;
    case Regions::Ksn:
        std::cout << "������������ ����!" << std::endl;
        break;
    case Regions::Tyv:
        std::cout << "���������� ����!" << std::endl;



    default:
        std::cout << "region not found!" << std::endl;
        std::cout << "buy premium edition!" << std::endl;
        break;
    }

}