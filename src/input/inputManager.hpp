#ifndef INPUT_MANAGER_H_INCLUDED
#define INPUT_MANAGER_H_INCLUDED
#include "../system/system.hpp"
#include "../system/messageBus.hpp"
#include <SDL2/SDL.h>

namespace input
{
  class InputManager: public System
  {
  public:
    InputManager(messanger::MessageBus* msgBus): System(msgBus){}

    void handleInput();

  protected:
    //void handleMessage(messanger::MessageBus* msgBus)

  private:
    SDL_Event event;
  };
}

#endif // INPUT_MANAGER_H_INCLUDED
