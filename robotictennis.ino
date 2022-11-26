#include "Timer.h"
#include "Listener.h"

unsigned long int counter = 0;
Timer* timer = new Timer();

void setup() {
  //  LED to PIN Map:
/*************/
/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   52---   */
/*************/  
  pinMode(52, OUTPUT); // Rear Left

/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ----49  */
  pinMode(49, OUTPUT); // Rear Right

/*   -----51 */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
  pinMode(51, OUTPUT); // Head Right

/*  50-----  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */  
  pinMode(50, OUTPUT); // Head Left

/* Relay to PIN Map: 
-------------
|\^^^^^^^^^ |\
| \^^^^^^^^^||\
|R2\ ^^^^^^^|||\
| R3\-------||||-
|w   |bottom|||||0
| a  |bottom|||||
|  l |bottom|||||
|R1 l|bottom|||||
|    |bottom|||||
\------------\|||
 \transparent \||
  \^^R5^^R4^^^^\|
   \^^^^wall^^^^\0
     ^ ^    ^ ^
     | |    | | 
*/  
  pinMode(8, OUTPUT); // Rapberry Pi Power Relay (R5)
  pinMode(7, OUTPUT); // The Arduino Due Power Relay (R4)
  pinMode(6, OUTPUT); // The Motor power Relay (R3)
  pinMode(5, OUTPUT); // The Reserved R2 Relay (Speakers?)

  Serial.begin(9600);

    timer->executePeriodically(new TumblerListener(52), 1000, 200);
//  timer->executeNextTick(new TumblerListener(52));

}

void loop() {
  // put your main code here, to run repeatedly:
  timer->tick(counter);
  counter++;
}
