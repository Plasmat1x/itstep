#pragma once
#include <string>
#include <vector>

struct Cart_position
{
    int id;
    std::string name;
    float price;
    int count;
};

class Cart
{
public:
    std::vector<Cart_position> cart;

    Cart();
    ~Cart();

    void add(int id, int count);

    void remove(int id, int count);
        
};

