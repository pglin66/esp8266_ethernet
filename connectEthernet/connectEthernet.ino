#include <SPI.h>
#include <ESP8266WiFi.h>
#include <W5500lwIP.h> // https://github.com/d-a-v/W5500lwIP
//#include <W5100lwIP.h> // https://github.com/d-a-v/W5500lwIP
//#include <ENC28J60lwIP.h> // https://github.com/d-a-v/W5500lwIP

#define CSPIN D2

Wiznet5500lwIP eth(SPI, CSPIN);
//Wiznet5100lwIP eth(SPI, CSPIN);
//ENC28J60lwIP eth(SPI, CSPIN);
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
//byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; 

void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.print(ESP.getFullVersion());
  Serial.println();
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setFrequency(4000000);

  eth.setDefault(); // use ethernet for default route
  int present = eth.begin(mac);
  if (!present) {
    Serial.println("no ethernet hardware present");
    while(1);
  }
  
  Serial.print("connecting ethernet");
  while (!eth.connected()) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.print("ethernet ip address: ");
  Serial.println(eth.localIP());
  Serial.print("ethernet subnetMask: ");
  Serial.println(eth.subnetMask());
  Serial.print("ethernet gateway: ");
  Serial.println(eth.gatewayIP());
}

void loop() {

} 
