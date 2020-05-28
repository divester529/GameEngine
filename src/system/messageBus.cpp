#include "messageBus.hpp"
#include <stdio.h>

namespace messanger
{

  void MessageBus::dispatchMessage(Message msg)
  {
    for(std::list<System*>::iterator it=systems.begin(); it != systems.end(); ++it)
    {
      (*it)->handleMessage(&msg);
    }
  }

  void MessageBus::test()
  {
      printf("shit");
  }

  void MessageBus::addSystem(System* system)
  {
    systems.push_back(system);
  }
}
