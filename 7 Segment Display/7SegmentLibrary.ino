#include <SevenSegment.h>
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int button = 9;
int h = 10;

int current; // these two variables will store the state of the button which was pressed currently or the last stored state of the button
int previous;
int rand;
SevenSegment sevenseg(a,b,c,d,e,f,g,h);

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  current = digitalRead(button);
}

void loop() {
  // put your main code here, to run repeatedly:
  sevenseg.none();
  delay(1000);
  sevenseg.zero();
  delay(1000);
  sevenseg.one();
  delay(500);
  sevenseg.two();
  delay(500);
  sevenseg.three();
  delay(500);
  sevenseg.four();
  delay(500);
  sevenseg.five();
  delay(500);
  sevenseg.six();
  delay(500);
  sevenseg.seven();
  delay(500);
  sevenseg.eight();
  delay(500);
  sevenseg.nine();
  delay(500);  
}