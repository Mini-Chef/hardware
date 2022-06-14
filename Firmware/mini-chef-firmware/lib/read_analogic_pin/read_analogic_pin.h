#include <Arduino.h>

#ifndef READ_ANALOGIC_PIN_H
#define READ_ANALOGIC_PIN_H

#define THRESHOLD_LOW 1175
#define THRESHOLD_HIGH 2413
#define CONFIDENCE 500

    class readAnalogicPin {
        private:
            uint8_t pin;
            uint16_t read = -1;
            static const uint8_t defaultPin = 34;
            
            void setRead(uint16_t* value);
            void setPin(uint8_t* Pin);
        public:
            // Constructor
            readAnalogicPin(uint8_t Pin = defaultPin);
            void readPin(uint16_t* value);
            void refreshPin();
            void getRead(uint16_t* value);
            boolean isFull(uint16_t* value);
    };

#endif