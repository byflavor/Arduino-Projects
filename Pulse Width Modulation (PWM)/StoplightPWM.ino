/* First we set up variables that will be used throughout the program. */
int stopl = 6000;
int yld = 2000;
int go = 6000;
int GREEN = 10;
int BLUE = 9;
int RED = 11;
int s = 3;
/**
* Set up the Serial monitor, then set pins 10-12 for output. Finally
* set all pins LOW to insure that they are turned off.
**/
void setup()
{
  Serial.begin(9600);
  while(!Serial);
  pinMode(RED, OUTPUT);    // Sets the digital pins to the mode OUTPUT.
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(s,INPUT_PULLUP);

/**
  digitalWrite(RED,LOW);    // Sets the digital pins output to 0 Volts
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
  */ 
}


void loop()
{
  green(cswitch());
 // green(go);
  yellow(yld);
  red(stopl);
  
}


/* The following three functions turn on the desired LED and turn off all others. */

void green(int d){
  analogWrite(RED,255);
  analogWrite(GREEN,0);
  analogWrite(BLUE,255);
  Serial.println("Light Mode: Go = " + String(cswitch()));
  delay(d);
}


void yellow(int d){
  analogWrite(RED,190);
  analogWrite(GREEN,100);
  analogWrite(BLUE,255);
  Serial.println("Light Mode: Wait");
  delay(d);
}


void red(int d){
  analogWrite(RED,0);
  analogWrite(GREEN,255);
  analogWrite(BLUE,255);  
  Serial.println("Light Mode: Stop");
  delay(d);
}


int cswitch(){

  int  m = digitalRead(s);
  
  switch(m){

    case(HIGH):
      Serial.println("open");
      return 5000;
    case(LOW):
      Serial.println("closed");
      return 10000;
}
}
