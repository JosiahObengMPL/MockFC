#pragma once
#include <Quaternion.h>
#include <cstdint>

struct State{
    xyz_t position; //position worldframe (north, east, down)
    xyz_t velocity; //velocity (ned as well)
    Quaternion attitude; //orientation
    xyz_t angularVelocity; //angular velocity
    bool newData;
};

struct IMUData{
    xyz_t accelerometer;
    xyz_t gyroscope;
    std::uint32_t timestamp;
    bool newData;
};

struct GPSData{
    double latitude;//position
    double longitude;
    float altitude;

    float velocityNorth;//velocity
    float velocityEast;
    float velocityDown;

    bool newData;
};

struct BaroData{
    float altitude;
    bool newData;
};