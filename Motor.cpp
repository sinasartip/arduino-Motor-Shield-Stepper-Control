#include <Stepper.h>
#include "./Include/Motor.h"


Stepper myStepper = Stepper(stepsPerRevolution, dirA, dirB);

void Motor_InitPins(){
  // Set the PWM and brake pins so that the direction pins can be used to control the motor:
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeA, LOW);
  
  digitalWrite(brakeB, LOW);
  
}

void Motor_move(int direction_speed){
    myStepper.setSpeed(10);
    myStepper.step(200);
}