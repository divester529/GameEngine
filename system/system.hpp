#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include "messageBus.hpp"

namespace messanger{

  class MessageBus;
}

class System
{
public:
  System(messanger::MessageBus *_messageBus);

  virtual void handleMessage(messanger::Message *msg);

private:
  messanger::MessageBus* messageBus;
};

#endif // SYSTEM_H_INCLUDED
