# arduino-fancontrol
Arduino controls relay, connected to fans, and turns off and on based on temperature.


## Needs:
Arduino
Tinkerkit sheild 
Tinkerkit thermister
Tinkerkit relay
Some way of connecting the high power to a fan going through relay.



## Setup

Attach tinkerkit sheild to Arduino
connect relay to pin 01 on the "Output" side
connect thermister on pin I3 on the "Imput" side


## Starting

Download the Arduino IDE (https://www.arduino.cc/en/Main/Software) or use the online (never used it before)
It is also on Microsoft Store, but not sure about Apple.

Download this repo

put the Tinkerkit folder in Documents\Arduino\libraries (if on windows)

Now open Relay.ino and send it to your arduino. it will now start. It is now possible to disconnect from your computer. you can connect the usb or the power to anything else as the arduino remembers.
