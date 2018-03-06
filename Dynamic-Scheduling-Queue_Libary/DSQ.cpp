/**
 * File: DSQ.cpp
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Dynamic Scheduling Queue(DSQ) is a library used to provide dynamic execution
 *      of tasks or other routines within a microprocessor.
*/

#include "DSQ.h"

DSQ::DSQ(){
	priority_cnt = 0;
}

void DSQ::add_routine(int type, int priority_mult, void (*routine_addr)()){
	
	// Create routine dynamically 
	Routine routine = create_routine(type, priority_mult, routine_addr);
	// Place routine into the DSQ(sch_queue)
	insert_routine(routine);
}

void DSQ::execute(){

    priority_cnt += 1;

	Routine current_routine = sch_queue.pop();
    current_routine.routine_addr();
}

int DSQ::get_size(){
	
	return sch_queue.size(); 
}

void DSQ::set_default(int type, void (*routine_addr)()) {

    Routine routine = create_routine(type, 0, routine_addr);
    sch_queue.set_default(routine);
}

Routine DSQ::create_routine(int type, int priority_mult, void (*routine_addr)()){
	Routine routine;
	
	routine.type = type;
	routine.priority_value = calculate_priority(priority_mult);
	routine.routine_addr = routine_addr;
	
	return routine;
}

void DSQ::insert_routine(const Routine &routine){
	
	sch_queue.push(routine);
}

unsigned long int DSQ::calculate_priority(int priority_mult){
	
	// TODO check maximum value
	return priority_cnt + (PRIORITY_BASE * priority_mult);
}

void DSQ::priority_reset(){
	// TODO
}

bool Comparator::operator() (const Routine &lhs, const Routine &rhs){
	return lhs.priority_value < rhs.priority_value;;
}