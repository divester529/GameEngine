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
            camera->move(-5);
          break;
          case 115:
            //camera->move(glm::vec3(0, -5, 0));
            camera->move(5);
          break;
          case 100:
            //camera->move(glm::vec3(5, 0, 0));
            camera->yaw(-0.2);
          break;
          case 97:
            //camera->move(glm::vec3(-5, 0, 0));
            camera->yaw(0.2);
          break;
          case 101:
            camera->pitch(-0.02);
          break;
          case 113:
            camera->pitch(0.02);
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

    renderables.push_back(new Renderable());
    renderables.push_back(new Renderable());

    printf("Renderables length: %i\n", renderables.size());
    Tileset *ts = new Tileset("res/tileset1.bmp", 3);

    tmTest = new TileMapAsset("test.txt", 10, 10, ts);
  }

  // Draw the current scene
  void Renderer::render()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "default"));

    camera->useCamera();

    messageBus->dispatchMessage(messanger::Message(messanger::SHADER_GET, "tilemap"));
    camera->useCamera();
    GLuint numRowsLoc = glGetUniformLocation(shaderProg, "numRows");
    glUniform1f(numRowsLoc, 3);

    glBindVertexArray(tmTest->vao);
    glDrawArrays(GL_TRIANGLES, 0, tmTest->numVerticies);

    for(std::vector<Renderable* >::iterator it = renderables.begin(); it != renderables.end(); ++it)
    {
      (*it)->render();
    }
  }
}
