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
#define UP 'A'
#define LEFT 'C'
#define RIGHT 'D'
#define DOWN 'B'
#define STOP 'E'

#define ON  'n'


char myCommand ;
SoftwareSerial BlueTooth(rxPin, txPin); // RX, TX

//****************************************//
//      DISTANCE SENSOR SET UP            //
//****************************************//

const int trigPin = 19;
const int echoPin = 18;
long duration;
int distanceCM;

#define DISTANCE_TO_STOP 10


//****************************************//
//      POT SET UP                        //
//****************************************//

#define PIN_POT 17


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
int MOTOR_SPEED = 255;
#define MOTOR_LEFT 3
#define MOTOR_RIGHT 4

AF_DCMotor motor1(MOTOR_LEFT);
AF_DCMotor motor2(MOTOR_RIGHT);

void Stop();
void forward();
void left();
void right();
void back();

int ledPin = 13;


void eXecute(char myCommand);

void setup() {
  Serial.begin(9600);

  Serial.println("Goodnight moon!");
  BlueTooth.begin(9600);
  forward();   //Motors are initially stopped
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.print(myCommand);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {

  //Controlling the motor speed base on the POT
  //int temp = analogRead(PIN_POT); // gives range from 1023-0
  //MOTOR_SPEED = analogRead(temp/4); //Motor speed rangge 255-0
  //MOTOR_SPEED = 255; 
  
  while (BlueTooth.available()) {
    myCommand = BlueTooth.read();
    eXecute(myCommand);
  }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCM = duration * .034 / 2;
  if (distanceCM == 0) {
    distanceCM = DISTANCE_TO_STOP + 2; //0cm means nothing was detected ie. no wall
  }

  //Counter is a safeguard from false signals
  //The trade off to this is a slighter delay in stopping
  static int counter = 0;
  if (distanceCM < DISTANCE_TO_STOP) {
    counter++;
  }
  if (distanceCM < DISTANCE_TO_STOP && counter == 5) {
    counter = 0;
    Serial.print(distanceCM);
    Serial.println(" cm");
    Stop();
    //while (1); // GAME OVER!
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
      back();
      break;
    case STOP:
      Stop();
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

void back()
{
  motor1.setSpeed(MOTOR_SPEED);
  motor1.run(BACKWARD); //rotate the motor counterclockwise

  motor2.setSpeed(MOTOR_SPEED);
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
  motor1.setSpeed(MOTOR_SPEED); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}

void right()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
  
  motor2.setSpeed(MOTOR_SPEED); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off

}

