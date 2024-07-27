#include <Arduino.h>
#include "loggining.hpp"
#include "network/wifi/wifi.hpp"
#include "network/client/client.hpp"

Logger* SYSTEM_LOGGER;
WiFiManager* WIFI_MANAGER;
NetworkTrackingClient* NETWORK_CLIENT;


void setup() {
  Serial.begin(9600);
  Serial.println("");
  SYSTEM_LOGGER = new Logger("System");

  SYSTEM_LOGGER->log("Running LVR Tracker firmware", false);
  SYSTEM_LOGGER->logfln("Build date: %s at %s", false, __DATE__, __TIME__);

  WIFI_MANAGER = new WiFiManager();


  
  WIFI_MANAGER->connect(WIFI_SSID, WIFI_PSK);
  NETWORK_CLIENT = new NetworkTrackingClient();
}

void loop() {
  if (WIFI_MANAGER->wifi_state == WMANAGER_CONNECTED && NETWORK_CLIENT->state == CLIENT_LOOKUP_IDLE) {
    Serial.println("Looking for client...");
    NETWORK_CLIENT->lookup_for_server();
  }
}
