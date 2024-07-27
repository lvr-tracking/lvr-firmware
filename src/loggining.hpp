#pragma once
#include "utils/date.hpp"
#include <Arduino.h>

class Logger
{
private:
    char *m_loggerName;

public:
    void log(const char *message, bool network);
    template <typename... Params>
    void logfln(const char *message, bool network, Params... params)
    {
        char buffer[255];
        sprintf(buffer, message, params...);
        Serial.printf("[%s%s] - %s\n", this->m_loggerName, current_date_formatted(), buffer);
    }
    template <typename... Params>
    void logf(const char *message, bool network, Params... params)
    {
        char buffer[255];
        sprintf(buffer, message, params...);
        Serial.printf("[%s%s] - %s", this->m_loggerName, current_date_formatted(), buffer);
    }
    Logger(char *m_loggerName);
};