#include "servo_controller.h"

servoController::servoController(uint8_t pinValue){
    setServoPin( pinValue );
    closeFeeder();
}

void servoController::setServoPin(uint8_t pin){
    servo.attach( pin );
}

void servoController::openLeft(int milliseconds){
    servo.write(170);
    delay(milliseconds);
}

void servoController::openRight(int milliseconds){
    servo.write(0);
    delay(milliseconds);
}

void servoController::openFeederFull(){
    openLeft();
    delay(400);
    openRight();
    delay(400);
}

void servoController::openFeederParse(){
    openRight();
    delay(400);
}

void servoController::closeFeeder(){
    servo.write(82);
}