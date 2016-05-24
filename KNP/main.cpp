#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop sklep;
    Backpack plecak;
    plecak.set_capacity(15);
    sklep.fill("dane.txt");

    KNP KNP_problem(sklep, plecak);

    sklep.show();

    //KNP_problem.KNP_bruteforce();


    std::cout<<"Tekst w mainie na dole"<<endl;

    return 0;
}
