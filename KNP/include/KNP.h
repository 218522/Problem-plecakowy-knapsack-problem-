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
        // Wczytywanie plecaka i dodawanie sklepu do kontenera
        void set_backpack(Backpack & backpack);
        void add_shop(Shop shop);
        // Algorytmy rozwiazania problemu
        Shop Find_best_shop();       //Zwraca sklep o najlepszym wspolczynnku
        void KNP_approx(Shop shop);  //Algorytm aproksymacyjny dla zlodzieja
        void KNP_bruteforce();
        void KNP_bruteforce_source(int numer_wywolania, int* used_item, int* item_set, int & suma_wartosci);
    private:
        std::vector <Shop> shop_list;
        Backpack* backpack;
};

#endif // KNP_H
