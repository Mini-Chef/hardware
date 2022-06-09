#include <Arduino.h>
#include <servo_controller.h>
#include <dht_sensor.h>
#include <read_analogic_pin.h>
#include <bluetooth_controller.h>
#include <string>

bluetoothController btController;
servoContrller feederServo;
dhtSensor feederDHT;


void setup() {
  Serial.begin(115200);
  btController.begin();
}

void loop() {

  String msg = ""; 
  
  
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
      uint8_t count = 0;
      while ( 1 )
      {
        count++;
        btController.writeBT("    - ");
        feederServo.openFeederFull();
        feederServo.closeFeeder();
      }
      
      break;
    case 52:
      btController.writeBT("TEMPERATURA: ");
      break;
    default:
      btController.writeBT("405");
      break;
    }
  }
}