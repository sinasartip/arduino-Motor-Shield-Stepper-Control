#include "./Include/UI.h"
#include <HardwareSerial.h>

void UI_StartMessage(){
    Serial.println("Welcome to the program");
}

int UI_MapMotorSpeed(int SerialInput){
    if (SerialInput == 56)
        return (60);
    else
        return (0);
}