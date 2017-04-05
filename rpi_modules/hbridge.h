#ifndef HBRIDGE
#define HBRIDGE


class HBridgeMotor {
private:
	void clockwise();
	void counter_clockwise();
	int motorEnableA, motorEnableB, motorPWM;
public:
	HBridgeMotor(int motorEnableAPin, int motorEnableBPin, int motorPWMPin);
	void rotate(int dir);
	void setSpeed(int speed);
	void stop();
};


#endif
