#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop Shop1, Shop2, Shop3, Shop4;
    KNP KNP_problem;
    Backpack plecak;

    Shop1.fill("Miesny.txt");
    Shop2.fill("RTV_AGD.txt");
    Shop3.fill("Lumpeks.txt");
    Shop4.fill("Jubiler.txt");

    plecak.set_capacity(15);

    KNP_problem.set_backpack(plecak);
    KNP_problem.add_shop(Shop1);
    KNP_problem.add_shop(Shop2);
    KNP_problem.add_shop(Shop3);
    KNP_problem.add_shop(Shop4);

    KNP_problem.Thief();
    KNP_problem.Algorithms();
    return 0;
}
