#ifndef LISTENER
#define LISTENER

#include <Arduino.h>

/* This class is responsible for handling the event that come from the robot's hardware events */
class Listener {
  public:
    static const int LEFT_REAR_WHEEL_CODE  = 1;
    static const int RIGHT_REAR_WHEEL_CODE = 2;
    static const int RIGHT_HEAD_WHEEL_CODE = 4;
    static const int LEFT_HEAD_WHEEL_CODE  = 8;
      
    void onTimer(unsigned int millis);
    void onRevolve(int wheelCode); // being executed when the wheel turned 60 degrees
    void onEcho();
    void onRpi(String message);
    void onRpiNoReply(unsigned int millis);
    void onUpButton();
    void onEnterButton();
    void onDownButton();
    void onLowButton(unsigned int voltage);
    void onShutDown(unsigned int voltage);
};

#endif
