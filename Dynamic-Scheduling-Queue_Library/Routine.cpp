#include "Routine.h"
#include "DSQ.h"

#include <string>
#include <iostream>

TestRoutine::TestRoutine(int priority_mult, DSQ* pDsq, std::string msg) 
{
    Routine::priority_value = priority_mult;
    Routine::base_priority = priority_mult;
    Routine::_pDsq = pDsq;
    _msg = msg;
}

void TestRoutine::run() {
    std::cout << _msg << std::endl;

    TestRoutine routine = *(new TestRoutine(Routine::base_priority, Routine::_pDsq, _msg));
    //_pDsq->add_routine(routine);
}
