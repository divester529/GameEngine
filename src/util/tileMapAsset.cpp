#include "TileMapAsset.hpp"

TileMapAsset::TileMapAsset(std::string key, int width, int height, Tileset* ts)
{
  GLfloat meshCoord[width*height*18];
  GLfloat texCoord[width*height*12];

  numVerticies=width*height*6;

  for(int i=0; i < height; i++)
  {
    for(int j=0; j < width; j++)
    {
      meshCoord[18*(j+i*width)]=(float)j*32.0f;
      texCoord[12*(j+i*width)]=0.0f;
      meshCoord[18*(j+i*width)+1]=(float)i*32.0f;
      texCoord[12*(j+i*width)+1]=0.0f;
      meshCoord[18*(j+i*width)+2]=0;

      meshCoord[18*(j+i*width)+3]=(float)j*32.0f;
      texCoord[12*(j+i*width)+2]=0.0f;
      meshCoord[18*(j+i*width)+4]=(float)(i+1)*32.0f;
      texCoord[12*(j+i*width)+3]=1.0f;
      meshCoord[18*(j+i*width)+5]=0;

      meshCoord[18*(j+i*width)+6]=(float)(j+1)*32.0f;
      texCoord[12*(j+i*width)+4]=1.0f;
      meshCoord[18*(j+i*width)+7]=(float)i*32.0f;
      texCoord[12*(j+i*width)+5]=0.0f;
      meshCoord[18*(j+i*width)+8]=0;

      meshCoord[18*(j+i*width)+9]=(float)(j+1)*32.0f;
      texCoord[12*(j+i*width)+6]=1.0f;
      meshCoord[18*(j+i*width)+10]=(float)i*32.0f;
      texCoord[12*(j+i*width)+7]=0.0f;
      meshCoord[18*(j+i*width)+11]=0;

      meshCoord[18*(j+i*width)+12]=(float)j*32.0f;
      texCoord[12*(j+i*width)+8]=0.0f;
      meshCoord[18*(j+i*width)+13]=(float)(i+1)*32.0f;
      texCoord[12*(j+i*width)+9]=1.0f;
      meshCoord[18*(j+i*width)+14]=0;

      meshCoord[18*(j+i*width)+15]=(float)(j+1)*32.0f;
      texCoord[12*(j+i*width)+10]=1.0f;
      meshCoord[18*(j+i*width)+16]=(float)(i+1)*32.0f;
      texCoord[12*(j+i*width)+11]=1.0f;
      meshCoord[18*(j+i*width)+17]=0;
    }
  }

  GLuint vbo;
  GLuint texCoordLoc;

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(meshCoord), meshCoord, GL_STATIC_DRAW);

  glGenBuffers(1, &texCoordLoc);
  glBindBuffer(GL_ARRAY_BUFFER, texCoordLoc);
  glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, texCoordLoc);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
}
