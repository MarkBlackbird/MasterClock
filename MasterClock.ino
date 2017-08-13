#include <Wire.h>

unsigned long newSecond = 0;
unsigned long seconds = 0;
unsigned long hours = 0;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  newSecond=millis()+1000;
}

void loop() {
  while(millis()<newSecond)
  {
    delay(1);
  }
  newSecond=newSecond+1000;
  if(seconds==4294967295)
  {
    seconds = 0;
    hours++;
  }else{
    seconds++
  }
  Wire.beginTransmission(10); // transmit to device #8
  Wire.write(seconds);
  Wire.endTransmission();    // stop transmitting
  Wire.beginTransmission(11); // transmit to device #8
  Wire.write(hours);
  Wire.endTransmission();    // stop transmitting

}
