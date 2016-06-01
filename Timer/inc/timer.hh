#ifndef TIMER_HH
#define TIMER_HH


#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

class Timer{

private:
    chrono::time_point<chrono::high_resolution_clock> begin, end;
    chrono::duration<long double> work_time;
public:

    void start(void);
    void stop(void);
    long double getElapsedTimeMs(void);


};


#endif
