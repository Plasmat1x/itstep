#pragma once

#include<thread>

class Core
{
private:
    //var
    std::thread* thread1;
    std::thread* thread2;

    //func
    void threadx_fnc();
    void thread1_fnc();
    void thread2_fnc();

public:

    Core();
    ~Core();

    void run();
};

