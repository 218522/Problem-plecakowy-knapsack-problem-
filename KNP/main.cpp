#include <iostream>
#include"KNP.h"
#include "timer.hh"

#include <string>
#include <fstream>


using namespace std;

int main()
{
    Shop Shop1, Shop2, Shop3, Shop4;
    KNP KNP_problem;
    Backpack plecak;
    Timer czas;

    double aprox,brute,dynamic;
    string const results("WYNIKI.csv");
   ofstream save_result(results.c_str());

    Shop1.fill("Miesny.txt");
    Shop2.fill("RTV_AGD.txt");
    Shop3.fill("Lumpeks.txt");
    Shop4.fill("Jubiler.txt");

    plecak.set_capacity(8);

    KNP_problem.set_backpack(plecak);
    KNP_problem.add_shop(Shop1);
    KNP_problem.add_shop(Shop2);
    KNP_problem.add_shop(Shop3);
    KNP_problem.add_shop(Shop4);

    KNP_problem.Thief();
    KNP_problem.Algorithm_Bruteforce();
    KNP_problem.Algorithm_Dynamic();

    /*
   // for(int i=0;i<10;i++)
   // {
    czas.start();
    KNP_problem.Thief();
    czas.stop();
    cout << "Aprox" << czas.getElapsedTimeMs() << endl;
    save_result << czas.getElapsedTimeMs() << endl;

    czas.start();
   KNP_problem.Algorithm_Bruteforce();
    czas.stop();
    //cout << "Brute" << czas.getElapsedTimeMs() << endl;
    save_result << czas.getElapsedTimeMs() << endl;

     czas.start();
    KNP_problem.Algorithm_Dynamic();
    czas.stop();
     cout << "Dynamic" << czas.getElapsedTimeMs() << endl;
     //save_result << czas.getElapsedTimeMs() << endl;
   // }
//save_result << "Srednia Aprox: " << endl << aprox << endl;
  //  save_result << "Srednia Brute: " << endl << brute << endl;
  //  save_result << "Srednia Dynamic: " << endl << dynamic << endl;

*/
    return 0;
}
