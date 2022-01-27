#pragma once
#include "Observer.h"


class TemperatureModel : public Observable
{
private:
    float _temperatureF;

public:
    
    TemperatureModel(float tempF);

    float getF();
    float getC();

    void setF(float tempF);
    void setC(float tempC);
};

