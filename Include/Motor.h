#ifndef MOTOR
#define MOTOR

#ifndef STEPPER
#define STEPPER
#include <Stepper.h>
#endif

// Give the motor control pins names:
#define pwmA 3
#define pwmB 11
#define brakeA 9
#define brakeB 8
#define dirA 12
#define dirB 13

const int stepsPerRevolution = 200;
bool run_stepper = false;
int motor_speed = 0;


void Motor_InitPins();
void Motor_move(int);

#endif