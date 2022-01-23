#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath> // ��� ����� ��
#include <cstdlib>

void secondsToFormat(const int& seconds);
void moneySepFromFloat(const float& sum);
void daysToWeeks(const int& days);
void calcRuningSpeed(const int& dist, const float& time);

int main6(int argc, char* argv[])
{
    /*
    ��������� ��������� ���������� ������� ����� � ����� ����������, 
    ������ �������� � ����������. ��������� ��������� �� �����. 
    (��� ���������� ������������ ���������� ������������ ����� ������)�
    */
    system("chcp 1251");
    system("cls");

    float r = 0.f;//������
    float l = 0.f;//����� ����������
    float s = 0.f;//�������

    std::cout << "--��������� ���������� ������� ����� � ����� ����������--" << std::endl;
    std::cout << "������� ������ => "; std::cin >> r;

    //l=sqrt(S*4*PI) or l=2*PI*r
    //s=2*PI*r*r

    s = 2 * M_PI * r * r;
    l = 2 * M_PI * r;

    std::cout << "��������:" << std::endl;
    std::cout << "\t������� ���������� => " << s << std::endl;
    std::cout << "\t����� ���������� => " << l << std::endl;

    system("pause");
    system("cls");

    {
        std::cout << "--��������� ����������� ������ � ��������� ����� (��:��:��)--" << std::endl;
        int seconds = 0;
        std::cout << "������� ����� � ��������: "; std::cin >> seconds;
        secondsToFormat(seconds);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--��������� ����������� ����� ����� ����� \"12.75\" � 12$ 75c--" << std::endl;
        float value = 0;//����� �����
        std::cout << "������� ����� (�������): "; std::cin >> value;
        moneySepFromFloat(value);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--��������� ����������� ���� � ������ + ���--" << std::endl;
        int value = 0;//����
        std::cout << "������� ���������� ����: "; std::cin >> value;
        daysToWeeks(value);
    };

    system("pause");
    system("cls");

    {
        std::cout << "--��������� ���������� �������� ����--" << std::endl;
        float time = 0.f;
        int distance = 0;
        std::cout << "������� ����� ��������� (������) = "; std::cin >> distance;
        std::cout << "������� ����� (���.���) = "; std::cin >> time;
        calcRuningSpeed(distance, time);

    };

    system("pause");
    system("cls");

    {
        /*
        �������� ���������, ������� ���������� ������������
        ������ ����� ��������� ������ � ����, � ����� ������� �������, ������� ����������� ����. ���������� ����� �����,
        ������������� ������ ��������� ������ �����.
        */
        std::cout << "--��������� ������� ������ �� ������--" << std::endl;
        float _value = 0.f; // �����
        float _precent = 0.f; // ���������� ������
        float _income = 0.0f; // ����� ��������

        std::cout << "������� ����� ������ (euro): "; std::cin >> _value;
        std::cout << "������� ���������� ������: "; std::cin >> _precent;

        float prec_val = _value / 100;
        _income = prec_val * _precent;
        std::cout << "������� ����� ������� �� ������ " << _precent << " % �������: " << _income << " euro" << std::endl;
        _income /= 12;
        std::cout << "����������� ����� ������� �� ������ " << _precent << " % �������: " << _income << " euro" << std::endl;
        
    };
    system("pause");
    system("cls");

    return EXIT_SUCCESS;
}

void secondsToFormat(const int& seconds)
{
    int Hours = 0;
    int Minutes = 0;
    int Seconds = 0;

    Seconds = seconds % 60;
    Minutes += seconds / 60;
    Hours += Minutes / 60;
    Minutes %= 60;

    std::cout << "�����: " << Hours << ":" << Minutes << ":" << Seconds << std::endl;
}

void moneySepFromFloat(const float& val)
{
    std::cout << int(val) << " $ " << int(100*(val-int(val))) << " c " << std::endl;
}

void daysToWeeks(const int& days)
{
    int _days = 0;
    int _weeks = 0;

    _days = days % 7;
    _weeks = days / 7;

    std::cout << _weeks << " ������ " << _days << " ���" << std::endl;
}

void calcRuningSpeed(const int& dist, const float& time)
{
    int min = 0;
    int sec = 0;
    int sum_sec = 0;
    float speed = 0;

    sec += (time - int(time)) * 100;
    min += int(time) + (sec/60);
    sec %= 60;
    sum_sec += min * 60 + sec;

    speed = (float)dist / sum_sec;

    float speed_kmph = 3.6f * speed;

    std::cout << "���������: " << dist << " �" << std::endl;
    std::cout << "�����: " << min << " ��� " << sec << " ��� = " << sum_sec << " ���" << std::endl;
    std::cout << "�� ������ �� ��������� " << speed_kmph << " ��/�" << std::endl;
}
