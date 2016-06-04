#include "timer.hh"


void Timer::start(void) {
	begin = chrono::high_resolution_clock::now();
}

void Timer::stop(void) {
	end = chrono::high_resolution_clock::now();
}

long double Timer::getElapsedTimeMs(void) {
	work_time = end - begin;
	return work_time.count()*1000;
}
