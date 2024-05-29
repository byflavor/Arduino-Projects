void setup() {
  // put your setup code here, to run once:
     for(int i =2; i<7; i++){
      pinMode(i, OUTPUT);
     }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i =2; i<7; i++){
  digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW   
  }
  for(int i =7; i>2; i--){
  digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW   
  }
  delay(500);
}
