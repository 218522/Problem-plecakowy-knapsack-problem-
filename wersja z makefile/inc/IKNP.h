#ifndef IKNP_H
#define IKNP_H
#include "Shop.h"

class IKNP
{
    public:
        virtual void KNP_approx(Shop shop)=0;
        virtual void KNP_bruteforce()=0;
};

#endif // IKNP_H
