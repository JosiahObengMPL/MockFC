#pragma once
#include <Adafruit_BNO055.h>
#include "navigation/StructsForData.h"
class IMU {
public:
    void begin();
    IMUData readIMU();
private:
    Adafruit_BNO055 bno;
};