#ifndef MESSAGE_BUS_H_INCLUDED
#define MESSAGE_BUS_H_INCLUDED
#include <list>
#include "message.hpp"
#include "system.hpp"

class System;

namespace messanger
{

  class MessageBus
  {
  public:
    void dispatchMessage(Message msg);

    void test();

    void addSystem(System* system);
  private:
    std::list<System* > systems;
  };

}
#endif // MESSAGE_BUS_H_INCLUDED
