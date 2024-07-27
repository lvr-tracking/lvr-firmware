#include <FS.h>
#include <LittleFS.h>
#include "loggining.hpp"

typedef enum {
    WMANAGER_WAITING = 0,
    WMANAGER_CONNECTING = 1,
    WMANAGER_CONNECTED = 2,
    WMANAGER_CONNECTION_FAILED = 3,
    WMANAGER_CONNECTION_DISCONNECTED = 4

} wifi_manager_state;

class WiFiManager {
    private:
        Logger* logger;
    public:
        wifi_manager_state wifi_state;
        bool is_wifi_credentials_saved();
        void connect_with_saved_credentials();
        void save_credentials();
        void connect(const char* ssid, const char* pass);
        WiFiManager();
};