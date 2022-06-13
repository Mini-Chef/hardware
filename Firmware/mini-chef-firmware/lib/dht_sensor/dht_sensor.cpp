#include "dht_sensor.h"

/*

    
    class dhtSensor {
    public:
        dhtSensor(uint8_t pinValue = DHTPIN)
        {
            pin = pinValue;
        }
        // Getter
        void getHumidity(float* value){
            setHumidity();
            *value = humidity;
        }
        void getTemperature(float* value){
            setTemperature(&temperature);
            *value = temperature;
            Serial.println(temperature);
        }
    private:
        void setTemperature(float* value){
            temperature = dhtInstanse.readTemperature();

        }
        void setHumidity(){
            humidity = dhtInstanse.readHumidity();
        }
};
*/
dhtSensor::dhtSensor(uint8_t pinValue = DHTPIN){
    pin = pinValue;
}

void dhtSensor::setTemperature(){
    temperature = dhtInstanse.readTemperature();
}

void dhtSensor::setHumidity(){
    humidity = dhtInstanse.readHumidity();
}

void dhtSensor::getTemperature(float* value){
    setTemperature();
    *value = temperature;
}

void dhtSensor::getHumidity(float* value){
    setHumidity();
    *value = humidity;
}