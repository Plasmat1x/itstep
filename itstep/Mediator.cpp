#include <iostream>
#include <string>

class BaseComponent;

class Mediator
{
public: 
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator_;

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator)
    {
    }

    void set_mediator(Mediator* mediator)
    {
        this->mediator_ = mediator;
    }
};

class Component1 : public BaseComponent
{
public:

};

class Component2 : public BaseComponent
{
public:

};

class ConcreteMediator : public Mediator
{
private: 
    Component1* comp1;
    Component2* comp2;

public:
    ConcreteMediator(Component1* c1, Component2* c2) : comp1(c1), comp2(c2)
    {
        this->comp1->set_mediator(this);
        this->comp2->set_mediator(this);
    }

    void Notify(BaseComponent* sender, std::string event) const override
    {

    }
};

void ClientCode() 
{
    Component1* c1 = new Component1;
    Component2* c2 = new Component2;

    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

    std::cout << std::endl;

    delete c1;
    delete c2;
    delete mediator;
}

int main(int argc, char* argv[])
{
    ClientCode();
    return 0;
}