#include "Controller.h"
#include "Messaging.h"
#include <Stepper.h>



int speed;

void setup(){
   
    welcomeMessage();
    ConnectMotorShield();
    myStepper.setSpeed(80);
}

void loop(){

    if(Serial.available() > 0){
        speed = readin_speed();
        motor_move(speed);
  
    }

}

