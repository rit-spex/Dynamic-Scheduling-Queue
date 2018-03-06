/**
 * File: TestQueue.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for queue
 */

#include "../Dynamic-Scheduling-Queue_Libary/DSQ.h"
#include <iostream>

Routine bulid_fake_routine(int type, int priority_mult, void (*routine_addr)()){
    Routine routine;

    routine.type = type;
    routine.priority_value = priority_mult;
    routine.routine_addr = routine_addr;

    return routine;
}

int main(){

    priority_queue<Routine, 100, Comparator> queuei;

    queuei.push(bulid_fake_routine(0, 1, 0));
    Routine r1 = queuei.pop();

    queuei.push(bulid_fake_routine(0, 2, 0));
    queuei.push(bulid_fake_routine(0, 55, 0));
    queuei.push(bulid_fake_routine(0, 0, 0));
    queuei.push(bulid_fake_routine(0, 0, 0));
    Routine r2 = queuei.pop();

    queuei.pop();
    queuei.pop();
    queuei.pop();
    // Empty

    queuei.pop(); // Returns default

    std::cout << queuei.size();
}