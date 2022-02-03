//test for main
#pragma once

namespace tz
{
    void fnc();
    void fncx(int a, int b);
    void clbck(void(*fnc)(int, int), int a, int b);

    void testmain();
};
