#include "Item.h"
#include<iostream>

using namespace std;

void Item::show(){
    cout<<"  Name: "<<name<<endl;
    cout<<"  Size: "<<size<<endl;
    cout<<"  Value: "<<value<<endl;
}

int Item::get_value(){
    return this->value;
}

int Item::get_size(){
    return this->size;
}
