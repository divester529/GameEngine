#include "tileset.hpp"

Tileset::Tileset(std::string path, int _numRows)
{
  texture=loadBitmap(path);
  numRows=_numRows;
}

GLfloat* Tileset::getTile(int index)
{
  int frameSize=texture.width/numRows;
  float offsetX=((index*frameSize)%texture.width)/texture.width;
  float offsetY=((texture.height/2)-(index*frameSize)/texture.width)/texture.height;

  float right=offsetX+frameSize/texture.width;
  float bottom=offsetY+frameSize/texture.height;
}
