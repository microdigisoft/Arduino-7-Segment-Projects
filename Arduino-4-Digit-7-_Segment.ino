#include "SevSeg.h"
SevSeg sevseg; //Initiate a seven segment controller object


void setup() {
  byte numDigits = 4;  // 4 digit display
  byte digitPins[] = {2, 3, 4, 5};//( Digital pins D1, D2, D3, D4)
  byte segmentPins[] = {6, 8, 12, 10, 9, 7, 13, 11};//( Seggmrnt pin such as  A,B,C,D,E,F,G,Dp )
  bool resistorsOnSegments = 0;  // variable above indicates that 4 resistors were placed on the digit pins.
                                 // set variable to 1 if you want to use 8 resistors on the segment pins.
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);// LED brightness
}
void loop() {
  sevseg.setNumber(3141, 3); //what you want to display
  sevseg.refreshDisplay(); // Must run repeatedly
}
