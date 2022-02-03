#include "thread_guard.h"

thread_guard::thread_guard(std::thread& t_, bool state_ = 0) :
    t(t_), state(state_)
{
}

thread_guard::~thread_guard()
{
    if (t.joinable())
        if (state)
            t.detach();
        else
            t.join();
}
