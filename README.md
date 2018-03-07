# Dynamic-Scheduling-Queue
Dynamic Scheduling Queue(DSQ) is a library used to provide dynamic execution of tasks or other routines within a microprocessor. 

### Operation
DSQ uses a min-heap structured by a task priority value, this priority value will loosely define when a routine will be executed. Priority values are calculated based on a priority counter. As this priority counter increases, priority values assigned to routines will also increase. The priority counter moves up by one on completion of a routine. Intervals between execution of routines can be adjusted by using the priority multiplier. The full priority calculation is as follows:

`priority_value = priority_counter + PRIORITY_BASE * priority_multiplier`

Routines will be structured in a min-heap with the lowest priority being first. Routines will be able to add other routines into the DSQ. This will allow for routine fragmentation into sub-routines. Routines will be defined as high-level tasks which require no additional data to execute. This allows for robustness within the DSQ as well as simplicity. Routines in the program will be as follows:
```
type: int
priority_value: unsigned long int
routine_addr: void(*)()
```
Routines on execution will be removed from the min-heap, then the function in routine_addr will be executed. In the event that priority_value >= size of long, the DSQ will issue a priority reset on all entries in the heap. Then priority_counter will be reset to 0. This is done to prevent overflows or reaching maximums within the DSQ, in this case such a issue would block the DSQ from dynamic execution. 

Adding routines to the DSQ will create a struct as defined above, then the newly created struct will be inserted into the DSQ. 

### Usage

To implement the DSQ first research the target platform specific long maximum size which can be calculated using this formula (2^(SIZE_OF_LONG_BYTES*8)). Then add this value into the DSQ.h file under the macro MAX_SIZE_LONG. Include the DSQ.h header into program. Now create a DSQ object in your program as follows:

`DSQ NAMEOFVAR;`

This will create a DSQ object which will be used to control execution of routines within your program. To add routines into the DSQ, the add_routine() function must be used, this function take the following parameters in this order: 

`int type, int priority_mult, void (*routine_addr)()`

The **type** parameter is used to define which type of routine is to be added. NOTE thise value is not used by the DSQ currently. 

The **priority_mult** parameter is used to define how often the routine will be called. (0 most often ... to least often)

The void **(*routine_addr)()** is the address of the routine. This value can be passed as follows for example:

`add_routine(0, 1, testFunc);`

The routine passed to the add_routine function should have a return type of void and take no parameters, for example:

```
void testFunc(){
    std::cout << "Hello World! ";
}
```

Now after the routine has been added into the DSQ, the execute function can be called to run exactly one routine at a time. The execute function can be used as follows:

`dsq.execute();`

On the event the DSQ is empty, a default routine will be called. A default routine should always be set and can be set as follows.

`dsq.set_default(type, (*routine_addr)())`

To access the size of the DSQ the get_size function can be used. 

`dsq.get_size();`

### Contributor
Dylan Wagner(drw6528@rit.edu

