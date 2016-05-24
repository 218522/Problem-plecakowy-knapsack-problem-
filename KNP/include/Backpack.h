#ifndef BACKPACK_H
#define BACKPACK_H
#include "Item.h"
#include <vector>

class Backpack
{
    public:
        void fill(int capacity); //inicjuje pojemnosc
        void show();
        int get_capacity();
        std::vector <Item> get_Item_array();
    private:
        int capacity;           //pojemnosc
        std::vector <Item> Item_array;         //lista elementow spakowanych
};

#endif // BACKPACK_H
