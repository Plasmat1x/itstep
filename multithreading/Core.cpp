#include "Core.h"

#include<iostream>
#include<functional>
#include<chrono>

void Core::threadx_fnc()
{
}

void Core::thread1_fnc()
{
    std::cout << "\t\t\t\t\t<----thread_1 start---->" << std::endl;

    for (int i = 0; i < 25; i++)
    {
        std::cout << "\t\t\t\t\t THREAD1::ITERATION::" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }

    std::cout << "\t\t\t\t\t<----thread_1   end---->" << std::endl;
}

void Core::thread2_fnc()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    std::cout << "\t\t\t\t\t\t\t\t\t\t<----thread_2 start---->" << std::endl;

    for (int i = 0; i < 7; i++)
    {
        std::cout << "\t\t\t\t\t\t\t\t\t\t THREAD2::ITERATION::" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    std::cout << "\t\t\t\t\t\t\t\t\t\t<----thread_2   end---->" << std::endl;
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
    std::cout << "<----main thread start---->" << std::endl;

    thread1 = new std::thread(&Core::thread1_fnc, this);
    thread2 = new std::thread(&Core::thread2_fnc, this);

    for (int i = 0; i < 30; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << " M::THREAD::ITERATION::" << i << std::endl;
    }

    thread1->join();
    thread2->join();

    std::cout << "<----main thread   end---->" << std::endl;
}
