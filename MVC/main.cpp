#include <iostream>
#include <iomanip>
#include <locale>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    //������� 1
    std::cout << "������ �� ����� \"��������������\", ����������� HTP" << std::endl;
    std::cout << std::endl
        << "�������������� - �������� �������\n"
        << "����� ��, �� ������������ �� ���\n"
        << "��������� �� ����������, ��� ��������� ����\n"
        << "������ ������� � ������ ������ \"���\"\n"
        << "���-���-��� �����������\n"
        << "���-���-��� �����������\n"
        << "���-���-��� �����������\n"
        << "���-���-��� �����������\n"
        << std::endl;


    //������� 2
    std::cout << "������ ������� ������ ����� ��� ����� �����." << std::endl;
    std::cout
        << "� - ������� - (������)\n"
        << "\t� - ��������� - (�������)\n"
        << "\t\t� - ������ - (������)\n"
        << "\t\t\t� - ������� - (�����)\n"
        << "\t\t\t\t� - ������� - (���)\n"
        << "\t\t\t\t\t� - ����� - (�����)\n"
        << "\t\t\t\t\t\t� - ���������� - (�����)\n"
        << std::endl;

    //������� 3
    std::cout << "|" << std::setfill('=') << std::setw(20) << "|" << std::endl;
    std::cout << "|" << std::setfill(' ') << std::setw(19) << "������ ������ ���" << "|" << std::endl;
    std::cout << "|" << std::setfill(' ') << std::setw(19) << "�.8(800)-555-35-35" << "|" << std::endl;
    std::cout << "|" << std::setfill('=') << std::setw(20) << "|" << std::endl;
    std::cout << std::setfill(' ');
    for (int str = 0; str < 6; str++)
    {
        for (int tab = 0; tab < 5; tab++)
        {
            switch (str)
            {
            case 0:
            {
                std::cout << "|" << std::setw(3) << "8";
                break;
            }
            case 1:
            {
                std::cout << "|" << std::setw(3) << "800";
                break;
            }
            case 2:
            {
                std::cout << "|" << std::setw(3) << "555";
                break;
            }
            case 3:
            {
                std::cout << "|" << std::setw(3) << "35";
                break;
            }
            case 4:
            {
                std::cout << "|" << std::setw(3) << "35";
                break;
            }
            case 5:
            {
                std::cout << "|" << std::setfill('-') << std::setw(4);
                break;
            }
            }
        }
        std::cout << "|" << std::endl << std::setfill(' ');
    }
    std::cout << std::endl;

    return 0;
}