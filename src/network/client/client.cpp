#include "client.hpp"

NetworkTrackingClient::NetworkTrackingClient() {
    this->logger = new Logger("Network Client");
    this->state = CLIENT_LOOKUP_IDLE;
}
client_status NetworkTrackingClient::lookup_for_server() {
    String network_address = WiFi.localIP().toString().substring(0, WiFi.localIP().toString().lastIndexOf("."));
    this->logger->logfln("network map: %s", false, network_address.c_str());
    
    WiFiUDP udp;
    udp.begin(44456);

    for (int i = 0; i < 255; i++) {
        char buffer[50];
        sprintf(buffer, "%s.%d", network_address.c_str(), i);
        udp.beginPacket(buffer, 44456);
        udp.write("owo");
        int result = udp.endPacket();
        delay(20);
        int packets = udp.parsePacket();

        if (packets > 0) {
            this->logger->logfln("Got packet on %s", false, buffer);
            int packet_size = udp.available();

            for (int i = 0; i < packet_size; i++) {
                Serial.print(char(udp.read()));
                Serial.print(" ");
            }
            Serial.println("");
        }
    }

    this->state = CLIENT_LOOKUP_FAILED;
    return CLIENT_LOOKUP_FAILED;
};