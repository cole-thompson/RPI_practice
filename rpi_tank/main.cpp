#include <stdio.h>
#include <wiringPi.h>

int motorEnableA[] = { 0, 0 };
int motorEnableB[] = { 0, 0 };
int motorPWM[] = { 0, 0 };


int main(int argc, char*argv[]) {
	init();

}

int init() {
	wiringPiSetupGpio();

	for (int i = 0; i < 2; i++) {
		pinMode(motorEnableA[i], OUTPUT);
		pinMode(motorEnableB[i], OUTPUT);
		pinMode(motorPWM[i], OUTPUT);
	}

	fprintf(stderr, "h-bridge gpio initialized");
}

void rotate(int motor_number, int speed, int dir) {
	if (dir == 1) {
		clockwise(motor_number, speed);
	}
	else {
		counter_clockwise(motor_number, speed);
	}
}

void clockwise(int motor_number, int speed) {
	setSpeed(motor_number, speed);
	digitalWrite(motorEnableA[motor_number], HIGH);
	digitalWrite(motorEnableB[motor_number], LOW);
}

void counter_clockwise(int motor_number, int speed) {
	setSpeed(motor_number, speed);
	digitalWrite(motorEnableA[motor_number], LOW);
	digitalWrite(motorEnableB[motor_number], HIGH);
}

void stop(int motor_number) {
	setSpeed(motor_number, 0);
	digitalWrite(motorEnableA[motor_number], LOW);
	digitalWrite(motorEnableB[motor_number], LOW);
}

void setSpeed(int motor_number, int speed) {
	if (0 < speed <= 1000) {
		digitalWrite(motorPWM[motor_number], HIGH);
		//wiringpi.softPwmWrite(pins.motorPWM[motor_number], speed)
	}
	else {
		digitalWrite(motorPWM[motor_number], LOW);
		//wiringpi.softPwmWrite(pins.motorPWM[motor_number], 0)
	}
}