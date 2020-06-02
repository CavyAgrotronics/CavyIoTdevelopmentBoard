/*
"CavyIoT.nodemcu-V0.03.bin" 

CavyIoTdevelopment board firmware download for IC ESP8266  and NodeMCU 1.0(ESP-12E Module)
*/
#include <ESP8266httpUpdate.h>
const char* ssid =     "WiFiSSID";     // Set your router SSID
const char* password = "WiFiPassword"; // Set your router password
void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
                       Serial.print(".");
                       delay(500);
                               }
  Serial.print("Downloding.........Wait  2 to 3 minutes for update...");
  t_httpUpdate_return ret = ESPhttpUpdate.update("http://www.developers.cavyiot.com/downloads/CavyIoT.nodemcu-V0.03.bin"); 
   switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;
    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;
    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
  }
  Serial.println(".....Done!"); 
}

void loop() {
// ...
}
