#include "messageBus.hpp"

namespace messanger
{

  void MessageBus::dispatchMessage(Message msg)
  {
    for(std::list<System* >::iterator it=systems.begin(); it != systems.end(); ++it)
    {
      (*it)->handleMessage(&msg);
    }
  }

  void MessageBus::addSystem(System* system)
  {
    printf("adding system");
    systems.push_back(system);
  }
}
