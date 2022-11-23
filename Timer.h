#ifndef TIMER
#define TIMER

#include <limits.h>
#include "src/listener/Listener.h"
#include "ArrayList.h"

/***************************************************************************************************************************************************************************************/
/* Describes the timer parameters such as period and number of repetitions. It also contains the next execution time in milliseconds                                                   */
/***************************************************************************************************************************************************************************************/
class DelayedExecution {
  private:
    unsigned int nextExecutionTime = INT_MAX; // Next execution time in millis
    unsigned int period            = INT_MAX; // Period between two executiond
    unsigned int numberOfReps      = 1;       // Number of repetition
    Listener* listener;
  public:
    DelayedExecution(Listener* listener, unsigned int nextExecutionTime, unsigned int period, unsigned int numberOfReps);
    Listener* getListener();
    unsigned int getNextExecutionTime();
    unsigned int getPeriod();
    unsigned int getNumberOfReps();
    void decrementNumberOfReps(unsigned int nextExecutionTime); 
    ~DelayedExecution();   
};

/***************************************************************************************************************************************************************************************/
/* The timer that gets invoked from arduno loop and it goes through the immediateExecutionList first. The class calls the listener and then removes it from the list. It verifies      */
/* whether there are any entries in the delayedExecutionList that are due for execution at which moment this entry gets moved into immediateExecutionList array where it is being      */
/* picked up at the next tick                                                                                                                                                          */
/***************************************************************************************************************************************************************************************/                      
class Timer {
  private:
    unsigned int nowMillis = 0;
    // Array list that contains all the listeners that needed to be executed immediatelly and once only
    ArrayList<Listener*> *immediateExecutionList = new ArrayList<Listener*>();
    // Array list that contains all the timers that need to be executed in the future
    ArrayList<DelayedExecution*> *delayedExecutionList = new ArrayList<DelayedExecution*>();
  public:
    Timer();
    void executeNextTick(Listener* listener); // it runs the listener once immidiately and then forgets about it 
    void executePeriodically(Listener* listener, unsigned int period=1000, unsigned int numberOfReps=1); // scans the list periodically by sending the new entry into an immediateExecutionList. The first execution will happen in number of millis 
    void tick(unsigned long int tickNumber); // being called from the Arduino loop, each tick nowMillis gets updated 
    ~Timer();
};    

#endif
