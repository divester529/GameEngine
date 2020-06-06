#include "resourceManager.hpp"
#include "../system/message.hpp"
#include "shaderLoader.hpp"
#include "textureLoader.hpp"

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
      case messanger::TEXTURE_LOAD:
        loadTexture(msg->msg_value, *(std::string*)msg->msg_data);
      break;
      case messanger::TEXTURE_GET:
        getTexture(msg->msg_value);
      break;
      case messanger::TEXTURE_ATLAS_LOAD:
        loadTextureAtlas(msg->msg_value, *(std::string*)msg->msg_data);
      break;
      case messanger::TEXTURE_ATLAS_GET:

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

  GLuint ResourceManager::getShaderProgram(std::string key)
  {
    //printf("Getting shader %s\n", key.c_str());
    try{
      GLuint progID = shaderPrograms[key.c_str()];
      messageBus->dispatchMessage(messanger::Message(messanger::SHADER_POST, std::to_string(progID)));
    }catch(const std::out_of_range& exception){
      printf("Out of Range error: %s\n", exception.what());
      messageBus->dispatchMessage(messanger::Message(messanger::SHADER_NOT_FOUND));
    }
  }

  void ResourceManager::loadTexture(std::string key, std::string path)
  {
    printf("Loading bitmap %s as %s\n", path.c_str(), key.c_str());
    TextureData texture = loadBitmap(path);
    textureData.insert( std::pair<std::string, TextureData>(key, texture));
  }

  TextureData ResourceManager::getTexture(std::string key)
  {
    printf("Getting texture %s\n", key.c_str());
    try{
      TextureData tex = textureData[key.c_str()];
      messageBus->dispatchMessage(messanger::Message(messanger::TEXTURE_POST, std::to_string(tex.id), &tex));
      return tex;
    }catch(const std::out_of_range& exception){
      printf("Out of Range error: %s\n", exception.what());
      messageBus->dispatchMessage(messanger::Message(messanger::TEXTURE_NOT_FOUND));
    }
  }

  void ResourceManager::loadTextureAtlas(std::string key, std::string path)
  {
    printf("Loading textureAtlas %s as %s\n", path.c_str(), key.c_str());
    TextureAtlas ta(path);
    textureAtlas.insert( std::pair<std::string, TextureAtlas>(key, ta));
  }

  TextureAtlas ResourceManager::getTextureAtlas(std::string key)
  {
    printf("Getting textureAtlas %s\n", key.c_str());
    try{
      TextureAtlas* ta = &textureAtlas[key.c_str()];
      messageBus->dispatchMessage(messanger::Message(messanger::TEXTURE_ATLAS_POST, key.c_str(), (TextureAtlas*)ta));
    }catch(const std::out_of_range& exception){
      printf("Out of Range error: %s\n", exception.what());
      messageBus->dispatchMessage(messanger::Message(messanger::TEXTURE_ATLAS_NOT_FOUND));
    }
  }
}
