/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees, displays on SSD1306 OLED
 * License: MIT
 */

//Rashmi Alawani
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_light.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);                           // Ensure serial monitor set to this value also    
  lcd.begin(16, 2);                    
  Wire.begin();
  mpu.begin();         
  mpu.calcGyroOffsets();                          // This does the calibration
}

void loop() {
  mpu.update();  
  if((millis()-timer)>10)                         // print data every 10ms
  {   
    lcd.setCursor(0, 0); //start at the top left corner
    lcd.print("P:" + String(mpu.getAngleX()) + " R:" + String(mpu.getAngleY()));
    lcd.setCursor(0, 1); //move it to the second line
    lcd.print("Y:"+String(mpu.getAngleZ()));
    
  
    String dir = "hello world";
    double degrees = mpu.getAngleZ();
    degrees = (int)degrees % 360;
    if (degrees<0){
      degrees +=360;
    }


    if(11.25>=degrees || degrees>=(360-11.25)){h
      dir = "N   ";
    }
    else if (11.25<=degrees && degrees<=33.75){
      dir = "NNW  ";
    }
    else if(33.75<degrees && degrees<56.25){
      dir = "NW  ";
    }
    else if(56.25<degrees && degrees<78.75){
    dir = "WNW  ";
  }
  else if(78.75<degrees && degrees<101.25){
    dir = "W   ";
  }
  else if(101.25<degrees && degrees<123.75){
    dir = "WSW  ";
  }
  else if(123.75<degrees && degrees<146.25){
    dir = "SW  ";
  }
  else if(146.25<degrees && degrees<168.75){
    dir = "SSW  ";
  }
  else if(168.75<degrees && degrees<191.25){
    dir = "S   ";
  }
  else if(191.25<degrees && degrees<213.75){
    dir = "SSE  ";
  }
  else if(213.75<degrees && degrees<236.25){
    dir = "SE  ";
  }
  else if(236.25<degrees && degrees<258.75){
    dir = "ESE  ";
  }
  else if(258.75<degrees && degrees<281.25){
    dir = "E   ";
  }
  else if(281.25<degrees && degrees<303.75){
    dir = "ENE  ";
  }
  else if(303.75<degrees && degrees<326.25){
    dir = "NE  ";
  }
  else if(326.25<degrees && degrees<348.75){
    dir = "NNE  ";
  }
  timer = millis();  
    delay(1000); //delay 1 second for user to read
    lcd.print(" dir:"+dir);
    Serial.println(degrees);
}
}
