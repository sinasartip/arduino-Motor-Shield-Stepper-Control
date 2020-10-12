void welcomeMessage();
void serial_write(String[],int);
int readin_speed();
void motor_move(int);

 int speed;

void setup(){
   
    welcomeMessage();
}

void loop(){

    if(Serial.available() > 0)
        speed = readin_speed();
        motor_move(speed);
        Serial.println(speed);

}

void welcomeMessage(){
    int number_of_message = 2;
    String welcome[] = {"You are in stepper_speed_control.",
                        "send speed as a percent."};
    
    serial_write(welcome,number_of_message);
}

int readin_speed(){
    char incomingByte;
    incomingByte = Serial.read();

    return(atoi(&incomingByte));


}

void motor_move(int speed){
    
}

void serial_write(String message[],int size){    
    Serial.begin(115200); //Baud-Rate
    for(int i=0;i < size; i++)
        Serial.println(message[i]);

}