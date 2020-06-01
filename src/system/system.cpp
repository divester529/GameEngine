#include "system.hpp"

namespace messanger{
  static const char* msg_types[] = {
    "KEY_PRESSED",
    "APPLICATION EXIT",
    "TEXTURE_LOAD",
    "TEXTURE_GET",
    "SHADER_LOAD",
    "SHADER_GET",
    "SHADER_POST",
    "SHADER_NOT_FOUND"};
}

System::System(messanger::MessageBus* _messageBus)
{
  messageBus = _messageBus;
}

void System::handleMessage(messanger::Message* msg)
{
  printf("Message type: %s Message value: %s\n", messanger::msg_types[msg->msg_type], msg->msg_value.c_str());
}
