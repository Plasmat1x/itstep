#include "Cart.h"

Cart::Cart()
{

}

Cart::~Cart()
{

}

void Cart::add(int id, int count)
{
    for (auto& pos : cart)
    {
        if (pos.id == id)
        {
            pos.count += count;
        }
    }
}

void Cart::remove(int id, int count)
{
    for (auto& pos : cart)
    {
        if (pos.id == id)
        {
            pos.count -= count;
        }
    }
}
