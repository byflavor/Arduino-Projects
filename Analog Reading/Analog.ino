#include <math.h>
//Rashmi Alawani

int value = 0;
float scaleFactor = 5.0/1023;
float voltage = 0.0;

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  setIndicator(readVolts());
  delay(100);
}


double readVolts() //input to voltage
{
  value = analogRead(A0); //Reads the analog input
  voltage = value*scaleFactor;
  Serial.println("The input value is " + String(value) + ", which corresponds to " + String(voltage) + "volts");
  return voltage;
}

void setIndicator(double voltage) //turn on the LEDs based on the voltage.
{
  if(voltage>=0.5){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }
  if(voltage>=1){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }
  if(voltage>=2){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }
  if(voltage>=3){
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
  if(voltage>=4){
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);
  }
  if(voltage>=5){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }
    
}


