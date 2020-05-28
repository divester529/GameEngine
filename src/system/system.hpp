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

  void start();
protected:
  virtual void handleMessage(messanger::Message *msg);

  messanger::MessageBus* messageBus;

  friend class messanger::MessageBus;
};

#endif // SYSTEM_H_INCLUDED
