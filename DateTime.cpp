#include "DateTime.h"




     string DateTime::getCurrentDateTime()
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime;
        localtime_s(&localTime, &currentTime);

        stringstream ss;
        ss << put_time(&localTime, "%d/%m/%Y %H:%M:%S");

        return ss.str();
    }




