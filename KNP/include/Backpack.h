#ifndef BACKPACK_H
#define BACKPACK_H
#include "Item.h"
#include <vector>

class Backpack
{
    public:
        void set_capacity(int capacity); //inicjuje pojemnosc
        void show();
        int get_capacity();
        void add(Item item);
        void clean();
        int size();
    private:
        int capacity;           //pojemnosc
        std::vector <Item> Item_array;         //lista elementow spakowanych
};

#endif // BACKPACK_H
