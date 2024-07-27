#pragma once
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "loggining.hpp"

typedef enum
{
    CLIENT_LOOKUP_FAILED = 0,
    CLIENT_LOOKUP_SEARCHING = 1,
    CLIENT_LOOKUP_FOUND = 2,
    CLIENT_LOOKUP_IDLE = 3
} client_status;

class NetworkTrackingClient
{
    private:
        char* server_ip;
        size_t server_port;
        Logger* logger;
    public:
        client_status lookup_for_server();
        NetworkTrackingClient();
        client_status state;
};