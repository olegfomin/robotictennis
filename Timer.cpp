#include "Timer.h"

void Timer::executeOnceTimer(Listener* listener, unsigned int inMillis) {
  executeOnceList->add(listener);
}
