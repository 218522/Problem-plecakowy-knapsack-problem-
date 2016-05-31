<<<<<<< HEAD
#include "KNP.h"
#include "Shop.h"
#include <list>
#include<iostream>

using namespace std;

void KNP::add_shop(Shop shop){
    shop_list.push_back(shop);
}

void KNP::set_backpack(Backpack & backpack){
    this->backpack = & backpack;
}

void KNP::Thief(){
    Shop sklep = Find_best_shop();
    //KNP_approx(sklep);
    KNP_dynamic(sklep);
    cout<<"Podejscie do kradziezy od strony zlodzieja"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Wybrany sklep: "<<endl;
    sklep.show();
    cout<<"******************************************"<<endl;
    cout<<"Kradziez :"<<endl;
    backpack->show();
    cout<<"******************************************"<<endl;
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
=======
#include "KNP.h"
#include "Shop.h"
#include <list>
#include<iostream>

using namespace std;

void KNP::add_shop(Shop shop){
    shop_list.push_back(shop);
}

void KNP::set_backpack(Backpack & backpack){
    this->backpack = & backpack;
}

void KNP::Thief(){
    Shop sklep = Find_best_shop();
    //KNP_approx(sklep);
    KNP_dynamic(sklep);
    cout<<"Podejscie do kradziezy od strony zlodzieja"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Wybrany sklep: "<<endl;
    sklep.show();
    cout<<"******************************************"<<endl;
    cout<<"Kradziez :"<<endl;
    backpack->show();
    cout<<"******************************************"<<endl;
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
>>>>>>> 166e155f48f2811ec70ca9704e4fe543850af0d0
}

void KNP::KNP_dynamic(Shop shop)
{
<<<<<<< HEAD
    int n = shop.get_number_of_items();
    int W=backpack->get_capacity();

    int i,w;
    int K[n+1][W+1];

for(i=0;i<shop.get_number_of_items();i++)
{
    for(w=0;w<=backpack->get_capacity();w++)
{
    if(i==0|| w==0)
        K[i][w]=0;
        else if (shop.get_Item_array()[i-1].get_size()<=w)
            K[i][w]=max(shop.get_Item_array()[i-1].get_value() + K[i-1][w-shop.get_Item_array()[i-1].get_size()], K[i-1][w]);
        else
            K[i][w]=K[i-1][w];
}
cout << K[n+1][W+1] << " ";
//backpack->add(K[n][W]);
}
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
=======
      int current_size =0;
    //Struktura do przechowywania atrakcyjnosci danego produktu i numeru produktu(numer wskaznika)
    float* a_tab = new float[shop.get_number_of_items()];
    int best_item_pos =-1;
    float best_item_a =-1;
    //Obliczanie atrakcyjnosci produktu i umieszczanie danych w tablicy
    for(int i=0; i<shop.get_number_of_items(); i++){
        //a_tab[i] = shop.get_Item_array()[i].get_value()/shop.get_Item_array()[i].get_size();
    }
    for(int j=0; j<shop.get_number_of_items(); j++){
    if((i>=shop.get_Item_array()[j].get_size()) && (a_tab[i]<a_tab[i-shop.get_Item_array()[j].get_size()]+shop.get_Item_array()[j].get_value())) //jesli item miesci sie w plecaku i jego obecnosc zwieksza jego watosc to dodaj
    {
        a_tab[i]=a_tab[i-shop.get_Item_array()[j].get_size()]+shop.get_Item_array()[j].get_value();
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
>>>>>>> 166e155f48f2811ec70ca9704e4fe543850af0d0
