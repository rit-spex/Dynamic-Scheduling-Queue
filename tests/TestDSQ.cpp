/**
 * File: TestDSQ.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for DSQ
 */

#include "../Dynamic-Scheduling-Queue_Libary/DSQ.h"
#include <iostream>

int cnt = 0;

void testFunc(){

    std::cout << "Hello World! ";
    std::cout << cnt;
    std::cout << "\n";

    cnt += 1;
}

int main(){

    std::cout << sizeof(Routine);

    DSQ dsq;
    for (int i = 0; i < 2000; ++i) {
        dsq.add_routine(0, 1, testFunc);
    }
    while (dsq.get_size())
    dsq.execute();

    for(int i = 0; i < 20; ++i) {
        dsq.add_routine(0, 1, testFunc);
        dsq.execute();
    }
    dsq.add_routine(0, 5, testFunc);
    dsq.add_routine(0, 2, testFunc);

    dsq.execute();
    dsq.execute();

    dsq.execute();
}