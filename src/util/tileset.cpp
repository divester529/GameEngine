#include "tileset.hpp"

Tileset::Tileset(std::string path, int _numRows)
{
  texture=loadBitmap(path);
  numRows=_numRows;
}

GLfloat* Tileset::getTile(int index)
{
  float offsetX=(float)(index%numRows);///numRows;
  float offsetY=(float)(index/numRows);///numRows;

  GLfloat *uv = (GLfloat*)malloc(sizeof(GLfloat)*12);
  
  uv[0]=offsetX;
  uv[1]=offsetY;
  uv[2]=offsetX;
  uv[3]=offsetY;
  uv[4]=offsetX;
  uv[5]=offsetY;
  uv[6]=offsetX;
  uv[7]=offsetY;
  uv[8]=offsetX;
  uv[9]=offsetY;
  uv[10]=offsetX;
  uv[11]=offsetY;

  return uv;
}
