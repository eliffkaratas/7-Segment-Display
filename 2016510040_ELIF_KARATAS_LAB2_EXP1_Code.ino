/// define pins
#define a 3
#define b 4
#define c 5
#define d 6
#define e 7
#define f 8
#define g 9
#define dp 2
#define buttonPin 12

/// define COUNTER_VALUE
/// COUNTER_VALUE can be changed
int COUNTER_VALUE = 7;
/// define number for displaying on seven segment display
int number = 0;
/// define button state for using button controls
int buttonState = 0;
int last_buttonState = 0;
/// define press state for using in experiments
int pressState = 0;

int wait = 150;

void setup() 
{
  /// setup modes
randomSeed(analogRead(0));
pinMode(buttonPin, INPUT);
pinMode(dp, OUTPUT);
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT); 
pinMode(g, OUTPUT);
}

void loop()
{
  /// button state equals to digital read button pin value ( high or low )
  buttonState = digitalRead(buttonPin);
  
  /// EXPERIMENTS
  increment(); /// EXPERIMENT 1
  //randomNumber(); /// EXPERIMENT 2
  
  /// if button is pressed, press state changes to 1
  /// it is also using for displaying 0 at first in experiment 1 (increment void)
  if(pressState==1)
  {
    SevenSegmentDisplay(number);
    //delay(wait); // I used this delay on video for pushing button delays
  }
  /// if button is pressed as 2nd pressing, press state changes to 2 
  if(pressState==2)
  {
    SevenSegmentDisplay(number);
    //delay(wait);
  }
}

/// EXPERIMENT 1
void increment ()
{
  /// if button is pressed and 2nd time pressing or more  
  if (buttonState != last_buttonState && buttonState == LOW && (pressState==1 || pressState==2)) {
    /// increment number
    number = number + COUNTER_VALUE;
    /// display number that is greater than 15
    if(number > 15)
    {
      number = number % 16;
    }
    /// if press state is 1, change to 2
    pressState=2;
  }
  /// if button is pressed for the first time
  else if (buttonState != last_buttonState && buttonState == LOW && pressState==0) {
    /// displaying number 0 on seven segment display
    number = 0;
    /// press state changes to 1 because of press state was 0
    pressState=1;
  }
  last_buttonState = buttonState;
}

/// EXPERIMENT 2
/*void randomNumber()
{
  /// if button is pressed
  if (buttonState != last_buttonState && buttonState == LOW) {
    /// press state changes to 1 because of press state was 0
     pressState=1;     
    /// random numbers between 0-16
     number = random(0,16);
  }
  last_buttonState = buttonState;
}*/

/// NUMBERS ON SEVEN SEGMENT
void SevenSegmentDisplay(int number)
{
  /// leds on seven segment display
 if (number == 0)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);   
 }
 if (number == 1)
 {
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
 }
 if (number == 2)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
 }
 if (number == 3)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
 }
 if (number == 4)
 {
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
 }
 if (number == 5)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
 }
 if (number == 6)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
 }
 if (number == 7)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
 }
 if (number == 8)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
 }
 if (number == 9)
 {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
 }
  if(number == 10)
  {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
  }
   if(number == 11)
  {
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
  }
   if(number == 12)
  {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
  }
   if(number == 13)
  {
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
  }
   if(number == 14)
  {
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
  }
   if(number == 15)
  {
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
  }
}
