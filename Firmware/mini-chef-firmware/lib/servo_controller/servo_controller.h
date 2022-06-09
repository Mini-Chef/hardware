#include <Servo.h>
#include <Arduino.h>

#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

    Servo servo;  
    uint8_t servoDefaultPin = 22;    


    class servoContrller {
        private:
            // Setters
        void setServoPin(u_int8_t pin){
            servo.attach( pin );
        }
        void openLeft(int milliseconds = 350){
            servo.write(170);
            delay(milliseconds);
        }
        void openRight(int milliseconds = 350){
            servo.write(0);
            delay(milliseconds);
        }
        public:
        servoContrller(uint8_t pinValue = servoDefaultPin){
            setServoPin(pinValue);
            closeFeeder();
        }
        void openFeederFull(){
            openLeft();
            delay(400);
            openRight();
            delay(400);
            
        }
        void openFeederParse(){
           openRight();
        }
        void closeFeeder(){
            servo.write(82);
        }
    };

#endif