#include <Arduino.h>
#include <string.h>
#include <BluetoothSerial.h>

#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define BT_NAME "Mini-Chef"


    class bluetoothController {
        private:
            BluetoothSerial miniChefSerialBT;
        public:
            boolean haveComands(){
                return miniChefSerialBT.available();
            }
            void readBT(String * msg){
                *msg = miniChefSerialBT.read();
            }
            void writeBT(String msg){
                miniChefSerialBT.println(msg);
            }
            void begin(){
                miniChefSerialBT.begin(BT_NAME);
            }
    };

#endif