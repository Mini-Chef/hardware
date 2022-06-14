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
            boolean haveComands();
            void readBT(String * msg);
            void writeBT(String msg);
            void begin();
    };

#endif