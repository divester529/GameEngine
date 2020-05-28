#include "renderer.hpp"
#include "../system/message.hpp"
#include <glm/glm.hpp>

namespace render{

  void Renderer::handleMessage(messanger::Message* msg)
  {
    switch(msg->msg_type)
    {
      case messanger::KEY_PRESS:
        //camera->move(glm::vec3(0,0,1));
      break;
    }
  }

  // Draw the current scene
  void Renderer::render()
  {

  }
}
