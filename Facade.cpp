#include <Arduino.h>
#include "Facade.h"

/*************/
/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   52----  */
/*************/
void Facade::setLeftRearLight(bool highLow) {
   digitalWrite(52, highLow ? HIGH : LOW);
};

/*************/
/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ----49  */
/*************/
void Facade::setRightRearLight(bool highLow) {
   digitalWrite(49, highLow ? HIGH : LOW);
};

/*************/
/*   -----51 */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
/*************/
void Facade::setRightHeadLight(bool highLow) {
   digitalWrite(51, highLow ? HIGH : LOW);
};

/*************/
/*  50-----  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
/*************/
void Facade::setLeftHeadLight(bool highLow) {
   digitalWrite(50, highLow ? HIGH : LOW);
};

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
void Facade::setRpiPowerRalay(bool highLow) {
   digitalWrite(8, highLow ? HIGH : LOW); // false means LOW true means HIGH (R5)
};
  
void Facade::setSelfPowerRalay(bool highLow){
  digitalWrite(7, highLow ? HIGH : LOW); // false means LOW true means HIGH (R4) PIN #7
};  

void Facade::setEngageMotorsRelay(bool highLow) {
  digitalWrite(6, highLow ? HIGH : LOW); // false means LOW true means HIGH (R1) PIN #6
}; 

void Facade::setR2Relay(bool highLow) {
  digitalWrite(5, highLow ? HIGH : LOW); // false means LOW true means HIGH (R2) PIN #5
};
