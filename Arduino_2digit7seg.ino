//Prepare binary array for all 7 segment to turn on 7 segment at position of a,b,c,d,e,f,g 
int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};

int digit1, digit2; // initialize individual digit to controll each segment

void setup()
{
  for (int i = 2; i < 9; i++)
  {
    pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
  pinMode(12, OUTPUT); //declare 7 seg Digit1 pin as output
  pinMode(13, OUTPUT);//declare 7 seg Digit2 pin as output
}
void loop() {
  for (int j = 0; j <= 99; j++)// for lopp to pass value from 00-99
  {
    digit2 = j / 10;
    digit1 = j % 10;
    for ( int k = 0; k < 20; k++)// For loop to control the digit control to print 00-99
    {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      dis(digit2);
      delay(10);
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      dis(digit1);
      delay(10);
    }
  }
}
void dis(int num)
{
  for (int i = 2; i < 9; i++)
  {
    digitalWrite(i, bitRead(digit[num], i - 2));
  }
}
