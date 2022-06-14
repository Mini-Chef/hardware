#include "bluetooth_controller.h"

void bluetoothController::begin(){
    miniChefSerialBT.begin(BT_NAME);
}

void bluetoothController::writeBT(String msg){
    miniChefSerialBT.println( msg );
}

void bluetoothController::readBT( String* msg){
    *msg = miniChefSerialBT.read();
}

boolean bluetoothController::haveComands(){
    return miniChefSerialBT.available(); 
}