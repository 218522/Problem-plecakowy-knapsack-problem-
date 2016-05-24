#ifndef KNP_H
#define KNP_H

#include "Shop.h"
#include "Backpack.h"

class KNP
{
    public:
        KNP(Shop shop, Backpack backpack);
        void KNP_bruteforce();
        void KNP_bruteforce_source(int numer_wywolania, int* used_item, int* item_set, int & suma_wartosci);
    private:
        Shop shop;
        Backpack backpack;
};

#endif // KNP_H
