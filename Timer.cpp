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

/*****************************************************************************************************************/

ListNode::ListNode() {
  this->delayedExecution = NULL;
  this->nextListNode = NULL; 
};

ListNode::ListNode(DelayedExecution* delayedExecution) {
  this->delayedExecution = delayedExecution;
  this->nextListNode = NULL; 
};

ListNode::ListNode(DelayedExecution* delayedExecution, ListNode nextlistNode) {
  this->delayedExecution = delayedExecution;
  this->nextListNode = NULL; 
};

DelayedExecution* ListNode::getDelayedExecution() {
  return this->delayedExecution;
}

ListNode* ListNode::getNextListNode() {
  return this->nextListNode;
}

ListNode* ListNode::addBetween(DelayedExecution* delayedExecution2Add) {
    bool isPlaceFound = false;
    ListNode* currentNode = this;
    ListNode* nextListNode = this->nextListNode; 
    if(nextListNode == NULL) {
      if(delayedExecution2Add->getNextExecutionTime() < this-> delayedExecution->getNextExecutionTime()) {
        ListNode* newRoot2add = new ListNode(delayedExecution2Add);
        newRoot2add->nextListNode = this;
        return newRoot2add;
      } else {
        ListNode* next2add = new ListNode(delayedExecution2Add);
        this->nextListNode = next2add;
        return this; 
      };
    };
     
    while(!isPlaceFound && nextListNode != NULL) {
      if(delayedExecution2Add->getNextExecutionTime() < nextListNode->delayedExecution->getNextExecutionTime()) {
        ListNode* node2add = new ListNode(delayedExecution2Add);
        currentNode->nextListNode = node2add;
        node2add->nextListNode = nextListNode;
        isPlaceFound = true;
      }
      currentNode = nextListNode;
      nextListNode = currentNode->nextListNode;
    };
    if(nextListNode == NULL) {
      currentNode->nextListNode = new ListNode(delayedExecution2Add);
    };

    return this;
  
}

ListNode::~ListNode() {
  
}

/*****************************************************************************************************************/
Chain::Chain() {
  
};

Chain::Chain(ListNode* root) {
  this->root = root;
}

void Chain::push(DelayedExecution* delayedExecution) {
  if(root == NULL) { 
    this->root = new ListNode(delayedExecution);
    return; 
  } else {
    ListNode* currentRoot = root->addBetween(delayedExecution);
    root = currentRoot;
  }
};

bool Chain::hasNext() {
  return root != NULL;
}

DelayedExecution* Chain::pop() {
  if(root != NULL) {
    ListNode* nextListNode = root->getNextListNode();
    DelayedExecution* delayedExecution = root->getDelayedExecution();
    delete root;
    root = nextListNode;
    return delayedExecution;
  } else {
    return NULL;
  }
};

DelayedExecution* Chain::peekDelayedExecution() {
  if(root != NULL) return root->getDelayedExecution();
  return NULL;
};

Chain::~Chain() {
  
}

/*****************************************************************************************************************/
void Timer::tick(unsigned long int tickNumber) {
  nowMillis = millis();
  while(immediateExecutionList->size() > 0) {
     Listener* listener = immediateExecutionList->get(0, new Listener());
     listener->onTimer(tickNumber);
     immediateExecutionList->remove(0);
  };

  if(delayedExecutionList->size() > 0) {
    DelayedExecution* delayedExecution = delayedExecutionList->get(0, new DelayedExecution(new Listener(), nowMillis, 0, 1));
    if(delayedExecution->getNextExecutionTime() <= nowMillis) {
      Listener* listener = delayedExecution->getListener();
      immediateExecutionList->add(listener);
      if(delayedExecution->getNumberOfReps() <= 1) {
        delayedExecutionList->removeByIndex(0);
        delete delayedExecution; 
      } else {
        delayedExecution->decrementNumberOfReps(nowMillis+delayedExecution->getPeriod());
        DelayedExecution* newDelayedExecution = new DelayedExecution(delayedExecution->getListener(), delayedExecution->getNextExecutionTime() , delayedExecution->getPeriod(), delayedExecution->getNumberOfReps()); 
        delayedExecutionList->removeByIndex(0);
        delete delayedExecution; 
        delayedExecutionList->add(newDelayedExecution);
      }
    };
  };  
  
};


DelayedExecution::DelayedExecution(Listener* listener, unsigned int nextExecutionTime, unsigned int period, unsigned int numberOfReps) {
    this->listener          = listener;
    this->nextExecutionTime = nextExecutionTime; // Next execution time in millis
    this->period            = period; // Period between two executiond in millis
    this->numberOfReps      = numberOfReps;       // Number of repetition
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

DelayedExecution::~DelayedExecution() {
  
}

void DelayedExecution::decrementNumberOfReps(unsigned int nextExecutionTime) {
  numberOfReps--;
  this->nextExecutionTime = nextExecutionTime; // Next execution time in millis
}; 
