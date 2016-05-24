#include "Backpack.h"
#include<iostream>

using namespace std;

void Backpack::set_capacity(int capacity)
{
    this->capacity = capacity;
}

void Backpack::show(){
    cout<<      "Backpack"<<endl;
    for(int i=0; i<Item_array.size(); i++){
        Item_array[i].show();
    }
}

int Backpack::get_capacity(){
    return capacity;
}

std::vector <Item> Backpack::get_Item_array(){
    return Item_array;
}
