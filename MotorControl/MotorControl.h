
#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
#include <AFMotor.h>

AF_DCMotor motor1(MOTOR_LEFT);
AF_DCMotor motor2(MOTOR_RIGHT);
int MOTOR_SPEED = 255/2;


void Stop();
void forward();
void left();
void right();
void backward();
void testMotor();
void setSpeed(uint8 speed);
#endif /* MOTORCONTROL_H */
