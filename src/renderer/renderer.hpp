#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include "../system/system.hpp"
#include "../system/messageBus.hpp"
#include "camera.hpp"

namespace render{
  class Renderer: public System
  {
  public:
    Renderer(messanger::MessageBus *_messageBus): System(_messageBus) {}

    void render();

  protected:
    void handleMessage(messanger::Message *msg);

  private:
    Camera* camera;
  };

}

#endif // RENDERER_H_INCLUDED
