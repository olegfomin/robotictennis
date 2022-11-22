#include "Timer.h"

Timer::Timer() {
  
};

void Timer::executeNextTick(Listener* listener) {
  immediateExecutionList->add(listener);
}

void Timer::executePeriodically(Listener listener, unsigned int period, unsigned int numberOfReps) {
  DelayedExecution* delayedExecution = new DelayedExecution(listener, nowMillis+period, period, numberOfReps); 
  delayedExecutionList->add(delayedExecution);
}

void Timer::tick(unsigned long int tickNumber) {
  nowMillis = millis();
  while(immediateExecutionList->size() > 0) {
     Listener* listener = immediateExecutionList.get(0);
     listener->onTimer(tickNumber);
     immediateExecutionList.remove(0);
  }

  for(int i=0; i < delayedExecutionList->size(); i++) {
    DelayedExecution delayedExecution = delayedExecutionList.get(i);
    if(delayedExecution.getNextExecutionTime() >= nowMillis) {
      Listener* listener = delayedExecution.getListener();
      immediateExecutionList.add(listener);
      if(delayedExecution.getNumberOfReps() <= 1) {
        delayedExecutionList.remove(i);
        delete delayedExecution; 
      } else {
        delayedExecution.decrementNumberOfReps(nowMillis+delayedExecution.getPeriod());
      }
    }
  }
  
}
