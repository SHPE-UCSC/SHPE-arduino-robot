//Author: UCSC SHPE Familia
//Created on: May 4th (May the fourth be with you)
//Purpose: The purpose of this project is to get
//members familiar with sensors like bluetooth and
//proximety. Hope you all enjoy! :)

#include <MotorControl.h>
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
//     BLUETOOTH HELPER FUNCTION				         //
//****************************************//

void eXecute(char myCommand) {
  Serial.print(" command entered: ");
  Serial.println(myCommand);
    
//****************************************//
//						ADD CODE HERE				            //
//****************************************//









//****************************************//
//						END OF CODE SEGMENT					//
//****************************************//

  //Prints a new line every time you press a new command
  static char lastCommand = ' ';
  if (lastCommand == myCommand) {
    Serial.println();
  }

}
