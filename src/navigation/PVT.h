#pragma once
#include "StructsForData.h"

class PVT {
public:
    void PositionEstimate(GPSData gpsData, IMUData imuData);
    void VelocityEstimate(GPSData gpsData, IMUData imuData);
private:    
    
};