
#include <OneWire.h> 
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 

OneWire oneWire(ONE_WIRE_BUS); 

DallasTemperature sensors(&oneWire);
 
void setup(void) 
{ 
 
 Serial.begin(9600); 
 
 Serial.println("Dallas Temperature IC Control Library Demo"); 
 // Start up the library 
 
 sensors.begin(); 
} 

void loop(void) 
{ 

 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 

 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0));
 
 // Why "byIndex"?  
 // You can have more than one DS18B20 on the same bus.  
 // 0 refers to the first IC on the wire 
 
 
 delay(1000); 
} 
