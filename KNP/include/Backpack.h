#ifndef BACKPACK_H
#define BACKPACK_H
#include "Item.h"
#include <vector>

class Backpack
{
    public:
        int size();
        void show();
        void clean();
        int get_capacity();
        void add(Item item);
        void set_capacity(int capacity); //inicjuje pojemnosc
    private:
        int capacity;           //pojemnosc
        std::vector <Item> Item_array;         //lista elementow spakowanych
};

#endif // BACKPACK_H
