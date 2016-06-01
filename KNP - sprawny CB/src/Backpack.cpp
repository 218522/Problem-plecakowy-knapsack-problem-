#include "Backpack.h"
#include<iostream>

using namespace std;

void Backpack::set_capacity(int capacity)
{
    this->capacity = capacity;
}

void Backpack::show(){
    cout<<"     Backpack"<<endl;
    cout<<"capacity: "<<capacity<<endl;
    int backpack_weight =0;
    int backpack_value =0;
    for(int i=0; i<Item_array.size(); i++){
        Item_array[i].show();
        backpack_value += Item_array[i].get_value();
        backpack_weight += Item_array[i].get_size();
    }
    cout<<"SUMMARY: "<<endl<<"   VALUE: "<<backpack_value<<endl<<"   WEIGHT: "<<backpack_weight<<endl;
}

int Backpack::get_capacity(){
    return capacity;
}

void Backpack::add(Item item){
    Item_array.push_back(item);
}
void Backpack::clean(){
    Item_array.clear();
}
int Backpack::size(){
    return Item_array.size();
}
