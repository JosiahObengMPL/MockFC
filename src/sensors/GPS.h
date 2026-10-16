#pragma once
#include <Arduino.h>
#include "SparkFun_u-blox_GNSS_Arduino_Library.h"
#include "navigation/StructsForData.h"
class GPS {
public:
    void begin();
    GPSData readGPS();
private:
    SFE_UBLOX_GNSS gps;
};