void welcomeMessage();
void serial_write(String);

int main(){
    //enter setup values
    welcomeMessage();





    bool control_loop_isActive = true;
    while(control_loop_isActive){

    }

    return 0;
}

void welcomeMessage(){
    
    String welcome = "You are in stepper_speed_control./nsend speed percent.0";
    serial_write(welcome);
}

void serial_write(String message){    
    
    Serial.begin(9600); //Baud-Rate
    Serial.println(message);

}