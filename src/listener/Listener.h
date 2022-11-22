#ifndef LISTENER
#define LISTENER

#include <Arduino.h>

/* This class is responsible for handling the event that come from the robot's hardware events */
class Listener {
  public:
    // Being called when the timer generates the event
    void onTimer(unsigned long int tickNumber);
    // Being called when the state changes and event gets generated supplying listener with old and new values
    void onStateChange(int oldValue, int newValue);
 };

#endif

/*
 *
    static const int LEFT_REAR_WHEEL_CODE  = 1;
    static const int RIGHT_REAR_WHEEL_CODE = 2;
    static const int RIGHT_HEAD_WHEEL_CODE = 4;
    static const int LEFT_HEAD_WHEEL_CODE  = 8;


    void onRevolve(int wheelCode); // being executed when the wheel turned 60 degrees
    void onEcho();
    void onRpi(String message);
    void onRpiNoReply(unsigned int millis);
    void onUpButton();
    void onEnterButton();
    void onDownButton();
    void onLowButton(unsigned int voltage);
    void onShutDown(unsigned int voltage); *\
