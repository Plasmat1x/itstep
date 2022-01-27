#pragma once
#include "TemperatureModel.h"

class Controller
{
private:
    TemperatureModel* _model;
public:
    Controller(TemperatureModel* model);

    void start();
};

