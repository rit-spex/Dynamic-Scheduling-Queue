/**
 * File: TestDSQ.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for DSQ
 */

#include "../Dynamic-Scheduling-Queue_Library/DSQ.h"
#include <iostream>

int cnt = 0;
unsigned int cap = 50;

DSQ dsq(50);


void testFunc(){

    std::cout << "Hello World! ";
    std::cout << cnt;
    std::cout << "\n";

    cnt += 1;

    dsq.add_routine(0, 0, testFunc);

    if(cnt == 50000){
        dsq.clear();
    }
}

void testFunc3(){
    std::cout << "BAR!\n";
}

void testFunc2(){
    std::cout << "FOO!\n";

    dsq.add_routine(0, 2, testFunc2);
    dsq.add_routine(0, 5, testFunc3);
}

int main(){
    //dsq.set_default(1, testFunc);
    dsq.add_routine(0, 0, testFunc);
    dsq.add_routine(0, 2, testFunc2);

    while(true){
        dsq.execute();
        std::cout << dsq.get_size();
    }
}
/*
int main(){

    std::cout << sizeof(Routine);

    DSQ dsq;
    for (int i = 0; i < 2000; ++i) {
        dsq.add_routine(0, 1, testFunc);
        dsq.execute();
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
 */