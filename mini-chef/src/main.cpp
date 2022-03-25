#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.write("ping\n");
  delay(2000);
}