#ifndef TEXTUREATLAS_H_INCLUDED
#define TEXTUREATLAS_H_INCLUDED
#include <string>
#include <GL/GLew.h>
#include <GL/GL.h>
#include "textureLoader.hpp"

class TextureAtlas{
public:
  TextureAtlas(){}
  TextureAtlas(std::string path);
  TextureAtlas(std::string path, int _numRows);

  void useTexture();
  void setFrame(int index);
private:
  TextureData texture;
  int numRows;
};

#endif // TEXTUREATLAS_H_INCLUDED
