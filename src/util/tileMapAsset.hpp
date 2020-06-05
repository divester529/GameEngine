#ifndef TILEMAPASSET_H_INCLUDED
#define TILEMAPASSET_H_INCLUDED
#include <string>
#include <GL/GLew.h>
#include <GL/GL.h>
#include "textureLoader.hpp"
#include "tileset.hpp"
#include "resourceManager.hpp"

struct TileMapInfo{
  TileMapInfo(std::string _key, std::string _tilesetKey, int _width, int _height){
    key=_key;
    tilesetKey=_tilesetKey;
    width=_width;
    height=_height;
  }
  TileMapInfo(std::string _path, std::string _key, std::string _tilesetKey){

  }

  std::string path;
  std::string key;
  std::string tilesetKey;
  int width, height;
};

class TileMapAsset
{
public:
  TileMapAsset(std::string key, int width, int height, Tileset* ts);
  TileMapAsset(std::string key, std::string path);

  GLuint vao;
  int numVerticies;
private:
  TextureData texture;
  //GLuint vbo;
};

#endif // TILEMAPASSET_H_INCLUDED
