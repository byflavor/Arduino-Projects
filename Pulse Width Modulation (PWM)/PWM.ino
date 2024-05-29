float scaleFactor = 255/5.0;
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  Serial.print(scaleFactor);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("Please input a desired voltage between 0.0 and 5.0");
Serial.setTimeout(10); 
while(!Serial.available());
  float userRequest = Serial.parseFloat();
  Serial.parseFloat();
  Serial.println("Input voltage requested: " + String(userRequest));
  float analogValue = userRequest * scaleFactor;
   Serial.println("PWM set to: " + String((int)analogValue));
   analogWrite(11, analogValue);
 
}
  
