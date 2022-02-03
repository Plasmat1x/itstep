#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>

struct objectData // структура реализованна POD'ом для хранения данных 
{
    float x = 0.0F;
    float y = 0.0F;
    double speed = 0.0;
};


void recursive(objectData* obj, std::vector<objectData>* arr);

void t1()
{
    /*
    физической задачи тела брошенного под углом на  С++. Посмотрите пожалуйста, систему уравнений записала, решается методом Рунге -Кутта 4 порядка. 
    В итоге мне нужен вывод результатов с шагом по времени например 0.01 для угла, скорости и координат в файл для построения графиков

    Это научка, так что подобных не было к сожалению. Да, получается решение yi изначально ищется в нуле, то есть до цикла я так понимаю его нужно найти. 
    После этого для каждой переменной y(i+1) ищется решение на основе предыдущего приближения через формулы коэффициентов k. h- это шаг. Надеюсь более или менее понятно объяснила.
    Я пыталась сама это все сделать, но у меня проблемы с массивами и пониманием как применить этот метод именно в программировании
    */

    //p.s. x0, y0 и тд. это исходные данные их программа не вычесляет она получает их либо от другой программы, либо из файла, либо ввод с клавиатруы

    std::vector<objectData> output_data; //массив для хранения данных на каждом шаге если требовния писать на C то данная структура данных не подойдет придется писать свой динамический массив. аналог arr[x]

    const double gravity = 0.0; //Задаем или вычисляем гравитацию
    float mass = 40.0F;
    double accelleration = 400.0;

    objectData test_object;

    //std::cin >> //исхлдные данные пример угол броска, ускорение броска, масса объекта

    recursive(&test_object, &output_data); // функция рекурсии

}

void recursive(objectData* obj, std::vector<objectData>* arr)
{
    if (obj->y <= 0) // с данным условие осторожно, данные берутся из obj указанным при вызове функции (test_object). если данное условие никак не будет зайдествованно программа уйдет в цикл пока не забьется вся память
    {
        return; // условие окончания рекурсии
    }

    /*  //формула прямолинейного движения в зависимости от угла. ист. SFML blueprints Maxime Barbier ch.3 p.77
    
                            перевод угла в радианы (но это не точно)
        float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;

                                    позиция (х, y)                 ускорение   время
        _impulse += sf::Vector2f(std::cos(angle), std::sin(angle)) * 300.f * seconds;

        по части гравитации и физики (не симулирует физику реального мира) https://github.com/Plasmat1x/SFproj/blob/test2/IT/PhysicsSystem.cpp и https://github.com/Plasmat1x/SFproj/blob/test2/IT/PhysicsSystem.h
    */

    /* //часть расчета, грубый пример
    obj->x += cos(angle) * t * acceleration
    obj->y += sin(angle) * t * acceleration * gravity
    obj->speed = acceleration * t
    */

    arr->push_back(objectData{obj->x,obj->y,obj->speed}); //добавляем в массив новый обьект с просчитанными данными

    recursive(obj, arr);
}

/*
//пример рекурсии факториала

namespace myMath
{
    int i = 1;                              //данные переменные находятся за функцией в глобальной пространстве
    unsigned long int result;               //

    unsigned long int factorial(unsigned long int x)
    {
        if (x == 1 || x == 0)
            return 1;                       //условие выхода

        i++;
        result = x * factorial(x - 1);      //повторный вызов функции(самой себя с новым параметром х-1)

        return result;
    }
}

*/