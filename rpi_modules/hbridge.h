#ifndef HBRIDGE
#define HBRIDGE

int initHbridge();
void rotate(int motor_number, int dir);
void setSpeed(int motor_number, int speed);
void stop(int motor_number);

#endif