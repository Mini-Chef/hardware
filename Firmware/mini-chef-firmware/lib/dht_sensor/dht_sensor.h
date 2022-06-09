#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include "DHT.h"

#define DHTPIN 18
#define DHTTYPE DHT11

    uint8_t pin;
    float humidity = 0;
    float temperature = 0;
    DHT dhtInstanse(DHTPIN, DHTTYPE);
    // Setter
    
    
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


#endif