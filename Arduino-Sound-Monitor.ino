#include <TimerOne.h>
#include <ADS1115_WE.h>
#include <Wire.h>

#define I2C_ADDRESS 0x48

int faADC  = 860;
ADS1115_WE adc = ADS1115_WE(I2C_ADDRESS);

// Analoge Eingänge
int adcChannel = 0;  // A0
int adcValue = 0;
void setup() {
  Wire.begin();
  Serial.begin(115200);
  // put your setup code here, to run once:
  if(!adc.init()){
    Serial.println("ADS1115 not connected!");
  }
  else
  {
    Serial.println("ADS1115 found!");         
  }
  adc.setVoltageRange_mV(ADS1115_RANGE_4096);   
  adc.setCompareChannels(ADS1115_COMP_0_GND);
  adc.setConvRate(ADS1115_860_SPS);              
  adc.setMeasureMode(ADS1115_CONTINUOUS);

  Timer1.initialize(1000000/faADC);             
  Timer1.attachInterrupt(readADC);   
  Timer1.start();
}

void loop() {
  adcValue = adc.getRawResult();
//  Serial.print("ADC:");
//  Serial.println(adcValue);
}

void readADC() {
  Serial.print("ADC:");
  Serial.println(adcValue);
}

void serialEvent() {
  char inChar = Serial.read();
  if (inChar == 's') {   // 's'top
    Timer1.stop();
  }
  if (inChar == 't') {   //  restar't'
    Timer1.restart();
  }
}
