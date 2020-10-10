#include "./Include/Motor.h"
#include "./Include/UI.h"
#include <Stepper.h>

int incomingByte = 0;


void setup() {    
    Motor_InitPins();
    Serial.begin(9600);
    UI_StartMessage();
}

void loop(){
    //read in serial data 
    if (Serial.available() > 0){
        
        incomingByte = Serial.read();
        Serial.println(incomingByte);
        
        motor_speed = UI_MapMotorSpeed(incomingByte);
        Motor_move(motor_speed);
    }
}