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
            dhtSensor(uint8_t pinValue = DHTPIN);
            // Getter
            void getHumidity(float* value);
            void getTemperature(float* value);
        private:
            void setTemperature();
            void setHumidity();
    };


#endif