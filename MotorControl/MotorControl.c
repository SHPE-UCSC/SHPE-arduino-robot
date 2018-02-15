
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

  void setSpeed(uint8 speed) {
    MOTOR_SPEED = speed/2;  //full speed is too fast with 9v 
  }
