#include <iostream>
#include"KNP.h"


using namespace std;

int main()
{
    Shop sklep;
    sklep.fill("dane.txt");
    sklep.show();
    Backpack plecak;
    plecak.fill(15);
    Item przedmiot;
    plecak.get_Item_array().push_back(przedmiot);
    KNP problem(sklep, plecak);
    problem.KNP_bruteforce();
    plecak.show();
    return 0;
}
