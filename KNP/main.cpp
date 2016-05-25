#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop Shop1, Shop2, Shop3, Shop4;
    KNP KNP_problem;
    Backpack plecak;

    Shop1.fill("Jubiler.txt");
    Shop2.fill("Miesny.txt");
    Shop3.fill("RTV_AGD.txt");
    Shop4.fill("Lumpeks.txt");

    plecak.set_capacity(8);

    KNP_problem.set_backpack(plecak);
    KNP_problem.add_shop(Shop1);
    KNP_problem.add_shop(Shop2);
    KNP_problem.add_shop(Shop3);
    KNP_problem.add_shop(Shop4);

    KNP_problem.Thief();
    return 0;
}
