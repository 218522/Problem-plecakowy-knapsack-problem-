#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop sklep;
    Backpack plecak;

    sklep.fill("dane.txt");
    plecak.set_capacity(15);
    KNP KNP_problem(sklep, plecak);


    sklep.show();

    KNP_problem.KNP_bruteforce();
    plecak.show();

    std::cout<<"Tekst w mainie na dole"<<endl;

    return 0;
}
