#include "Core.h"

#include<iostream>
#include<functional>

void Core::threadx_fnc()
{
}

void Core::thread1_fnc()
{
    std::cout << "thread_1 start" << std::endl;

    std::cout << "thread_1 end" << std::endl;
}

void Core::thread2_fnc()
{
    std::cout << "thread_2 start" << std::endl;

    std::cout << "thread_2 end" << std::endl;
}

Core::Core() :
    thread1(nullptr),
    thread2(nullptr)
{

}

Core::~Core()
{
    delete thread2;
    delete thread1;
}

void Core::run()
{
    std::cout << "main thread start" << std::endl;

    thread1 = new std::thread(&Core::thread1_fnc, this);
    thread2 = new std::thread(&Core::thread2_fnc, this);

    thread1->join();
    thread2->join();

    std::cout << "main thread end" << std::endl;
}
