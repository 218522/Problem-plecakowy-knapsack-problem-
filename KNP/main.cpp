#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop sklep;
    Backpack plecak;
    KNP KNP_problem(sklep, plecak);

    sklep.fill("dane.txt");
    plecak.set_capacity(15);

    sklep.show();

    std::cout<<"Tekst w mainie na dole"<<endl;

    return 0;
}
