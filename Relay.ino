/*
 Relay

 Turns on and off a Relay Module connected to O0,
 when pressing a Button Module attached to I0.
 http://www.tinkerkit.com/button/
 http://www.tinkerkit.com/relay/

 This example code is in the public domain.
 
 created in Dec 2011
 by Federico Vanzati
 modified in Jun 2013
 by Matteo Loglio<http://matlo.me>
 
 This example code is in the public domain.
 */

// include the TinkerKit library
#include <TinkerKit.h>
#include <math.h>
#include <SPI.h>
#include <Ethernet.h>

TKButton btn(I0);    // creating the object 'led' that belongs to the 'TKLed' class 
		     // and giving the value to the desired output pin

TKMosFet relay(O1);  // creating the object 'relay' that belongs to the 'TKRlay' class 
                     // and giving the value to the desired output pin
                 
TKThermistor therm(I3);       // creating the object 'therm' that belongs to the 'TKThermistor' class 
                              // and giving the value to the desired output pin


/******************** ETHERNET SETTINGS ********************/

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x85, 0xD9 };   //physical mac address
byte ip[] = { 192, 168, 86, 112 };                   // ip in lan
byte subnet[] = { 255, 255, 255, 0 };              //subnet mask
byte gateway[] = { 192, 168, 0, 1 };              // default gateway
EthernetServer server(80);                       //server port


                              
int trigger = 76;
float C, F;

void setup() {
 // initialize serial communications at 9600 bps
  Serial.begin(9600);
  Ethernet.begin(mac,ip,gateway,subnet);      // initialize Ethernet device
server.begin();                                // start to listen for clients
   
}

void loop() {

  
   if(GetTemp() > trigger) {
    relay.on();
  }
  else{
    relay.off();



  
 EthernetClient client = server.available();    // look for the client

// send a standard http response header

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connnection: close");
client.println();

/* 
This portion is the webpage which will be
sent to client web browser one can use html , javascript
and another web markup language to make particular layout 
*/

client.println("<!DOCTYPE html>");      //web page is made using html
client.println("<html>");
client.println("<head>");
client.println("<title>Ethernet Tutorial</title>");
client.println("<meta http-equiv=\"refresh\" content=\"1\">");

/*
The above line is used to refresh the page in every 1 second
This will be sent to the browser as the following HTML code:
<meta http-equiv="refresh" content="1">
content = 1 sec i.e assign time for refresh 
*/

client.println("</head>");
client.println("<body>");
client.println("<h1>fan status </h1>");
client.println("<h2>Observing State Of Relay</h2>");

client.println("</body>");
client.println("</html>");

delay(1);          // giving time to receive the data
client.stop();
   
  }
  

  
}





float GetTemp() {
  delay(3000);
  float temp = therm.readFahrenheit();
  Serial.println(temp);
  return(temp);
  
}
