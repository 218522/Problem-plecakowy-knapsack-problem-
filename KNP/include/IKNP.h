#ifndef IKNP_H
#define IKNP_H
#include "Shop.h"

class IKNP
{
    public:
        virtual void KNP_approx(Shop shop)=0;
        virtual void KNP_bruteforce()=0;
        virtual void KNP_dynamic(Shop shop)=0;
        virtual void KNP_bruteforce_source(int numer_wywolania, int* used_item, int* item_set, int & suma_wartosci)=0;
};

#endif // IKNP_H
