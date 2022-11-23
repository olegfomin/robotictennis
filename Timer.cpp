#include "Timer.h"


Timer::Timer() {
  
};

void Timer::executeNextTick(Listener* listener) {
  immediateExecutionList->add(listener);
};

void Timer::executePeriodically(Listener* listener, unsigned int period, unsigned int numberOfReps) {
  DelayedExecution* delayedExecution = new DelayedExecution(listener, nowMillis+period, period, numberOfReps); 
  delayedExecutionList->add(delayedExecution);
};

void Timer::tick(unsigned long int tickNumber) {
  nowMillis = millis();
  while(immediateExecutionList->size() > 0) {
     Listener* listener = immediateExecutionList->get(0, new Listener());
     listener->onTimer(tickNumber);
     immediateExecutionList->remove(0);
  }

  for(int i=0; i < delayedExecutionList->size(); i++) {
    DelayedExecution* delayedExecution = delayedExecutionList->get(i, new DelayedExecution(new Listener(), nowMillis, 0, 1));
    if(delayedExecution->getNextExecutionTime() >= nowMillis) {
      Listener* listener = delayedExecution->getListener();
      immediateExecutionList->add(listener);
      if(delayedExecution->getNumberOfReps() <= 1) {
        delayedExecutionList->removeByIndex(i);
        delete delayedExecution; 
      } else {
        delayedExecution->decrementNumberOfReps(nowMillis+delayedExecution->getPeriod());
      }
    }
  }
  
};


DelayedExecution::DelayedExecution(Listener* listener, unsigned int nextExecutionTime, unsigned int period, unsigned int numberOfReps) {
    this->listener          = listener;
    this->nextExecutionTime = nextExecutionTime; // Next execution time in millis
    this->period            = period; // Period between two executiond in millis
    this->numberOfReps      = 1;       // Number of repetition
};

Listener* DelayedExecution::getListener() {
  return listener;
};

unsigned int DelayedExecution::getNextExecutionTime() {
  return nextExecutionTime;
};

unsigned int DelayedExecution::getPeriod() {
  return period;
};

unsigned int DelayedExecution::getNumberOfReps() {
  return numberOfReps;
};

void DelayedExecution::decrementNumberOfReps(unsigned int nextExecutionTime) {
  numberOfReps--;
  this->nextExecutionTime = nextExecutionTime; // Next execution time in millis
}; 
