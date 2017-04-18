#ifndef MPU9255
#define MPU9255

class mpu9255 {
private:
	int fd;	
	double readHighLowData(int regH, int regL);

public:
	mpu9255();

	double gyroX();
	double gyroY();
	double gyroZ();

	double accelX();
	double accelY();
	double accelZ();

	double compassX();
	double compassY();
	double compassZ();

	void read();
};


#endif
