#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED
#include <string>
#include <GL/GLew.h>
#include <GL/GL.h>
#include <glm/glm.hpp>
#include "textureLoader.hpp"

class Tileset
{
public:
  Tileset(std::string path, int _numRows);

  GLfloat* getTile(int index);
private:
  TextureData texture;
  int numRows;
};

#endif // TILESET_H_INCLUDED
