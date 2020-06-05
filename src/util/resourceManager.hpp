#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <vector>
#include <map>
#include <string>
#include "../system/system.hpp"
#include "textureAtlas.hpp"
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
    std::map<std::string, TextureAtlas> textureAtlas;

    void handleMessage(messanger::Message* msg);

    void loadShaderProgram(std::string key, std::string path[]);
    GLuint getShaderProgram(std::string key);

    void loadTexture(std::string key, std::string path);
    TextureData getTexture(std::string key);

    void loadTextureAtlas(std::string key, std::string path);
    void loadTextureAtlas(std::string key, std::string path, int numRows);
    TextureAtlas getTextureAtlas(std::string key);

  };
}
#endif // RESOURCEMANAGER_H_INCLUDED
