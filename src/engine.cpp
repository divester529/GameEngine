#define GL_GLEXT_PROTOTYPES
#define GLM_FORCE_CXX98
#define GLM_FORCE_EXPLICIT_CTOR
#include "engine.hpp"
#include <GL/GLew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <stdio.h>

#include "util/shaderLoader.hpp"
#include "system/messageBus.hpp"
#include "system/message.hpp"
#include "system/system.hpp"

#include <string>
Engine::Engine(): System(messageBus)
{
  messageBus = new messanger::MessageBus();
  renderer = new render::Renderer(messageBus);
  inputManager = new input::InputManager(messageBus);
  resourceManager = new util::ResourceManager(messageBus);

  messageBus->addSystem(this);
  messageBus->addSystem(renderer);
  messageBus->addSystem(inputManager);
  messageBus->addSystem(resourceManager);
}

bool Engine::init()
{
  glewExperimental = true;

  if(SDL_Init(SDL_INIT_VIDEO)<0)
  {
    printf("Could not initialize SDL: Error: %s\n", SDL_GetError());

    return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

  gWindow = SDL_CreateWindow("Platformer Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  gContext = SDL_GL_CreateContext(gWindow);
  if(!gContext)
  {
    printf("OpenGL context could not be created! Error: %s", SDL_GetError());
    return false;
  }

  if(SDL_GL_SetSwapInterval(1)<0)
  {
    printf("Unable to set VSync!");
  }

  if(!initGL())
    return false;

  GLfloat g_vertex_buffer_data[]={
    0.0f, 0.0f, 0.0f,
    0.0f, 32.0f, 0.0f,
    32.0f, 0.0f, 0.0f,
    32.0f, 0.0f, 0.0f,
    0.0f, 32.0f, 0.0f,
    32.0f, 32.0f, 0.0f
  };

  GLuint vertexbuffer;

  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  renderer->init();

  return true;
}

bool Engine::initGL()
{
  if(glewInit() != GLEW_OK)
  {
    printf("Error initializing glew");
    return false;
  };

  if(GLEW_VERSION_1_3)
  {
    printf("OpenGL version 1.3 supported\n");
  }
  if(GLEW_VERSION_2_1)
  {
    printf("OpenGL version 2.1 supported\n");
  }
  if(GLEW_VERSION_3_0)
  {
    printf("OpenGL version 3.0 supported\n");
  }
  if(GLEW_VERSION_3_3)
  {
    printf("OpenGL version 3.3 supported\n");
  }

  //glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
  return true;
}

void Engine::handleMessage(messanger::Message *msg)
{
  switch(msg->msg_type)
  {
    case messanger::APPLICATION_EXIT:
      running=false;
    break;
  }
}


void Engine::run()
{
  running = true;

  printf("Entering game loop\n");
  while(running)
  {
    inputManager->handleInput();

    renderer->render();

    SDL_GL_SwapWindow(gWindow);
  }
}
