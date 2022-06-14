#include <Servo.h>
#include <Arduino.h>

#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H
#define servoDefaultPin 22

    class servoController {
            private:
            Servo servo = Servo();

            void setServoPin(uint8_t pin);
            void openLeft(int milliseconds = 350);
            void openRight(int milliseconds = 350);
            public:
            servoController(uint8_t pinValue = servoDefaultPin);
            void openFeederFull();
            void openFeederParse();
            void closeFeeder();
    };

#endif