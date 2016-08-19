#include <Adafruit_ADS1115.h>
#include <Wire.h>

Adafruit_ADS1115 ads(0x49); //address 0x49 connects VDD to ADDR

float gainFactor = 0.03125; //dependent on the gain
float voltage;

void setup(void) {
  Serial.begin();
  ads.setGain(GAIN_FOUR);
  ads.begin();
}

void loop(void) 
{
  int16_t adc0;  
  adc0 = ads.readADC_SingleEnded(1);
  voltage = (adc0 * gainFactor)/1000;
  //Serial.print("Value: ");
  //Serial.print(adc0);
  //Serial.print("\tVoltage: ");
  Serial.print(voltage,7); //Serial.print(" ");
  Serial.println();
  delay(2);
}
