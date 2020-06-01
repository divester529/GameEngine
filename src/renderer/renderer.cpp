#include "renderer.hpp"
#include "../system/message.hpp"
#include "../util/shaderLoader.hpp"
#include <glm/glm.hpp>
#include <string>

namespace render{

  Renderer::Renderer(messanger::MessageBus *_messageBus): System(_messageBus)
  {

  }

  void Renderer::handleMessage(messanger::Message* msg)
  {
    switch(msg->msg_type)
    {
      case messanger::KEY_PRESSED:
        switch(std::stoi(msg->msg_value))
        {
          case 119:
            camera->move(glm::vec3(0, 0, 0.05));
          break;
          case 115:
            printf("s\n");
          break;
          case 100:
            printf("d\n");
          break;
          case 97:
            printf("a\n");
          break;
        }
      break;
      case messanger::SHADER_POST:
        printf("Changing shaders!\n");
        shaderProg = stoi(msg->msg_value);
        glUseProgram(shaderProg);
      break;
    }
  }

  // Has to be called after initGL() in engine
  void Renderer::init()
  {
    std::string test[]={"shaders/vertShader.glsl", "shaders/fragShader.glsl"};

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_LOAD, "default", test));

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "default"));

    camera = new Camera();

    renderObjects.push_back(new RenderObject());
    renderObjects.push_back(new RenderObject());

    printf("renderObjects length: %i\n", renderObjects.size());
  }

  // Draw the current scene
  void Renderer::render()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProg);
    camera->useCamera();

    for(std::vector<RenderObject* >::iterator it = renderObjects.begin(); it != renderObjects.end(); ++it)
    {
      (*it)->render();
    }
  }
}
