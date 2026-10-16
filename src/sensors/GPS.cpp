#include "GPS.h"
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
// GPS FIRST

void GPS::begin(){
    gps.begin(Serial1); //initialize gps
    if (!gps.begin(Serial1)) {
        Serial.println("GPS not found"); //let us know if communication fails
        while (1);
    }
    Serial.println("GPS found");
    gps.setNavigationFrequency(10); // Set update frequency to 10 Hz
    
}
GPSData GPS::readGPS(){
    GPSData gpsData;

    ///
    return gpsData;
}