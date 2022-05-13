#include "dhtSensor.h"

class dhtSensor{
    private:
        uint8_t pin;
        float humidity = 0;
        float temperature = 0;
        DHT dhtInstanse;
        // Setter
        DHT setDHT(){
           DHT dht(pin, DHTTYPE);
           return dht;
        }
        void setTemperature(){
            temperature = dhtInstanse.readTemperature();
        }
        void setHumidity(){
            humidity = dhtInstanse.readHumidity();
        }
    public:
        void setDHTSensor(uint8_t pinValue = DHTPIN){
            pin = pinValue;
            dhtInstanse = setDHT();
        }
        // Getter
        void getHumidity(float* value){
            setHumidity();
            *value = humidity;
        }
        void getTemperature(float* value){
            setTemperature();
            *value = temperature;
        }

};