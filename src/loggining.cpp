#include <loggining.hpp>
#include <Arduino.h>
#include <time.h>


void Logger::log(const char *message, bool network)
{

    if (network)
    {
        Serial1.println("Network loggining: not implemented");
        return;
    }

    Serial.printf("[%s%s] - %s\n", this->m_loggerName, current_date_formatted(), message);
}

Logger::Logger(char* m_loggerName) {
    this->m_loggerName = m_loggerName;
}