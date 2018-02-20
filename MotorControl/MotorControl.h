#ifndef _MOTORCONTROL_H_
#define _MOTORCONTROL_H_

#include <AFMotor.h>

#define MAXSPEED	255
#define MAXRUN		MAXSPEED / 2
#define MINSPEED		0

#define MOTOR_LEFT 3
#define MOTOR_RIGHT 4

void halt();
void left();
void right();
void forward();
void backward();
void testMotor();
void fasterSpeed();
void slowerSpeed();

#endif /* _MOTORCONTROL_H_ */
