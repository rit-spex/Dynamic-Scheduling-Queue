/**
 * File: TestQueue.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for queue
 */

#include "../Dynamic-Scheduling-Queue_Libary/DSQ.h"
#include <iostream>

int main(){

    DSQ dsq;
    dsq.set_default(1, 0);
    dsq.execute();
    dsq.add_routine(0, 1, 0);
    dsq.add_routine(0, 3, 0);

    dsq.execute();

    std::cout << dsq.get_size();
}