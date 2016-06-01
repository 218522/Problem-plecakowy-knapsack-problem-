#include "KNP.h"
#include "Shop.h"
#include <list>
#include <math.h>
#include <iostream>

using namespace std;

void KNP::add_shop(Shop shop){
    shop_list.push_back(shop);
}

void KNP::set_backpack(Backpack & backpack){
    this->backpack = & backpack;
}

void KNP::Thief(){
    Shop sklep = Find_best_shop();
    KNP_approx(sklep);
    cout<<"Podejscie do kradziezy od strony zlodzieja"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Wybrany sklep: "<<endl;
    sklep.show();
    cout<<"******************************************"<<endl;
    cout<<"Kradziez :"<<endl;
    backpack->show();
    cout<<"******************************************"<<endl;
}
// Algorytm aproksymacyjny
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
    int current_size =0;
    //Struktura do przechowywania atrakcyjnosci danego produktu i numeru produktu(numer wskaznika)
    float* a_tab = new float[shop.get_number_of_items()];
    int best_item_pos =-1;
    float best_item_a =-1;
    //Obliczanie atrakcyjnosci produktu i umieszczanie danych w tablicy
    for(int i=0; i<shop.get_number_of_items(); i++){
        a_tab[i] = shop.get_Item_array()[i].get_value()/shop.get_Item_array()[i].get_size();
    }
    for(int j=0; j<shop.get_number_of_items(); j++){
        //Szukamy przedmiotu o najlepszym wspolczynniku atrakcyjnosci
        for(int i=0; i<shop.get_number_of_items(); i++){
            if(a_tab[i]>best_item_a){
                best_item_pos=i;
                best_item_a=a_tab[i];
            }
        }
        //Jezeli damy rade, to pakujemy ten przedmiot
        if(backpack->get_capacity() >= shop.get_Item_array()[best_item_pos].get_size() + current_size){
            current_size += shop.get_Item_array()[best_item_pos].get_size();
            backpack->add(shop.get_Item_array()[best_item_pos]);
        }
        //Atrakcyjnosc zbadanego przedmiotu przyrownojemy do 0
        a_tab[best_item_pos]=-1;
        best_item_a =-1;
    }
}
//KONIEC Algorytm aproksymacyjny
//Algorytm bruteforce
void KNP::KNP_bruteforce(){
    int A = 0;
    int B = 0;
    int local_sum = 0;
    int local_size = 0;
    int maximum = 0;
    for(int shop_number =0; shop_number < shop_list.size(); shop_number++){
        A = B = 0;
        int* current_item_set = new int[shop_list[shop_number].get_number_of_items()];
        for(int i=0; i < pow(2,shop_list[shop_number].get_number_of_items()); i++){
            B = A;
            for(int j=0; j<shop_list[shop_number].get_number_of_items(); j++){
                B = B/2;
                if(B%2 == 1){
                    current_item_set[j] = 1;
                    local_sum += shop_list[shop_number].get_Item_array()[j].get_value();
                    local_size += shop_list[shop_number].get_Item_array()[j].get_size();
                }
            }
            if((local_sum > maximum) && (local_size <= backpack->get_capacity())){
                backpack->clean();
                maximum = local_sum;
                for(int j=0; j<shop_list[shop_number].get_number_of_items(); j++){
                    if(current_item_set[j] == 1)
                        backpack->add(shop_list[shop_number].get_Item_array()[j]);
                }
            }
            for(int j=0; j<shop_list[shop_number].get_number_of_items(); j++)
                    current_item_set[j]=0;
            A++;
            local_size = 0;
            local_sum = 0;
        }
        delete current_item_set;
    }
}
