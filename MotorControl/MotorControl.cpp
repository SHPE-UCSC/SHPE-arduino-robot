#include "Arduino.h"
#include "MotorControl.h"

//****************************************//
//        MOTORS SET UP                   //
//****************************************//
// Replace 2 and 1 with the numbers you connect your motors in
//the following is the wire set up for M1 and M2

//   RED   //  M1
//   BLACK //  M1
//   x     //  GND
//   x     //  M2
//   x     //  M2

//   BLACK   //  M3
//   RED     //  M3
//   x       //  GND
//   x       //  M4
//   x       //  M4

static int MOTOR_SPEED = MAXRUN;
static AF_DCMotor motor1(MOTOR_LEFT);
static AF_DCMotor motor2(MOTOR_RIGHT);

void halt()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off

}

void left()
{
  motor1.setSpeed(MOTOR_SPEED*3/4); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise

  motor2.setSpeed(MOTOR_SPEED*3/4);
  motor2.run(BACKWARD); //turn motor2 off
}

void right()
{
  motor1.setSpeed(MOTOR_SPEED*3/4);
  motor1.run(BACKWARD); //turn motor1 off

  motor2.setSpeed(MOTOR_SPEED*3/4); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void forward()
{
  motor1.setSpeed(MOTOR_SPEED); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise

  motor2.setSpeed(MOTOR_SPEED); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void backward()
{
  motor1.setSpeed(MOTOR_SPEED);
  motor1.run(BACKWARD); //rotate the motor counterclockwise

  motor2.setSpeed(MOTOR_SPEED);
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void testMotor() {
    delay(500);
    forward();
    delay(1000);
    backward();
    delay(1000);
    left();
    delay(1000);
    right();
    delay(1000);
    halt();
  }
  
 void fasterSpeed() {
	 if (MOTOR_SPEED < MAXSPEED) {
		MOTOR_SPEED += 10;
		if(MOTOR_SPEED > MAXSPEED) {
			MOTOR_SPEED = MAXSPEED;
		}
	 }
  }
void slowerSpeed() {
    if (MOTOR_SPEED > MINSPEED) {
		MOTOR_SPEED -= 10;
		if(MOTOR_SPEED < MINSPEED) {
			MOTOR_SPEED = MINSPEED;
		}
	 }
  }