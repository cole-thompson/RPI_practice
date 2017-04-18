#include <stdio.h>
#include <vector>
#include <wiringPi.h>
#include "hbridge.h"
#include "mpu9255.h"


int motorEnableA[] = { 5, 13 };
int motorEnableB[] = { 6, 19 };
int motorPWM[] = { 20, 21 };

void motorTest();
void imuTest();


int main(int argc, char*argv[]) {
	//some basic assurance that wiringpi setup is only called once
	#ifndef WIRINGPIINIT
	#define WIRINGPIINIT
		wiringPiSetupGpio();
	#endif

	imuTest();
	//motorTest();
}

void motorTest() {
	std::vector<HBridgeMotor> motors;
	for (int i = 0; i < 2; i++) {
		motors.push_back(HBridgeMotor(motorEnableA[i], motorEnableB[i], motorPWM[i]));
	}

	motors[0].setSpeed(500);
	motors[0].rotate(1);

	for (int i = 0; i < 100000000; i++) {}

	motors[0].rotate(0);
	for (int i = 0; i < 100000000; i++) {}


	motors[0].stop();
	fprintf(stderr, "motors stopped\n");

}

void imuTest() {
	mpu9255 imu = mpu9255();
	while (true) {
		int gyroX = imu.gyroX();
		int gyroY = imu.gyroY();
		int gyroZ = imu.gyroZ();
		int accelX = imu.accelX();
		int accelY = imu.accelY();
		int accelZ = imu.accelZ();

		printf("gyro: x%d y%d z%d \t| accel: x%d y%d z%d\n", gyroX, gyroY, gyroZ, accelX, accelY, accelZ);
		delay(100);
	}
}
