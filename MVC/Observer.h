#pragma once
#include <vector>

class Observer
{
public:
    virtual void update() = 0;
};

class Observable
{
private:
    std::vector<Observer*> _observers;

public:
    
    void addObserver(Observer* observer);

    void notifyUpdate();

};

