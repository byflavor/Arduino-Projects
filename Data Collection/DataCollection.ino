//Rashmi Alawani
#include <dht_nonblocking.h> 
#define DHT_SENSOR_TYPE DHT_TYPE_11 
static const int DHT_SENSOR_PIN = 8; 
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE ); 
float average;
float* circBuf;
int counter;
int samples;

//IIR Weights
float oldWeight;
float newWeight;

void setup() 
{ 
    Serial.begin(9600); 
    average = 0;

    Serial.println("Input the # samples to average: ");
    Serial.setTimeout(10);
    
    while(!Serial.available()); 
    samples = Serial.parseInt();
    Serial.read(); 
    
     circBuf = (float*)malloc(samples*sizeof(float));
      int i;
      for (i = 0; i < samples; i++) 
      {
        circBuf[i] = 0;
      }
      counter = 0;
    
    //ask user for old weight
    Serial.println("Input old weight: ");
    while(!Serial.available()); 
    oldWeight = Serial.parseFloat();
    Serial.read(); 

    //ask user for new weight
    Serial.println("Input new weight: ");
     while(!Serial.available()); 
    newWeight = Serial.parseFloat();
    Serial.read();  
} 

void loop() 
{ 
        //Serial.print( "T: " + String(temperature) + " deg C. H = " + String(humidity) + "%. Average = " + String(average));

        //comment out based on if you want to see IIR or FIR readings
        //FIR
        Serial.println( "Recorded value: " + String(analogRead(A0)) + "  FIR value: "  + finiteImpulseResponse(analogRead(A0))); 
        
        //IIR
        //Serial.println( "Recorded value: " + String(analogRead(A0)) + "  IIR value: "  + infiniteImpulseResponse(analogRead(A0), average)); 
        delay(500);
} 

//returns weighted average
float infiniteImpulseResponse(float measurement, float ave){
  average = average*oldWeight + measurement*newWeight;
  
  return average;
}

//takes average based on the current 10 values
float finiteImpulseResponse(float value){
  float sum = 0;
  circBuf[counter] = value;
  counter++;

  //if the counter goes beyond samples you wrap around
  if (counter >= samples)
  {
    counter = 0;
  }

  for(int i=0; i <samples; i++)
  {
    sum +=circBuf[i];
  }
  return float(sum/samples);

}


