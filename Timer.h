#ifndef TIMER
#define TIMER

#include <limits.h>
#include "Listener.h"


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

/*********************************************************************************/
/* Contains delayed execution time and the refernce to the next node in the list */
/*********************************************************************************/
class ListNode {
  private:
    DelayedExecution* delayedExecution=NULL;
    ListNode* nextListNode=NULL;
  public:
    ListNode();
    ListNode(DelayedExecution* delayedExecution);
    ListNode(DelayedExecution* delayedExecution, ListNode nextNode);
    DelayedExecution* getDelayedExecution();
    ListNode* getNextListNode();
    // Pushes the new element in between sequential execution times say there is a list 1->3->4->9->9->14 if we want to add the new delayed execution with 10 then the list would look like 1->3->4->9->9->10->14
    // It returns either the new node or the root provided depending upon whether the 'delayed execution' should be before the root or after
    ListNode* addBetween(DelayedExecution* delayedExecution); 
    ~ListNode();
};

/*********************************************************************************/
/* Contains the reference to the root of lineked list                            */
/*********************************************************************************/
class Chain {
  private:
    ListNode* root = NULL;
  public:  
    Chain();
    Chain(ListNode* root);
    void push(DelayedExecution* delayedExecution);
    bool hasNext();
    DelayedExecution* pop(unsigned int nextExecutionTime);
    DelayedExecution* peekDelayedExecution(); // Allowing the peekhole so that we can sleep till the time the execution is due
    ~Chain();
};

/***************************************************************************************************************************************************************************************/
/* The timer that gets invoked from arduno loop and it goes through the immediateExecutionList first. The class calls the listener and then removes it from the list. It verifies      */
/* whether there are any entries in the delayedExecutionList that are due for execution at which moment this entry gets moved into immediateExecutionList array where it is being      */
/* picked up at the next tick                                                                                                                                                          */
/***************************************************************************************************************************************************************************************/                      
class Timer {
  private:
    unsigned int nowMillis = 0;
    ArrayList<DelayedExecution*> *delayedExecutionList = new ArrayList<DelayedExecution*>();
  public:
    Timer();
    void executeNextTick(Listener* listener); // it runs the listener once immidiately and then forgets about it 
    void executePeriodically(Listener* listener, unsigned int period=1000, unsigned int numberOfReps=1); // scans the list periodically by sending the new entry into an immediateExecutionList. The first execution will happen in number of millis 
    void tick(unsigned long int tickNumber); // being called from the Arduino loop, each tick nowMillis gets updated 
    ~Timer();
};    

#endif
