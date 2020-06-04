#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <vector>
#include <map>
#include <string>
#include "../system/system.hpp"
#include "textureLoader.hpp"

namespace util{
  class ResourceManager: public System
  {
  public:
    ResourceManager(messanger::MessageBus *messageBus) : System(messageBus){}
  private:
    std::map<std::string, GLuint> shaderPrograms;
    std::map<std::string, GLuint> meshes;
    std::map<std::string, TextureData> textureData;

    void handleMessage(messanger::Message* msg);

    void loadShaderProgram(std::string key, std::string path[]);
    void getShaderProgram(std::string key);

    void loadTexture(std::string key, std::string path);
    void getTexture(std::string key);
  };
}
#endif // RESOURCEMANAGER_H_INCLUDED
