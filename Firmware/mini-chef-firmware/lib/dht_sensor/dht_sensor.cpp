#include "dht_sensor.h"

dhtSensor::dhtSensor(uint8_t pinValue){
    pin = pinValue;
}

void dhtSensor::setTemperature(){
    temperature = dhtInstance.readTemperature();
}

void dhtSensor::setHumidity(){
    humidity = dhtInstance.readHumidity();
}

void dhtSensor::getTemperature(float* value){
    setTemperature();
    *value = temperature;
}

void dhtSensor::getHumidity(float* value){
    setHumidity();
    *value = humidity;
}