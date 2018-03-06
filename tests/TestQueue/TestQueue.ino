/**
 * File: TestQueue.ino
 * Organization: RIT Space Exploration
 * Author: Dylan Wagner (drw6528@rit.edu)
 * Description:
 *    Test program for queue
 */

#include <DSQ.h>

DSQ dsq;

void setup() {
  Serial.begin(115200);
  delay(5000);
  Serial.println("Test Queue Startup");
  // put your setup code here, to run once:
  dsq.add_routine(0, 0, 0);
  
}

void loop(){
  
}



