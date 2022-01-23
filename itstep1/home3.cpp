#include <cstdlib>
#include <iostream>

struct timeform
{
    unsigned short int _hours = 24;
    unsigned short int _minutes = 0;
    unsigned short int _seconds = 0;

    const unsigned int total_sec_day = 86400;
    const unsigned int total_sec_min = 60;
    const unsigned int total_sec_hrs = 3600;

    unsigned int total = 86400;

    void setTotalTime()
    {
        total = 8 * 60 * 60;
        _hours = 8;
    }

    void draw(bool work)
    {
        if (work)
        {
            std::cout << total << " seonds to end work" << std::endl;
            std::cout << _hours << " hours last"<< std::endl;
        }
        else
        {
            std::cout << total << " seconds last to midnight" << std::endl;
            std::cout << _hours << ":" << _minutes << ":" << _seconds << std::endl;
        }

        std::cout << std::endl;
    }

    void info()
    {
        std::cout << "Total seconds in day: " << total_sec_day << std::endl;
        std::cout << "Total seconds in hours: " << total_sec_hrs << std::endl;
        std::cout << "Total seconds in minutes: " << total_sec_min << std::endl;
        std::cout << std::endl << std::endl;
    }
};

void timeConvert(unsigned int& sec, timeform* _time)
{
    _time->total -= sec;

    _time->_hours = _time->total / _time->total_sec_hrs;
    _time->_seconds = _time->total % _time->total_sec_hrs;
    _time->_minutes = _time->_seconds / _time->total_sec_min;
    _time->_seconds %= _time->total_sec_min;
}

int main(int argc, char argv[])
{
    system("chcp 1251");
    system("cls");

    /*
    ��������� ��������� �������� ����������� � ����� � ������ � ����������. 
    (�������� ��� �������� �������� � ����������). 
    ������������ ��� ���������� ������ ���� ������.�
    */

    double input;
    std::cout << "1. ������� �� ����������� � ����� \n"
        << "2. ������� �� ������ � ���������� \n"
        << "0. ��������� ��������� \n"
        << "������� ����� ������ >> ";
    std::cin >> input;

    const float cm_per_in = 2.54f;

    if ((int)input == 1)
    {
        std::cout << "������� ����������: "; std::cin >> input;
        
        double res = input / cm_per_in;

        std::cout << res << " ����" << std::endl;
    }
    else if ((int)input == 2)
    {
        std::cout << "������� �����: "; std::cin >> input;

        float res = (float)input * cm_per_in;

        std::cout << res << " ��" << std::endl;
    }
    else if ((int)input == 0)
    {
        return EXIT_SUCCESS;
    }

    system("pause");
    system("cls");

    /* week 3 home 2 task 1
        ������������ ������ � ���������� ����� � ��������, 
    ��������� � ������ ���. ������� �� ����� ������� ����� � �����,
    ������� � ��������. ���������, ������� �����, ����� � ������
    �������� �� ��������.

    P.S. ����� ���� ����������.
    */

    timeform time_struct;
    timeform time_struct2;

    time_struct.info();
    
    time_struct.draw(false); // ��������� false ��� ������ ����� ��� � ���� � ������� ��:��:��, ���� true ��� ������ �������� ��� � � ������� �����

    unsigned int _time = 0; // in seconds
    std::cout << "Input time: "; std::cin >> _time;

    timeConvert(_time, &time_struct);

    time_struct.draw(false);

    /* week 3 home 2 task 1
        ������������ ������ � ���������� ����� � ��������,
    ��������� � ������ �������� ���. ���������, ������� ����� �����
    ��� �������� �������� ���� ������� ���� � 8 �����.

    P.s ����������� ��� ���� ��� � � ���������� �������
    */
    system("pause");
    system("cls");

    time_struct2.setTotalTime(); //������������� ����� ����� �������� ���

    time_struct2.draw(true);

    std::cout << "Input time: "; std::cin >> _time;

    timeConvert(_time, &time_struct2);

    time_struct2.draw(true);

    return EXIT_SUCCESS;
}