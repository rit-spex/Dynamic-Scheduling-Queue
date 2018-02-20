/*
File: DSQ.h
Organization: RIT Space Exploration
Description: 
	Dynamic Scheduling Queue(DSQ) is a library used to provide dynamic execution 
	of tasks or other routines within a microprocessor. 
*/

#ifndef DSQ_H
#define DSQ_H

#define PRIORITY_BASE 4

// struct Routine -- holds information regarding routines
struct Routine{
	int type;	// type as int, can also be used with a enum
	long priority_value; // determines the placement within the DEQ
	std::function<void()> routine_addr; // function pointer to routine
}

// create alis between struct Routine and Routine
typedef struct Routine Routine;


class DEQ{
private:
	long priority_cnt; // main priority counter
public:
	
	// public constructor used to initialize DEQ varables. 
	DEQ();
	
	// add_routine -- main method for submitting routines to the DEA
	// args:
	//		type: int - type as int, can also be used with a enum
	//		priority_mult: int - ranging from (0+)
	//		func: std::function<void()> - function pointer to routine
	void add_routine(int type, int priority_mult, const std::function<void()> &func);
	
}

#endif /* end of include guard: DSQ_H */
