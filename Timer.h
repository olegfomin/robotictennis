#ifndef TIMER
#define TIMER

#include <limits>
#include "src/listener/Listener.h"
#include "ArrayList.h"

class Timer {
  private:
    unsigned int nowMillis = 0;
    // Array list that contains all the timers that needed to be executed once only
    ArrayList<Listener*> *executeOnceList = new ArrayList<Listener*>();
    // Array list that contains all the timers that needed to be periodically with a period in milliseconds (see the next array). It is being exceuted once immediately and then continue execution until it reaches the max number of execution see one more array down
    ArrayList<Listener*> *executePeriodicallyList = new ArrayList<Listener*>();
    // Array list contains the numeric periods in millis
    ArrayList<int> *periodList = new ArrayList<int>();
    // Array list contains the numeric periods in millis
    ArrayList<int> *nextExecutionTimeList = new ArrayList<int>();
    // Array list contains the nuber of repetitions the periodical timer needs to make          
    ArrayList<int> *howManyTimesList = new ArrayList<int>();
  public:
    void executeOnceTimer(Listener* listener, unsigned int inMillis=0); // by default it runs throught the listener once immidiately and then forgets about it 
//    void executePeriodically(unsigned int periodMillis=1000, Listener listener); // by default it runs through the listener infinite number of times with the period of one second
//    void executePeriodically(unsigned int periodMillis=1000, int howManyTimes=MAX_INT, Listener listener); // by default it runs through the listener infinite number of times with the period of one second
};

#endif
