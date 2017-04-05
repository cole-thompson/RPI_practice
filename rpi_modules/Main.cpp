#include <stdio.h>
#include <vector>
#include "hbridge.h"



int motorEnableA[] = { 5, 13 };
int motorEnableB[] = { 6, 19 };
int motorPWM[] = { 20, 21 };


int main(int argc, char*argv[]) {
	//some basic assurance that wiringpi setup is only called once
	#ifndef WIRINGPIINIT
	#define WIRINGPIINIT
		wiringPiSetupGpio();
	#endif


	std::vector<HBridgeMotor> motors;
	for (int i = 0; i < 2; i++) {
		motors.push_back(HBridgeMotor(motorEnableA[i], motorEnableB[i], motorPWM[i]));
	}

	motors[0].setSpeed(10);
	motors[0].rotate(1);

	for (int i = 0; i < 100000000; i++) {}
	
	motors[0].rotate(0);
	for (int i = 0; i < 100000000; i++) {}
	
	
	motors[0].stop();
	fprintf(stderr, "motors stopped\n");
}
