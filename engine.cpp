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

#include "renderer/shaderLoader.hpp"

Engine::Engine()
{

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
    printf("OpenGL context could not be created! Error: ", SDL_GetError());
    return false;
  }

  if(SDL_GL_SetSwapInterval(1)<0)
  {
    printf("Unable to set VSync!");
  }

  if(initGL())
    return true;
  else
    return false;

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

  return true;
}

void Engine::run()
{
  running = true;

  GLfloat g_vertex_buffer_data[]={
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 1.0f, 0.0f
  };

  GLuint vertexbuffer;

  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  GLuint shaderProg = renderer::loadShaders("shaders/vertShader.glsl", "shaders/fragShader.glsl");

  if(shaderProg==0)
    return;

  glm::mat4 projMat = glm::perspective(glm::radians(45.0f), float(SCREEN_WIDTH)/float(SCREEN_HEIGHT), 0.1f, 100.0f);
  //glm::mat4 projMat = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);

  glm::mat4 viewMat = glm::lookAt(glm::vec3(4,3,3),
                                  glm::vec3(0,0,0),
                                  glm::vec3(0,1,0));

  glm::mat4 modelMat = glm::mat4(1.0f);

  glm::mat4 mvp = projMat*viewMat*modelMat;

  glm::vec4 test(1, 1.0f, 1.0f, 1.0f);

  GLuint mvpID = glGetUniformLocation(shaderProg, "MVP");
  glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvp[0][0]);

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("%f ", &projMat[i][j]);
    }
    printf("\n");
  }

  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type==SDL_QUIT)
      {
        running=false;
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProg);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(gWindow);
  }
}