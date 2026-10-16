#include "IMU.h"
void IMU::begin() {
    if (!bno.begin()) {
        Serial.println("BNO055 not found");
        while (1);
    }
    bno.setExtCrystalUse(true);
    bno.setMode(OPERATION_MODE_AMG);
}
IMUData IMU::readIMU() {
    IMUData imuRead;
    imuRead.newData = false;

    imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
    imu::Vector<3> gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

    imuRead.accelerometer.x = accel.x();
    imuRead.accelerometer.y = accel.y();
    imuRead.accelerometer.z = accel.z();

    imuRead.gyroscope.x = gyro.x()*3.1415926/180.0; //rad/s
    imuRead.gyroscope.y = gyro.y()*3.1415926/180.0;
    imuRead.gyroscope.z = gyro.z()*3.1415926/180.0;

    imuRead.timestamp = micros();
    imuRead.newData = true;
    return imuRead;
}