
// include the TinkerKit library
#include <TinkerKit.h>
#include <math.h>

TKButton btn(I0);    // creating the object 'led' that belongs to the 'TKLed' class 
		     // and giving the value to the desired output pin

TKMosFet relay(O1);  // creating the object 'relay' that belongs to the 'TKRlay' class 
                     // and giving the value to the desired output pin
                 
TKThermistor therm(I3);       // creating the object 'therm' that belongs to the 'TKThermistor' class 
                              // and giving the value to the desired output pin
int trigger = 76;
float C, F;
void setup() {
 // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {


 GetTemp();

  if(therm.readFahrenheit() > trigger) {
    relay.on();
  }
  else{
    relay.off();
  }
}


float Thermister(float RawADC) {  //Function to perform the fancy math of the Steinhart-Hart equation
 float Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;              // Convert Kelvin to Celsius
 Temp = (Temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius
 return Temp;
}


float GetTemp() {
 
  float temp = therm.readFahrenheit();
  delay(1000);
  Serial.println (temp);
  
}
