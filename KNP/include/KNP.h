#ifndef KNP_H
#define KNP_H
#include"IKNP.h"
#include <vector>

#include "Shop.h"
#include "Backpack.h"

class KNP : public IKNP
{
    public:
        void Thief();
        void Algorithm_Bruteforce();
        void Algorithm_Dynamic();
        // Wczytywanie plecaka i dodawanie sklepu do kontenera
        void set_backpack(Backpack & backpack);
        void add_shop(Shop shop);
        // Algorytmy rozwiazania problemu
        Shop Find_best_shop_approx();       //Zwraca sklep o najlepszym wspolczynnku
        Shop Find_best_shop_dynamic();
        void KNP_approx(Shop shop);  //Algorytm aproksymacyjny dla zlodzieja
        void KNP_bruteforce();       //Algorytm silowy
        void KNP_dynamic();
    private:
        std::vector <Shop> shop_list;
        Backpack* backpack;
};

#endif // KNP_H
