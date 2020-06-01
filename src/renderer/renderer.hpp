#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <vector>
#include "../system/system.hpp"
#include "../system/messageBus.hpp"
#include "renderObject.hpp"
#include "camera.hpp"

namespace render{
  class Renderer: public System
  {
  public:
    Renderer(messanger::MessageBus *_messageBus);

    void render();

    void init();
  protected:
    void handleMessage(messanger::Message *msg);

  private:
    std::vector<RenderObject*> renderObjects;
    Camera* camera;

    GLuint shaderProg;
  };
  
}

#endif // RENDERER_H_INCLUDED
