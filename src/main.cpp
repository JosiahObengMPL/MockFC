#include <Arduino.h>
#include <Wire.h>
#include "sensors/IMU.h"
#include "sensors/GPS.h"
#include "navigation/StructsForData.h"

//define functions here
//declare objects here
IMU imuData;
GPS gpsData;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  delay(1000);
  Wire.begin();
  Quaternion attitude (1.0f, 0.0f, 0.0f, 0.0f); // Initial attitude quaternion
  imuData.begin();
}
void loop() {
  IMUData imuReading = imuData.readIMU();

  Serial.print("ACC: ");
  Serial.print(imuReading.accelerometer.x);
  Serial.print(", ");
  Serial.print(imuReading.accelerometer.y);
  Serial.print(", ");
  Serial.print(imuReading.accelerometer.z);

  Serial.print(" GYRO: ");
  Serial.print(imuReading.gyroscope.x);
  Serial.print(", ");
  Serial.print(imuReading.gyroscope.y);
  Serial.print(", ");
  Serial.println(imuReading.gyroscope.z);

  delay(100);
}