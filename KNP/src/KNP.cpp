#include "KNP.h"
#include "Shop.h"
#include<iostream>

KNP::KNP(Shop shop, Backpack & backpack)
{
    this->backpack = &backpack;
    this->shop = shop;
}

void KNP::KNP_bruteforce(){
    int* used_item = new int[shop.get_number_of_items()];
    int* item_set = new int[shop.get_number_of_items()];
    for(int i=0; i<shop.get_number_of_items(); i++){
        item_set[i]=0;
    }
    int suma_wartosci = 0;

    KNP_bruteforce_source(0, used_item, item_set, suma_wartosci);
    //backpack->show();
}
void KNP::KNP_bruteforce_source(int numer_wywolania, int* used_item, int* item_set, int &suma_wartosci){
    for(int i=0; i<shop.get_number_of_items(); i++){
        std::cout<<"Numer wywolania: "<<numer_wywolania<<"--- i: "<<i<<endl;
        item_set[numer_wywolania] = i;
        if(numer_wywolania < shop.get_number_of_items()-1){
            numer_wywolania ++;
            KNP_bruteforce_source(numer_wywolania, used_item, item_set, suma_wartosci);
            numer_wywolania --;
        }
        if(numer_wywolania == shop.get_number_of_items()-1){
            std::cout<<"Wchodze"<<endl;
            int waga_wartosci = 0;
            int lokalna_suma_wartosci = 0;
            for(int j=0; j<shop.get_number_of_items(); j++){
                std::cout<<"Wchodze #"<<endl;
                if((used_item[item_set[j]] != 1) && (waga_wartosci + shop.get_Item_array()[item_set[j]].get_size() <= backpack->get_capacity())){
                    //std::cout<<"ANNA "<<item_set[j]<<endl;
                    used_item[item_set[j]] = 1;
                    waga_wartosci += shop.get_Item_array()[j].get_size();
                    lokalna_suma_wartosci += shop.get_Item_array()[j].get_value();
                }
                if(lokalna_suma_wartosci>suma_wartosci){
                    suma_wartosci = lokalna_suma_wartosci;
                    backpack->clean();
                    std::cout<<"ANNA "<<item_set[j]<<endl;
                    for(int k = 0; k<shop.get_number_of_items(); k++){
                        if(used_item[k]==1){
                            backpack->add(shop.get_Item_array()[1]);
                        }
                    }
                }
                if(waga_wartosci + shop.get_Item_array()[j].get_size() <= backpack->get_capacity())
                    break;
            }
            for(int a=0; a<shop.get_number_of_items(); a++){
                item_set[a]=0;
            }
        }
    }
}
