#ifndef TEXTURELOADER_H_INCLUDED
#define TEXTURELOADER_H_INCLUDED
#include <GL/GLew.h>
#include <GL/GL.h>
#include <string>

struct TextureData{
    TextureData(){}
    TextureData(GLuint _id, int _width, int _height){
      id=_id;
      width=_width;
      height=_height;
    }

    GLuint id;
    int width, height;
};

TextureData loadBitmap(std::string path);

#endif // TEXTURELOADER_H_INCLUDED
