# Dynamic-Scheduling-Queue
Dynamic Scheduling Queue(DSQ) is a library used to provide dynamic execution of tasks or other routines within a microprocessor. 

### Operation
DSQ uses a min-heap structured by a task priority value, this priority value will loosely define when a routine will be executed. Priority values are calculated based on a priority counter. As this priority counter increases, priority values assigned to routines will also increase. The priority counter moves up by one on completion of a routine. Intervals between execution of routines can be adjusted by using the priority multiplier. The full priority calculation is as follows:

`priority_value = priority_counter + PRIORITY_BASE * priority_multiplier`

Routines will be structured in a min-heap with the lowest priority being first. Routines will be able to add other routines into the DSQ. This will allow for routine fragmentation into sub-routines. Routines will be defined as high-level tasks which require no additional data to execute. This allows for robustness within the DSQ as well as simplicity. Routines in the program will be as follows:
```
type: int
priority_value: long
routine_addr: void(*)()
```
Routines on execution will be removed from the min-heap, then the function in routine_addr will be executed. In the event that priority_value >= size of long, the DSQ will issue a priority reset on all entries in the heap. Then priority_counter will be reset to 0. This is done to prevent overflows or reaching maximums within the DSQ, in this case such a issue would block the DSQ from dynamic execution. 

Adding routines to the DSQ will create a struct as defined above, then the newly created struct will be inserted into the DSQ. 

### Usage
### Contributors 
Dylan Wagner

