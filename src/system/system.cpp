#include "system.hpp"

System::System(messanger::MessageBus* _messageBus)
{
  messageBus = _messageBus;
}

void System::handleMessage(messanger::Message* msg)
{
  printf("Message type: %s Message value: %s\n", messanger::msg_types[msg->msg_type], msg->msg_value.c_str());
}
