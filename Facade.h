#ifndef FACADE
#define FACADE

class Facade {

//  LED to PIN Map:
/*************/
/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   52---   */
  void setLeftRearLight(bool highLow);   // false means LOW true means HIGH

/*   ------  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ----49  */
  void setRightRearLight(bool highLow);  // false means LOW true means HIGH

/*   -----51 */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
  void setRightHeadLight(bool highLow);  // false means LOW true means HIGH

/*  50-----  */
/*   |    |  */
/*   |    |  */
/*   |    |  */
/*   |    |  */ 
/*   ------  */
  void setLeftHeadLight(bool highLow);   // false means LOW true means HIGH

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
  void setRpiPowerRalay(bool highLow);   // false means LOW true means HIGH (R5)   PIN #8
  void setSelfPowerRalay(bool highLow);  // false means LOW true means HIGH (R4)   PIN #7
  void setEngageMotorsRelay(bool highLow); // false means LOW true means HIGH (R1) PIN #6
  void setR2Relay(bool highLow); // false means LOW true means HIGH (R2) PIN #5 
  
};

#endif
