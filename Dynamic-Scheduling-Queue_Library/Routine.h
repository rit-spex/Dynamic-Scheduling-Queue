/**
 * File: Routine.h
 * Organization:RIT Space Exploration
 * Author: Chris Johnson
 * Description:
 *      Base class for all routines used by the DSQ
 */

#ifndef ROUTINE_H
#define ROUTINE_H

#include <string>

class DSQ;

class Routine {
public:
    /*Routine(int priority_mult, DSQ* pDsq) {
        priority_value = priority_mult;
        base_priority = priority_mult;
        _pDsq = pDsq;
    }
    Routine();*/
    virtual void run()=0;

    int type;
    unsigned long int priority_value;
    unsigned long int base_priority;

protected:
    DSQ* _pDsq;
};

class TestRoutine : public Routine {
public:
    TestRoutine(int, DSQ*, std::string);
    void run() override;

private:
    std::string _msg;

};

#endif
