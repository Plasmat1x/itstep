#include <cstdlib>
#include <iostream>
#include <cmath>

int main()
{
    system("chcp 1251");
    system("cls");



    //n8 253-288 //n1 1-36
    //���������� ������� ��������
    int app_number = 0; //����� ��������    // �������� � ����������
    int flr_number = 0; //����� �����       // �������������
    int blk_number = 0; //����� ��������    // �������������

    int apps_onfloor = 0;   //���-�� �� �� �����        //�������� � ����������
    int floors_onblock = 0; //���-�� ������ � ��������  //�������� � ����������
    int blk_inhouse = 0;    //���-�� ��������� � ����   //�������� � ����������

    std::cout << "Programm house, bloack and floor by appartaments number\n" << std::endl;

    std::cout << "floors in construction "; std::cin >> floors_onblock;
    std::cout << "apps on floor "; std::cin >> apps_onfloor;
    std::cout << "blocks in construction "; std::cin >> blk_inhouse;
    std::cout << "enter app number "; std::cin >> app_number;
    
    /*
    if (app_number <= 0) { std::cout << "app_number wrong" << std::endl; return -1; }
    if (app_number > 0 && app_number <= 36) std::cout << "block #1" << std::endl;
    //...
    */

    /*
    if (app_number > 288) std::cout << "wrong" << std::endl;
    else
    {
        int total_apps_onblock = (floors_onblock * apps_onfloor);
        blk_number = app_number / total_apps_onblock;

        if (app_number % total_apps_onblock == 0) std::cout << blk_number << " block" << std::endl;
        else std::cout << blk_number + 1 << " block" << std::endl;


        flr_number = (app_number - blk_number * total_apps_onblock) / apps_onfloor;

        if (app_number % total_apps_onblock == 0)
        {
            std::cout << flr_number + floors_onblock << " floor" << std::endl;
        }
        else
        {
            if (app_number % 4 == 0) std::cout << flr_number << " floor" << std::endl;
            else std::cout << flr_number + 1 << " floor" << std::endl;
        }
    }
    */


    int total_apps_onblock = (floors_onblock * apps_onfloor);                   //���-�� ������� � ��������
    int total_apps = (total_apps_onblock * blk_inhouse);                        //��� �������� �� �� ���������� ��������
    blk_number = app_number / total_apps_onblock;                               //������ �������� ��������
    flr_number = (app_number - blk_number * total_apps_onblock) / apps_onfloor; //������ �������� �����

    if (app_number > total_apps || app_number < 1 ) 
        std::cout << "wrong appartments number" << std::endl;
    else
    {
        if (app_number % total_apps_onblock == 0)
        {
            std::cout << blk_number << " block" << std::endl;
            std::cout << flr_number + floors_onblock << " floor" << std::endl;
        }
        else
        {
            std::cout << blk_number + 1 << " block" << std::endl;
            if (app_number % apps_onfloor == 0) std::cout << flr_number << " floor" << std::endl;
            else std::cout << flr_number + 1 << " floor" << std::endl;
        }
    }

    system("chcp 866");
    return EXIT_SUCCESS;
}