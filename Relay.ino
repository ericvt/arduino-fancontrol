
// include the TinkerKit library
#include <TinkerKit.h>
#include <math.h>

TKLed led(O0); // creating the object 'led' that belongs to the 'TKLed' class 
   // and giving the value to the desired output pin


TKMosFet relay(O1);  // creating the object 'relay' that belongs to the 'TKRlay' class 
                     // and giving the value to the desired output pin
                 
TKThermistor therm(I3);       // creating the object 'therm' that belongs to the 'TKThermistor' class 
                              // and giving the value to the desired output pin
int high_trigger = 75;
int low_trigger = 73; 
float C, F;
void setup() {
 // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  if(GetTemp() > high_trigger) {
    relay.on();
    led.on();
  }
  if(GetTemp() < low_trigger) {
    relay.off();
    led.off();
  }
}

float GetTemp() {
  float temp = therm.readFahrenheit();
  delay(1000);
  Serial.println (temp);
  return(temp);
}
