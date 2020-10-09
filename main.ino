// Include the Stepper library:
#include <Stepper.h>
// Define number of steps per revolution:
const int stepsPerRevolution = 200;
// Give the motor control pins names:
#define pwmA 3
#define pwmB 11
#define brakeA 9
#define brakeB 8
#define dirA 12
#define dirB 13
// Initialize the stepper library on the motor shield:
Stepper myStepper = Stepper(stepsPerRevolution, dirA, dirB);
bool run_stepper = false;
int incomingByte = 0; 

void setup() {
  // Set the PWM and brake pins so that the direction pins can be used to control the motor:
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  // Set the motor speed (RPMs):
  myStepper.setSpeed(60);
}
void loop() {
    while (run_stepper == true){  
        // Step one revolution in one direction:
        myStepper.step(200);
        delay(2000);
        //Step on revolution in the other direction:
        myStepper.step(-200);
        delay(2000);
    }
    //read in serial data 
    if (Serial.available() > 0){
        incomingByte = Serial.read();
    }

    if (incomingByte == 13){
        run_stepper = true;
        incomingByte = 0; //just ot reset the Byte
    }

}