#include <Quaternion.h>
#include "DeadReckoning.h"
//this should take in only gyro data and output an attitude quaternion
Quaternion DeadReckoning::updateAttitude(const Quaternion& attitude, const IMUData& imuData, float dt){
    xyz_t gyro = imuData.gyroscope;
    float angle = gyro.magnitude() * dt; // integrate angular velocity to get angle
    if (angle < 1e-6 || dt <= 0.0f) {
        return attitude; // no significant rotation
    }
    xyz_t axis = gyro.normalized(); // get the rotation axis
    float halfAngle = angle * 0.5f;
    Quaternion deltaQ = 
        Quaternion(cos(halfAngle), 
        axis.x * sin(halfAngle), 
        axis.y * sin(halfAngle), 
        axis.z * sin(halfAngle));
    Quaternion updated = attitude * deltaQ; // apply the rotation to the current attitude
    updated.normalize();
    return updated;
}
