#include "resourceManager.hpp"
#include "../system/message.hpp"
#include "shaderLoader.hpp"

namespace util{
  void ResourceManager::handleMessage(messanger::Message* msg)
  {
    switch(msg->msg_type)
    {
      case messanger::SHADER_LOAD:
        loadShaderProgram(msg->msg_value, (std::string*)msg->msg_data);
      break;
      case messanger::SHADER_GET:
        getShaderProgram(msg->msg_value);
      break;
    }
  }

  void ResourceManager::loadShaderProgram(std::string key, std::string path[])
  {
    printf("Loading shader program %s\nVertex Shader: %s\nFragment Shader: %s\n",
      key.c_str(), path[0].c_str(), path[1].c_str());

    GLuint prog = renderer::loadShaders(path[0].c_str(), path[1].c_str());
    shaderPrograms.insert( std::pair<std::string, GLuint>(key, prog));
  }

  void ResourceManager::getShaderProgram(std::string key)
  {
    printf("Getting shader %s\n", key.c_str());
    try{
      GLuint progID = shaderPrograms[key.c_str()];
      messageBus->dispatchMessage(messanger::Message(messanger::SHADER_POST, std::to_string(progID)));
    }catch(const std::out_of_range& exception){
      printf("Out of Range error: %s\n", exception.what());
      messageBus->dispatchMessage(messanger::Message(messanger::SHADER_NOT_FOUND));
    }
  }
}
