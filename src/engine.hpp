#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL2/SDL.h>
#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "renderer/renderer.hpp"
#include "input/InputManager.hpp"
#include "system/messageBus.hpp"

class Engine: public System{
public:
  Engine();

  bool init();

  void run();

  void exit();
private:
  bool initGL();

  void handleMessage(messanger::Message *msg);

  messanger::MessageBus *messageBus;

  render::Renderer *renderer;
  input::InputManager *inputManager;

  SDL_Window* gWindow;
  SDL_GLContext gContext;

  bool running;
};

#endif //ENGINE_H_INCLUDED
