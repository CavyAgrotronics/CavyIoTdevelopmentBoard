 /* Tested with CavyIoT.nodemcu-V0.03
   
  * Prints the current status of Buttons & working mode of device on Remote Control Panel. https://developers.cavyiot.com/cpanel.php 
 
   Ayush Khade 02 jun 2020 
 */
 
#include "CavyIoTdevelopmentBoard.h"
CavyIoT myIoTdevice;
int rx=10;
int tx=11;
int rst=13;
void setup()
{
 Serial.begin(9600);
 myIoTdevice.SetPort(rx,tx,rst);
 myIoTdevice.ShowDemo("WifiSSID","WIFiPassword",/*CavyIoT credential->*/"cavyiot-username","password","device");
 }
 void loop() {
   Serial.println("Device Status:-"+myIoTdevice.Status);
   myIoTdevice.loop();//Updates the Status variable.
}
