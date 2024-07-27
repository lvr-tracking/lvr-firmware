#include "wifi.hpp"
#include <ESP8266WiFi.h>
#include <string>

WiFiManager::WiFiManager() {
    this->wifi_state = WMANAGER_WAITING;
    this->logger = new Logger("WIFI");
}
void WiFiManager::connect_with_saved_credentials()
{
    File file = LittleFS.open("wifi.conf", "r");

    String data = file.readString();
    String ssid = data.substring(0, data.indexOf(":"));
    String passwd = data.substring(data.indexOf(":"));
    // file.write();
}

void WiFiManager::connect(const char* ssid, const char* pass) {
    this->wifi_state = WMANAGER_CONNECTING;
    this->logger->log("Setting up wifi", false);


    WiFi.hostname("lVR Wireless Tracker");

    
    wl_status_t state = WiFi.begin(ssid, pass);

    while (WiFi.status() == WL_DISCONNECTED) {
        delay(500);
        this->logger->logfln("Status: %d", false, state);
        continue;
    };

    switch (WiFi.status())
    {
    case WL_CONNECTED:
        this->wifi_state = WMANAGER_CONNECTED;
        this->logger->logfln("Connection to wifi successful. ip: %s, subnet: %s", false, WiFi.localIP().toString().c_str(), WiFi.subnetMask().toString().c_str());
        break;
    case WL_NO_SSID_AVAIL:
    case WL_WRONG_PASSWORD:
    case WL_CONNECT_FAILED:
    case WL_DISCONNECTED:
        this->wifi_state = WMANAGER_CONNECTION_FAILED;
        this->logger->logfln("Failed to connect to network: %d", false, state);
        break;
    default:

        break;
    }
}