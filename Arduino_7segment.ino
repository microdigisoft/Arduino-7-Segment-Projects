// One digit 7 segment LED display demo.
// Displays digit 0 - 9 and decimal point
//Prepare array of 7-Arduino pins which we need to interfaced with 
//7segments
int segPins[] = {2,3,4,5,6,7,8,9,0,};   // { a b c d e f g . )

//Truth table for driving the 7segments LED
byte segCode[11][8] = {
//  a  b  c  d  e  f  g  .
  { 1, 1, 1, 1, 1, 1, 0, 1},  // 0
  { 0, 1, 1, 0, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1, 0},  // 2
  { 1, 1, 1, 1, 0, 0, 1, 0},  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0},  // 4
  { 1, 0, 1, 1, 0, 1, 1, 0},  // 5
  { 1, 0, 1, 1, 1, 1, 1, 0},  // 6
  { 1, 1, 1, 0, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1, 0},  // 8
  { 1, 1, 1, 1, 0, 1, 1, 0},  // 9
  { 0, 0, 0, 0, 0, 0, 0, 1}   // .
};


void displayDigit(int digit)
{
  for (int i=0; i < 8; i++)
  {
    digitalWrite(segPins[i], segCode[digit][i]); //passing the value pin array              
  }
}


void setup()
{
  for (int i=0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);// declare Arduino pin as an output
  }

 }


void loop()
{
   for (int n = 0; n < 11; n++)    // display digits 0 - 9 and decimal point
  {
     displayDigit(n);
     delay(1000); ///1 second delay 
  }

}
