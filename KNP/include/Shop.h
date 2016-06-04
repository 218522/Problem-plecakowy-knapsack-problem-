#ifndef SHOP_H
#define SHOP_H
#include<string>
#include"Item.h"

class Shop
{
    public:
        void show();
        Item* get_Item_array();
        int get_number_of_items();
        void fill(const char* file_name);
    private:
        string name;
        int number_of_items;
        Item* Item_array;
};

#endif // SHOP_H
