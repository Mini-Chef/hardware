#include "read_analogic_pin.h"


class readAnalogicPin {
    private:
        uint8_t pin;
        uint16_t lastRead;
        uint16_t read;

        // Private Setters
        void setLastRead(uint16_t value){
            lastRead = value;
        }
        void setRead(uint16_t value){
            read = value;
        }

    public:
        void readPin(){
                uint16_t tmpRead = analogRead(pin);
                setLastRead(read);
                setRead( tmpRead);
            }
        //setter
        void setPin(uint8_t Pin){
            pin = Pin;
        }
        // Getters
       
        
};


