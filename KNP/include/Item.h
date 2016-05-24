#ifndef ITEM_H
#define ITEM_H
#include<string>

using namespace std;

class Item
{
    public:
        void show();
        int get_value();
        int get_size();
    private:
        friend class Shop;
        int value;       //Wartosc przedmiotu
        int size;        //Rozmiar przedmiotu
        string name;     //Nazwa przedmiotu

};

#endif // ITEM_H
