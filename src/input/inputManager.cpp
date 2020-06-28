#include "InputManager.hpp"
#include <string>

namespace input
{
  void InputManager::handleInput()
  {
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          messageBus->dispatchMessage(messanger::Message(messanger::APPLICATION_EXIT));
        break;
        case SDL_KEYDOWN:
          messageBus->dispatchMessage(messanger::Message(messanger::KEY_PRESSED, std::to_string(event.key.keysym.sym)));
          printf("Key Pressed: %i\n", event.key.keysym.sym);
         break;
      }
    }
  }
}
