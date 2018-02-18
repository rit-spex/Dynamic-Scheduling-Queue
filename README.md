# Dynamic-Scheduling-Queue
Dynamic Scheduling Queue(DSQ) is a library used to provide dynamic execution of tasks or other routines within a microprocessor. 

### Operation
DSQ uses a min-heap structured by a task priority value, this priority value will loosely define when a routine will be executed. Priority values are calculated based on a priority counter. As this priority counter increases, priority values assigned to routines will also increase. The priority counter moves up by one on completion of a routine. Intervals between execution of routines can be adjusted by using the priority multiplier. The full priority calculation is as follows:
'''
priority_value = priority_counter + PRIORITY_BASE \* priority_multiplier
'''


### Usage

