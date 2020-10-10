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
    Serial.println("in loop");
    if (Serial.available() > 0){
        Serial.println("reading byte");
        incomingByte = Serial.read();
        Serial.println(incomingByte);
        
        motor_speed = UI_MapMotorSpeed(incomingByte);
        Serial.println("mapped speed");
        Motor_move(motor_speed);
        Serial.println("end of control!");
    }
    delay(20);
}