#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960

#include <SDL2/SDL.h>
#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "renderer/renderer.hpp"
#include "input/InputManager.hpp"
#include "util/resourceManager.hpp"
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
  util::ResourceManager *resourceManager;

  SDL_Window* gWindow;
  SDL_GLContext gContext;

  bool running;
};

#endif //ENGINE_H_INCLUDED
