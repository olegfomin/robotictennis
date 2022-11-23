#include <Arduino.h>

void onTimer(unsigned long int tickNumber) {
  Serial.println("The default listener is called something is wrong (onTimer)");
};

// Being called when the state changes and event gets generated supplying listener with old and new values
void onStateChange(int oldValue, int newValue) {
    Serial.println("The default listener is called something is wrong (onStateChange)");
};
