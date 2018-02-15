//Author: UCSC SHPE Familia
//Created on: May 4th (May the fourth be with you)
//Purpose: The purpose of this project is to get
//members familiar with sensors like bluetooth and
//proximety. Hope you all enjoy! :)

#include <AFMotor.h>
#include <SoftwareSerial.h>

//****************************************//
//      BLUE TOOTH COMMANDS SET UP        //
//****************************************//
#define rxPin 2
#define txPin 3
#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define STOP 'r'
#define FASTER '='
#define SLOWER '-'


char myCommand ;
SoftwareSerial BlueTooth(rxPin, txPin); // RX, TX


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

//Max motor speed is 255
int MOTOR_SPEED = 255/2;
#define MOTOR_LEFT 3
#define MOTOR_RIGHT 4

AF_DCMotor motor1(MOTOR_LEFT);
AF_DCMotor motor2(MOTOR_RIGHT);

void Stop();
void forward();
void left();
void right();
void backward();
void testMotor();
void fasterSpeed();
void slowerSpeed();
int ledPin = 13;


void eXecute(char myCommand);

void setup() {
  Serial.begin(9600);

  Serial.println("Initializing . . . ");
  BlueTooth.begin(9600);
  Serial.print(myCommand);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("Done with Setup");
  testMotor(); //Order goes Forward backward, left then right turn.
}

void loop() {

  while (BlueTooth.available()) {
    myCommand = BlueTooth.read();
    eXecute(myCommand);
  }
  
 
}




//****************************************//
//     BLUETOOTH HELPER FUNCTIONS         //
//****************************************//

void eXecute(char myCommand) {
  Serial.print(" command entered: ");
  Serial.println(myCommand);
    
  switch (myCommand) {
    case UP:
      forward();
      break;
    case LEFT:
      left();
      break;
    case RIGHT:
      right();
      break;
    case DOWN:
      backward();
      break;
    case STOP:
      Stop();
      break;
    case FASTER:
      fasterSpeed();
      break;
    case SLOWER:
      slowerSpeed();
      break;
  }
  //Prints a new line every time you press a new command
  static char lastCommand = ' ';
  if (lastCommand == myCommand) {
    Serial.println();
  }

}


//****************************************//
//     MOTOR HELPER FUNCTIONS             //
//****************************************//


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

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off

}


void fasterSpeed() {
    if((MOTOR_SPEED+10) < 255) {
      MOTOR_SPEED += 10; 
    }
  }
void slowerSpeed() {
    if((MOTOR_SPEED-10) > 0) {
      MOTOR_SPEED -= 10; 
    }
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
    Stop();
  }
