//
// Created by olegfomin on 11/22/22.
//

#ifndef ROBOTICTENNIS_TUMBLERLISTENER_H
#define ROBOTICTENNIS_TUMBLERLISTENER_H

// This listener contains the state that changes from on to off with each call
class TumblerListener {
    bool isOn = false;
    TumblerListener(int pinContactNumber);
     // Being called when the timer generates the event
    virtual void onTimer(unsigned long int tickNumber);
    // Being called when the state changes and event gets generated supplying listener with old and new values
    virtual void onStateChange(int oldValue, int newValue);
};


#endif //ROBOTICTENNIS_TUMBLERLISTENER_H
