#ifndef LIST_H
#define LIST_H
#include "Item.h"


class List
{
    public:
        List();
        void size();
        void add();
        void remove();
    private:
        Item* first;
};

#endif // LIST_H
