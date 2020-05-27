#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL2/SDL.h>
#include <glm/ext.hpp>
#include <glm/glm.hpp>

class Engine{
public:
  Engine();

  bool init();

  void run();

  void exit();
private:
  bool initGL();


  SDL_Window* gWindow;
  SDL_GLContext gContext;

  SDL_Event event;

  bool running;
};

#endif //ENGINE_H_INCLUDED
