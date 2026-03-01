#include <Arduino.h>
#include <RadioLib.h>

// cs, irq (GDO0), rst, gpio (GDO2)
CC1101 radio = new Module(5, 4, RADIOLIB_NC, RADIOLIB_NC);

void setup() {
  Serial.begin(115200);

  Serial.print("Initializing CC1101... ");
  int state = radio.begin();

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println("success!");
  } else {
    Serial.print("failed, code ");
    Serial.println(state);
    while (true);
  }

  uint8_t version = radio.getChipVersion();
  Serial.print("VERSION: 0x");
  Serial.println(version, HEX);
}

void loop() {
}