#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>

struct objectData // ��������� ������������ POD'�� ��� �������� ������ 
{
    float x = 0.0F;
    float y = 0.0F;
    double speed = 0.0;
};


void recursive(objectData* obj, std::vector<objectData>* arr);

void t1()
{
    /*
    ���������� ������ ���� ���������� ��� ����� ��  �++. ���������� ����������, ������� ��������� ��������, �������� ������� ����� -����� 4 �������. 
    � ����� ��� ����� ����� ����������� � ����� �� ������� �������� 0.01 ��� ����, �������� � ��������� � ���� ��� ���������� ��������

    ��� ������, ��� ��� �������� �� ���� � ���������. ��, ���������� ������� yi ���������� ������ � ����, �� ���� �� ����� � ��� ������� ��� ����� �����. 
    ����� ����� ��� ������ ���������� y(i+1) ������ ������� �� ������ ����������� ����������� ����� ������� ������������� k. h- ��� ���. ������� ����� ��� ����� ������� ���������.
    � �������� ���� ��� ��� �������, �� � ���� �������� � ��������� � ���������� ��� ��������� ���� ����� ������ � ����������������
    */

    //p.s. x0, y0 � ��. ��� �������� ������ �� ��������� �� ��������� ��� �������� �� ���� �� ������ ���������, ���� �� �����, ���� ���� � ����������

    std::vector<objectData> output_data; //������ ��� �������� ������ �� ������ ���� ���� ��������� ������ �� C �� ������ ��������� ������ �� �������� �������� ������ ���� ������������ ������. ������ arr[x]

    const double gravity = 0.0; //������ ��� ��������� ����������
    float mass = 40.0F;
    double accelleration = 400.0;

    objectData test_object;

    //std::cin >> //�������� ������ ������ ���� ������, ��������� ������, ����� �������

    recursive(&test_object, &output_data); // ������� ��������

}

void recursive(objectData* obj, std::vector<objectData>* arr)
{
    if (obj->y <= 0) // � ������ ������� ���������, ������ ������� �� obj ��������� ��� ������ ������� (test_object). ���� ������ ������� ����� �� ����� �������������� ��������� ����� � ���� ���� �� �������� ��� ������
    {
        return; // ������� ��������� ��������
    }

    /*  //������� �������������� �������� � ����������� �� ����. ���. SFML blueprints Maxime Barbier ch.3 p.77
    
                            ������� ���� � ������� (�� ��� �� �����)
        float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;

                                    ������� (�, y)                 ���������   �����
        _impulse += sf::Vector2f(std::cos(angle), std::sin(angle)) * 300.f * seconds;

        �� ����� ���������� � ������ (�� ���������� ������ ��������� ����) https://github.com/Plasmat1x/SFproj/blob/test2/IT/PhysicsSystem.cpp � https://github.com/Plasmat1x/SFproj/blob/test2/IT/PhysicsSystem.h
    */

    /* //����� �������, ������ ������
    obj->x += cos(angle) * t * acceleration
    obj->y += sin(angle) * t * acceleration * gravity
    obj->speed = acceleration * t
    */

    arr->push_back(objectData{obj->x,obj->y,obj->speed}); //��������� � ������ ����� ������ � ������������� �������

    recursive(obj, arr);
}

/*
//������ �������� ����������

namespace myMath
{
    int i = 1;                              //������ ���������� ��������� �� �������� � ���������� ������������
    unsigned long int result;               //

    unsigned long int factorial(unsigned long int x)
    {
        if (x == 1 || x == 0)
            return 1;                       //������� ������

        i++;
        result = x * factorial(x - 1);      //��������� ����� �������(����� ���� � ����� ���������� �-1)

        return result;
    }
}

*/