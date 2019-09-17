/*
============================             
  www.kingstonhack.space    
=============================

A script to write an anolog input to a bluetooth module via the serial connection. 
To connect to an android device connected via bluetooth
 
Bluetooth module attached to digital pins 4 and 5
any analog output module attached to pin A0

*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4,5); 

const int analogInPin = A0;  // Analog input pin that the sensor is attached to

int sensorValue = 0; // value read from the pot

void setup() {
  BTSerial.begin(9600); // init BT serial connection
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // print the results to the BT serial:
  BTSerial.print("output = ");
  BTSerial.println(outputValue);
  
  delay(100);
}
