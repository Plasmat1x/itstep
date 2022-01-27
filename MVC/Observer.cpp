#include "Observer.h"

void Observable::addObserver(Observer* observer)
{
    _observers.push_back(observer);
}

void Observable::notifyUpdate()
{
    for (int i = 0; i < _observers.size(); i++)
    {
        this->_observers[i]->update();
    }
}
