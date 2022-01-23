#pragma once
#include "Observer.h"
#include "TemperatureModel.h"

class ConsoleView : public Observer
{
private:
    TemperatureModel* _model;

public:

    ConsoleView(TemperatureModel* model);

    virtual void update() override;
};

