#include <stdio.h>
#include "hbridge.h"
#include <wiringPi.h>



HBridgeMotor::HBridgeMotor(int motorEnableAPin, int motorEnableBPin, int motorPWMPin) {
	//some basic assurance that wiringpi setup is only called once
	#ifndef WIRINGPIINIT
	#define WIRINGPIINIT
		wiringPiSetupGpio();
	#endif

	motorEnableA = motorEnableAPin;
	motorEnableB = motorEnableBPin;
	motorPWM = motorPWMPin;


	for (int i = 0; i < 2; i++) {
		pinMode(motorEnableA, OUTPUT);
		pinMode(motorEnableB, OUTPUT);
		pinMode(motorPWM, OUTPUT);
	}

	fprintf(stderr, "h-bridge motor gpio initialized\n");

}

void HBridgeMotor::setSpeed(int speed) {
	if (0 < speed <= 1000) {
		digitalWrite(motorPWM, HIGH);
		//wiringpi.softPwmWrite(pins.motorPWM[motor_number], speed)
	}
	else {
		digitalWrite(motorPWM, LOW);
		//wiringpi.softPwmWrite(pins.motorPWM[motor_number], 0)
	}
}

void HBridgeMotor::clockwise() {
	digitalWrite(motorEnableA, HIGH);
	digitalWrite(motorEnableB, LOW);
}

void HBridgeMotor::counter_clockwise() {
	digitalWrite(motorEnableA, LOW);
	digitalWrite(motorEnableB, HIGH);
}

void HBridgeMotor::rotate(int dir) {
	if (dir == 1) {
		clockwise();
	}
	else {
		counter_clockwise();
	}
}

void HBridgeMotor::stop() {
	setSpeed(0);
	digitalWrite(motorEnableA, LOW);
	digitalWrite(motorEnableB, LOW);
}
