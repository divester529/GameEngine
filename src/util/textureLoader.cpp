#include "textureLoader.hpp"
#include <fstream>
#include <stdio.h>

TextureData loadBitmap(std::string path)
{
  FILE* bmpFile = fopen(path.c_str(), "r");

  unsigned char header[54];

  if(bmpFile==0)
  {
      printf("Could not load file\n");

  }

  fread(header, 1, sizeof(header), bmpFile);

  if(header[0]!='B' & header[1]!= 'M')
  {
      printf("File %s is an invalid bitmap image!", path.c_str());

  }

  printf("still not crashed\n");

  int dataPos=*(int*)&(header[0x0A]);
  int imageSize=*(int*)&(header[0x22]);
  int width=*(int*)&(header[0x12]);
  int height=*(int*)&(header[0x16]);

  if(dataPos==0)
      dataPos=54;

  if(imageSize==0)
      imageSize=width*height*3;

  unsigned char* tempData = new unsigned char[imageSize];

  unsigned char* data = new unsigned char[imageSize];

  fseek(bmpFile, dataPos, SEEK_SET);

  fread(tempData, 1, imageSize, bmpFile);

  GLuint id;

  glGenTextures(1, &id);

  glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, id);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempData);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  fclose(bmpFile);

  TextureData texData(id, width, height);

  return texData;
}
