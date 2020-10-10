
int incomingByte = 0;
int motor_speed = 0;

void setup() {
    UI.being();
    Motor.begin()
    Serial.begin(9600);
}

void loop(){
    //read in serial data 
    if (Serial.available() > 0){
        incomingByte = Serial.read();
        Serial.println(incomingByte);
        if (incomingByte <= 100 && incomingByte >= -100){
            motor_speed = UI.motor_input(incomingByte);
            Motor.move(motor_speed);
        }
    }
}