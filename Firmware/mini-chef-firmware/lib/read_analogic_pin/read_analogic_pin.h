#include <Arduino.h>

#ifndef READ_ANALOGIC_PIN_H
#define READ_ANALOGIC_PIN_H
#define THRESHOLD_LOW 1175
#define THRESHOLD_HIGH 2413
#define CONFIDENCE 500

    uint8_t defaultPin = 34;

    class readAnalogicPin {
        private:
            uint8_t pin;
            uint16_t read = -1;

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
            
            void readPin(uint16_t* value = 0){
                uint16_t tmpRead = analogRead(pin);
                setRead(&tmpRead);
                *value = tmpRead;
            }
            void refreshPin(){
                uint16_t temp = analogRead(pin);
                setRead(&temp);
                
            }
            boolean isFull(uint16_t* value){
                if (*value <= (THRESHOLD_HIGH - CONFIDENCE)){
                    return 1;
                }else{
                    return 0;
                }
            }
            // Getters
            void getRead(uint16_t* value){
                *value = read;
            }
    };

#endif