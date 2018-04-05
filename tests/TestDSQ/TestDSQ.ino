/**
 * File: TestDSQ.ino
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *      Test program for DSQ
 */

#include <DSQ.h>

DSQ dsq(50);

void testFunc(){

    Serial.println("Hello World!");

    dsq.add_routine(0, 0, testFunc);
}

void testFunc3(){
    Serial.println("BAR!");
}

void testFunc2(){
    Serial.println("FOO!");

    dsq.add_routine(0, 2, testFunc2);
    dsq.add_routine(0, 5, testFunc3);
}

void setup() {
    Serial.begin(9600);
    delay(5000);
    Serial.println("DSQ Test");
  
	  dsq.add_routine(0, 0, testFunc);
    dsq.add_routine(0, 2, testFunc2);
}

void loop(){
	dsq.execute();
}
