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
	void (*routine_addr)(); // function pointer to static routine
};

// create alis between struct Routine and Routine
typedef struct Routine Routine;


class DEQ{
private:
	long priority_cnt; // main priority counter
	// min-heap
	std::priority_queue<Routine, std::vector<Routine>, Comparator> sch_queue;
	
	// create_routine - creates a Routine struct on the stack, fills in the values 
	// then returns the created struct.
	// args:
	//		type: int - type as int, can also be used with a enum
	//		priority_mult: int - ranging from (0+)
	//		routine_addr: void(*)()
	// return:
	//		The Routine struct created and filled in with the parameters. 
	Routine create_routine(int type, int priority_mult, void (*routine_addr)());
	
	// insert_routine - inserts the provided routine into the sch_queue
	// args:
	//		routine: Routine - the routine to be inserted
	void insert_routine(const Routine &routine);
	
	// calculate_priority - used to calculate the priority value stored in the Routine struct
	// args:
	//		priority_mult: int - used to specify execution interval
	// return:
	// 		value containing the priority value
	long calculate_priority(int priority_mult);
	
public:
	
	// public constructor used to initialize DEQ varables. 
	DEQ();
	
	// add_routine -- main method for submitting routines to the DEA
	// args:
	//		type: int - type as int, can also be used with a enum
	//		priority_mult: int - ranging from (0+)
	//		routine_addr: void(*)()
	void add_routine(int type, int priority_mult, void (*routine_addr)());
	
	// execute - called in a loop, main function for executing routines placed in
	// the DEQ.
	void execute();
	
	// get_size - getter function
	// return:
	//		The size of the priority_queue/DSQ
	int get_size();
};

// Comparator class used to to compare Routine objects
class Comparator{
public:
	bool operator() (const Routine &lhs, const Routine &rhs);
};

#endif /* end of include guard: DSQ_H */