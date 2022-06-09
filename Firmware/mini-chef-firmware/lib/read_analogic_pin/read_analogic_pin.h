#include <Arduino.h>

#ifndef READ_ANALOGIC_PIN_H
#define READ_ANALOGIC_PIN_H

    uint8_t defaultPin = 34;

    class readAnalogicPin {
        private:
            uint8_t pin;
            uint16_t lastRead = -1;
            uint16_t read = -1;

            // Private Setters
            void setLastRead(uint16_t* value){
                lastRead = *value;
            }
            void setRead(uint16_t* value){
                read = *value;
            }
            void setPin(uint8_t Pin){
                pin = Pin;
            }
        public:
            // Constructor
            readAnalogicPin(uint8_t Pin = defaultPin){
                pin = Pin;
            }
            
            void readPin(uint16_t* value){
                uint16_t tmpRead = analogRead(pin);
                setLastRead(&read);
                setRead(&tmpRead);
                *value = tmpRead;
            }
        
           
            // Getters
            void getRead(uint16_t* value){
                *value = read;
            }
            void getLastRead(uint16_t* value){
                *value = lastRead;
            }
    };

#endif