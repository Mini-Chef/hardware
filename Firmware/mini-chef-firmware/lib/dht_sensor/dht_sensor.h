#include <DHT.h>

#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H
#define DHTPIN 18
#define DHTTYPE DHT11
    
    class dhtSensor{
        public:
            dhtSensor(uint8_t pinValue = DHTPIN);
            void getHumidity(float* value);
            void getTemperature(float* value);
        private:
            uint8_t pin = 0;
            float humidity = 0;
            float temperature = 0;
            DHT dhtInstance = DHT(DHTPIN, DHTTYPE);
            void setTemperature();
            void setHumidity();
    };
#endif