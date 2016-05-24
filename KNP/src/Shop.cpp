#include "Shop.h"
#include <fstream>
#include <iostream>

using namespace std;

void Shop::fill(const char* file_name)
{
    fstream plik;
    plik.open( file_name, std::ios::in);
    if( plik.good() == true )
    {
        plik>>number_of_items;
        Item_array = new Item[number_of_items];        //inicjuje tablice elementow dla wczytanej ilosci elementow
        plik>>name;                                    //wczytuje nazwe sklepu
        for(int i=0; !plik.eof(); i++){
            plik>>Item_array[i].name;
            plik>>Item_array[i].value;
            plik>>Item_array[i].size;
        }
        plik.close();
    }
    else
        cout << "Cannot access file!" << std::endl;
}

void Shop::show(){
    cout<<"     Shop "<<name<<endl;
    for(int i=0; i<number_of_items; i++){
        Item_array[i].show();
        cout<<"-"<<endl;
    }
}

int Shop::get_number_of_items(){
    return this->number_of_items;
}

Item* Shop::get_Item_array(){
    return Item_array;
}
