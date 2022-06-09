#include <Arduino.h>
#include <servo_controller.h>
#include <dht_sensor.h>
#include <read_analogic_pin.h>
#include <bluetooth_controller.h>
#include <string>

bluetoothController btController;
servoContrller feederServo;
dhtSensor feederDHT;
readAnalogicPin feederWeight;


void setup() {
  Serial.begin(115200);
  btController.begin();
}

void loop() {
  String msg = ""; 
  String resposne = "";
  float temp = -1;
  uint16_t read = -1;
  uint8_t count = 0;
  int isPlateFull=1;

  
  
  if(btController.haveComands()){
    btController.readBT(&msg);

    switch (  msg.toInt()  )
    {
    case 49:
      btController.writeBT("ALIMENTAR: DOSE MANUAL PARCIAL");
      feederServo.openFeederParse();
      feederServo.closeFeeder();
      break;

    case 50:
      btController.writeBT("ALIMENTAR: DOSE MANUAL CHEIA");
      feederServo.openFeederFull();
      feederServo.closeFeeder();
      break;

    case 51:
      btController.writeBT("ALIMENTAR: DOSE AUTOMATICA CHEIA");
      while ( isPlateFull )
      {
        count++;
        resposne = "";
        delay(1000);
        resposne.concat("    -");
        resposne.concat(count);
        resposne.concat(" DOSES SERVIDAS");
        btController.writeBT(resposne);
        feederWeight.readPin(&read);
        isPlateFull = feederWeight.isFull(&read);
        Serial.println(read);
        feederServo.openFeederFull();
        feederServo.closeFeeder();
        
      }
      break;

    case 52:
      resposne = "";
      feederDHT.getTemperature(&temp);
      resposne.concat("TEMPERATURA: ");
      resposne.concat(temp);
      btController.writeBT(resposne);
      break;
    case 53:
      resposne = "";
      feederDHT.getHumidity(&temp);
      resposne.concat("Humidade: ");
      resposne.concat(temp);
      btController.writeBT(resposne);
      break;
    case 54:
      resposne = "";
      feederWeight.readPin(&read);
      resposne.concat("Peso: ");
      resposne.concat(read);
      btController.writeBT(resposne);
      break;
    default:
      btController.writeBT("405");
      break;
    }
  }
}