#include <Stepper.h>


Stepper myStepper = Stepper(100, 10, 10);;



void ConnectMotorShield(){
    const int pwmA = 3;
    const int pwmB = 11;
    const int brakeA = 9;
    const int brakeB = 8;
    const int dirA = 12;
    const int dirB = 13;
    const int stepsPerRevolution = 200;


    // Set the PWM and brake pins so that 
    //the direction pins can be used to control the motor:
    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
    pinMode(brakeA, OUTPUT);
    pinMode(brakeB, OUTPUT);
    digitalWrite(pwmA, HIGH);
    digitalWrite(pwmB, HIGH);
    digitalWrite(brakeA, LOW);
    digitalWrite(brakeB, LOW);

    // Set the motor speed (RPMs):
    myStepper = Stepper(stepsPerRevolution, dirA, dirB);
    myStepper.setSpeed(0);
    
}

void motor_move(int speed){
    myStepper.setSpeed(speed);
    myStepper.step(200);
}

