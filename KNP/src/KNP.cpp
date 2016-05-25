#include "KNP.h"
#include "Shop.h"
#include<iostream>

using namespace std;

void KNP::add_shop(Shop shop){
    shop_list.push_back(shop);
}

void KNP::set_backpack(Backpack & backpack){
    this->backpack = & backpack;
}

Shop KNP::Find_best_shop(){
    float tab[2];           //tab[0] -> max value, tab[1] -> number of shop
    float local_sum = 0;
    float local_size = 0;
    for(int i=0; i<shop_list.size(); i++){
        for(int j=0; j<shop_list[i].get_number_of_items(); j++){
            local_size += shop_list[i].get_Item_array()[j].get_size();
            local_sum += shop_list[i].get_Item_array()[j].get_value();
        }
        if(tab[0]<local_sum/local_size){
            tab[0]=local_sum/local_size;
            tab[1]=i;
        }
        local_sum = local_size = 0;
    }

    return shop_list[tab[1]];
}

void KNP::KNP_approx(Shop shop){
    /*
    int* tab = new int[shop_list.size()];
    int local_sum = 0;
    int local_size = 0;
    for(int i=0, i<shop_list.size(), i++){
        for(int j=0; j<shop_list[i].get_number_of_items(); j++){
            tab[i]
        }
    }*/
}

void KNP::KNP_bruteforce(){
    /*
    int* used_item = new int[shop.get_number_of_items()];
    int* item_set = new int[shop.get_number_of_items()];
    for(int i=0; i<shop.get_number_of_items(); i++){
        item_set[i]=0;
    }
    int suma_wartosci = 0;

    KNP_bruteforce_source(0, used_item, item_set, suma_wartosci);*/
}
void KNP::KNP_bruteforce_source(int numer_wywolania, int* used_item, int* item_set, int &suma_wartosci){
/*
    for(int i=0; i<shop.get_number_of_items(); i++){
        item_set[numer_wywolania] = i;
        if(numer_wywolania < shop.get_number_of_items()-1){
            numer_wywolania ++;
            KNP_bruteforce_source(numer_wywolania, used_item, item_set, suma_wartosci);
            numer_wywolania --;
        }
        if(numer_wywolania == shop.get_number_of_items()-1){
            std::cout<<"Wchodze"<<endl;
            int waga = 0;
            int lokalna_suma_wartosci = 0;
            for(int j=0; j<shop.get_number_of_items(); j++){
                if((used_item[item_set[j]] != 1) && (waga + shop.get_Item_array()[item_set[j]].get_size() <= backpack->get_capacity())){
                        std::cout<<"Wchodze #"<<endl;
                    used_item[item_set[j]] = 1;
                    waga += shop.get_Item_array()[j].get_size();
                    std::cout<<"Waga "<<waga<<endl;
                    lokalna_suma_wartosci += shop.get_Item_array()[j].get_value();
                    std::cout<<"Suma "<<lokalna_suma_wartosci<<endl;
                }
                if(lokalna_suma_wartosci>suma_wartosci){
                    suma_wartosci = lokalna_suma_wartosci;
                    backpack->clean();
                    for(int k = 0; k<shop.get_number_of_items(); k++){
                            std::cout<<"XXXXXXXXXXX"<<endl;
                        if(used_item[k]==1){

                            backpack->add(shop.get_Item_array()[item_set[j]]);
                        }
                    }
                }
                if(waga + shop.get_Item_array()[item_set[j]].get_size() >= backpack->get_capacity())
                    break;
            }
        for(int a=0; a<shop.get_number_of_items(); a++){
                item_set[a]=0;
            }
        }
    }*/
}
