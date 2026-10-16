#pragma once
#include "StructsForData.h"
#include "sensors/IMU.h"

class DeadReckoning{
public:
    Quaternion updateAttitude(const Quaternion& attitude, const IMUData& imuData, float dt);
private:

};