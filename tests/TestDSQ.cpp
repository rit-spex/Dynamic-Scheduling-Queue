/**
 * File: TestDSQ.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for DSQ. To be used for testing on linux. Will
 *      not work on a Teensy due to stuff
 */

#include "../Dynamic-Scheduling-Queue_Library/DSQ.h"
#include "../Dynamic-Scheduling-Queue_Library/Routine.h"
#include <iostream>
#include <chrono>
#include <thread>

int cnt = 0;
unsigned int cap = 50;

DSQ dsq(50);

/*
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
    dsq.set_default(1, testFunc);
    dsq.add_routine(0, 0, testFunc);
    dsq.add_routine(0, 2, testFunc2);

    while(true){
        dsq.execute();
        std::cout << dsq.get_size() << std::endl;
    }
}

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

int main() {
    TestRoutine* routine = new TestRoutine(0, &dsq, "FOO");
    dsq.add_routine(routine);

    //routine->printMsg();
    //routine->run();

    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    
    //while (true){
        std::cout << dsq.get_size() << std::endl;
        dsq.execute();
        sleep_for(100ms);
    //}
}
