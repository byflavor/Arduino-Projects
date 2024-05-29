void setup() {
  // put your setup code here, to run once:
     for(int i =2; i<7; i++){
      pinMode(i, OUTPUT);
     }
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(2, LOW);
    
    digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(3, LOW);
    
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(4, LOW);
    
    digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(5, LOW);
    
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(6, LOW);

    delay(500);                       // wait for 0.5 second

    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(6, LOW);

    digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(5, LOW);

    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(4, LOW);
    
    digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(3, LOW);

    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for 0.5 second
    digitalWrite(2, LOW);
}
