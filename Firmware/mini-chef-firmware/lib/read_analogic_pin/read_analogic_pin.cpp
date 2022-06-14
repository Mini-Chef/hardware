#include "read_analogic_pin.h"

readAnalogicPin::readAnalogicPin(uint8_t Pin){
    setPin( &Pin );
}

void readAnalogicPin::setRead(uint16_t* value){
    read = *value;
}

void readAnalogicPin::setPin(uint8_t* Pin){
    pin = *Pin;
}

void readAnalogicPin::readPin(uint16_t* value){
    uint16_t tmpRead = analogRead(pin);
    setRead(&tmpRead);
    *value = tmpRead;
}

void readAnalogicPin::refreshPin(){
    uint16_t temp = analogRead(pin);
    setRead(&temp);
}

void readAnalogicPin::getRead(uint16_t* value){
    *value = read;
}

boolean readAnalogicPin::isFull(uint16_t* value){
    if (*value <= (THRESHOLD_HIGH - CONFIDENCE)){
        return 1;
    }else{
        return 0;
    }
}