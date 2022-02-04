#include "test_for_main.h"

#include<iostream>
#include<cstdlib>
#include<thread>

void tz::fnc()
{
    std::cout << "hello thread" << std::endl;
}

void tz::fncx(int a, int b)
{
    std::cout << "hello param thread " << a+b << std::endl;
}

void tz::clbck(void(*fnc)(int, int), int a, int b)
{
    fnc(a, b);
}

void tz::testmain()
{
    std::thread t(tz::fnc);                             //yep
    t.detach();
  //std::thread t((tz::fncx)(5,6));                     //nope
  //std::thread t{ tz::fncx(5,6) };                     //nope
  //std::thread t((*tx)(int, int));                     //nope
  //std::thread t(tz::fncx, 5, 6);                      //yep
  //std::thread t{ tz::fncx, 5, 6 };                    //yep
  //std::thread t{ tz::clbck, tz::fncx, 50, 60 };       //nope
  //std::thread t{ tz::clbck, (tz::fncx)(50,60)};       //nope
  //std::thread t{ tz::clbck, tz::fncx(50,60)};         //nope

  //int a = 50, b = 60;                                 //yep
  //std::thread t{ [a,b]()->void
  //{
  //    fncx(a,b);
  //}
  //};
  //t = std::thread(tz::fncx, 20, 20);

    t.join();
}