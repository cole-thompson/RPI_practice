#include <stdio.h>
#include "mpu9255.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

//https://projects.drogon.net/raspberry-pi/wiringpi/i2c-library/
//int wiringPiI2CRead(int fd);
//int wiringPiI2CWrite(int fd, int data);
//wiringPiI2CWriteReg8(fd, data);
//wiringPiI2CReadReg8(fd);
//negative return is error


//REGISTERS
#define DEVID				0x68
#define MPU9255_WHO_AM_I	0x75
#define MPU9255_ID			0x73

#define GYRO_CONFIG         0x1b
#define GYRO_LPF            0x1a

#define ACCEL_CONFIG        0x1c
#define ACCEL_LPF           0x1d

#define PWR_MGMT_1          0x6b
#define PWR_MGMT_2          0x6c

//H=high, L=low, high and low bytes of 16 bit data
#define ACCEL_XOUT_H        0x3b
#define ACCEL_XOUT_L        0x3c
#define ACCEL_YOUT_H        0x3d
#define ACCEL_YOUT_L        0x3e
#define ACCEL_ZOUT_H        0x3f
#define ACCEL_ZOUT_L        0x40

#define GYRO_XOUT_H			0x43
#define GYRO_XOUT_L			0x44
#define GYRO_YOUT_H			0x45
#define GYRO_YOUT_L			0x46
#define GYRO_ZOUT_H			0x47
#define GYRO_ZOUT_L			0x48


mpu9255::mpu9255() {
	if (wiringPiI2CSetup(DEVID) < 0) {
		//error
		fprintf(stderr, "error initializing i2c\n");
	}
	
	//write to registers to set up (datasheet)

	//reset imu
	wiringPiI2CWriteReg8(DEVID, PWR_MGMT_1, 0x80);
	delay(100);
	wiringPiI2CWriteReg8(DEVID, PWR_MGMT_1, 0x00);
	
	//make sure the imu is a mpu9255
	int id = wiringPiI2CReadReg8(DEVID, MPU9255_WHO_AM_I);
	if (id != MPU9255_ID) {
		fprintf(stderr, "error, not the right kind of imu\n");
	}
	
	//gyro init
	wiringPiI2CWriteReg8(DEVID, GYRO_CONFIG, 0x00);
	wiringPiI2CWriteReg8(DEVID, GYRO_LPF, 0x00);		//low pass filter

	//accel init
	wiringPiI2CWriteReg8(DEVID, ACCEL_CONFIG, 0x00);
	wiringPiI2CWriteReg8(DEVID, ACCEL_LPF, 0x00);		//low pass filter



	//sample rate 
	//wiringPiI2CWriteReg8(SMPRT_DIV, data);

	//compass init ("external sensor" registers in datasheet)

	//enable accel and gyro
	wiringPiI2CWriteReg8(DEVID, PWR_MGMT_1, 0x01);
	wiringPiI2CWriteReg8(DEVID, PWR_MGMT_2, 0x00);

	//fifo set up
	fprintf(stderr, "mpu9255 initialized\n");
}



double mpu9255::accelX() {
	return wiringPiI2CReadReg8(DEVID, ACCEL_XOUT_H);
}

double mpu9255::accelY() {
	return wiringPiI2CReadReg8(DEVID, ACCEL_YOUT_H);
}

double mpu9255::accelZ() {
	return wiringPiI2CReadReg8(DEVID, ACCEL_ZOUT_H);
}



double mpu9255::gyroX() {
	return wiringPiI2CReadReg8(DEVID, GYRO_XOUT_H);
}

double mpu9255::gyroY() {
	return wiringPiI2CReadReg8(DEVID, GYRO_YOUT_H);
}

double mpu9255::gyroZ() {
	return wiringPiI2CReadReg8(DEVID, GYRO_ZOUT_H);
}



double mpu9255::compassX() {
	return 0.0;
}

double mpu9255::compassY() {
	return 0.0;
}

double mpu9255::compassZ() {
	return 0.0;
}



