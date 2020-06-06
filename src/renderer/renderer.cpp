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
            camera->move(glm::vec3(0, 5, 0));
          break;
          case 115:
            camera->move(glm::vec3(0, -5, 0));
          break;
          case 100:
            camera->move(glm::vec3(5, 0, 0));
          break;
          case 97:
            camera->move(glm::vec3(-5, 0, 0));
          break;
        }
      break;
      case messanger::SHADER_POST:
        //printf("Changing shaders!\n");
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

    std::string test2[]={"shaders/tilemapVertShader.glsl", "shaders/fragShader.glsl"};

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_LOAD, "tilemap", test2));

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "default"));

    camera = new Camera();

    renderObjects.push_back(new RenderObject());
    renderObjects.push_back(new RenderObject());

    printf("renderObjects length: %i\n", renderObjects.size());
    Tileset *ts = new Tileset("res/tilest1.bmp", 2);

    tmTest = new TileMapAsset("test", 20, 20, ts);
  }

  // Draw the current scene
  void Renderer::render()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "default"));

    camera->useCamera();

    for(std::vector<RenderObject* >::iterator it = renderObjects.begin(); it != renderObjects.end(); ++it)
    {
      (*it)->render();
    }

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "tilemap"));
    camera->useCamera();
    GLuint numRowsLoc = glGetUniformLocation(shaderProg, "numRows");
    glUniform1f(numRowsLoc, 2);

    glBindVertexArray(tmTest->vao);
    glDrawArrays(GL_TRIANGLES, 0, tmTest->numVerticies);
  }
}
