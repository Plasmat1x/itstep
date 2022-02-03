#pragma once
#include<thread>

class thread_guard
{
private:
    std::thread& t;
    bool state;
public:
    explicit thread_guard(std::thread& t_, bool state_);
    ~thread_guard();

    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

