#include <HCSR04.h>
#include <LiquidCrystal.h>
#include <NewPing.h> 


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
UltraSonicDistanceSensor uds(2, 3);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Distance");
  
}


void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1); //makes it so that value is displayed in the 2nd row
  
  double sum=0;
  double average = 0;
  for (int i=0; i<10;i++){
    sum+=uds.measureDistanceCm();
  }
  average = sum/float(10);
   lcd.print(String(average) + " cm"); 
   //Serial.print(String(average)); //for data collection purposes
   delay(1000);

}
